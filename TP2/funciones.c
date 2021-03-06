#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int stringNumerico(char mensaje[], char input[])
{
    char aux[25];
    getString(mensaje, aux);
    if(esNumero(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}//stringNumerico

void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    gets(input);
}// getString


int esNumero(char str[])
{
    int i = 0;
    while(str[i]!='\0')
    {
        if(str[i]<'0' || str[i]>'9')
            return 0;
        i++;
    }
    return 1;
}// esNumero

int contadorChar(char str[])
 {
     int aux;
     aux=strlen(str);
     return aux;
 }//contadorChar


void agregarPersona(Epersona persona[], int tam)
{
    printf("-----------AGREGAR PERSONA-----------\n");
    int i,flagEncontro=0,j, menor18=0, entre18y35=0, mayor35, auxInt;
    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==0)
        {
            printf("\nNombre: ");
            fflush(stdin);
            gets(persona[i].nombre);
            while(stringLetras(persona[i].nombre)==0)
            {
                printf("\nEl nombre no acepta numeros ");
                printf("\nNombre: ");
                fflush(stdin);
                gets(persona[i].nombre);
            }

            fflush(stdin);
            while(stringNumerico("\nEdad: ", persona[i].edad)==0)
            {
                printf("\nEdad debe ser numerico! ");
            }
            auxInt=atoi(persona[i].edad);
            if(auxInt<18)
                menor18++;
            if(auxInt>18 && auxInt<35)
                entre18y35++;
            if(auxInt>35)
                mayor35++;

            printf("%d", menor18);

            fflush(stdin);
            while(stringNumerico("\nDNI: ", persona[i].dni)==0)
            {
            printf("\nDNI debe ser numerico ");
            }
            while(contadorChar(persona[i].dni)<7 || contadorChar(persona[i].dni)>8)
                   {
                       printf("\nCantidad de digitos invalida");
                        stringNumerico("\nDNI: ", persona[i].dni);
                   }

            persona[i].estado=1;
            flagEncontro=1;
            system("cls");
            printf("\n----------PERSONA AGREGADA EXITOSAMENTE!--------");
            printf("\nDNI\t\tNOMBRE\tEDAD\n");
            printf("%s\t%s\t%s\n", persona[i].dni,persona[i].nombre,persona[i].edad);
            break;

        }
    }
    if(flagEncontro==0)
        printf("No hay espacio disponible");
}//agregarPersona


void borrarPersona(Epersona persona[], int tam)
{
    printf("-----------BORRAR PERSONA-----------\n");
    int i,auxDNI,flagEncontro=0;
    char opcion;
    printf("Ingrese el DNI de la persona a borrar: ");
    scanf("%d", &auxDNI);
    for(i=0; i<tam; i++)
    {
        if(auxDNI==persona[i].dni)
        {
            flagEncontro=1;
            printf("%s\t%d\t%s", persona[i].nombre, persona[i].edad,persona[i].dni);
            printf("\nDesea eliminar este registro?(s/n)");
            scanf(" %c", &opcion);
            while(opcion!='n' && opcion!='s')
            {
                printf("Respuesta invalida. Desea eliminar este registro?(s/n)\n");
                scanf("%d", &opcion);
            }
            if(opcion=='n')
            {
                persona[i].estado=0;
                system("cls");
                printf("Registro borrado");
            }
            else
            {
                system("cls");
                printf("Operacion anulada por el usuario");
            }
        }
    }
    if(flagEncontro==0)
        printf("No se encontro el DNI ingresado");
}// borrarPersona


void listaOrdenada(Epersona persona[], int tam)
{
    printf("-----------LISTA POR NOMBRE-----------\n\n");
    int i,j;
    Epersona auxStruct;
    printf("DNI\t\tNOMBRE\tEDAD\n");
    for(i=0; i<tam; i++)
    {
        for(j=i+1; j<=tam; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre)<0)
            {
                auxStruct = persona[i];
                persona[i] = persona[j];
                persona[j] = auxStruct;
            }
        }
            if(persona[i].estado!=0)
                printf("%s\t%s\t%s\n", persona[i].dni,persona[i].nombre,persona[i].edad);
    }
}// listaOrdenada



void inicEstado(Epersona persona[],  int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        persona[i].estado=0;
    }
}// inicEstado


 int stringLetras(char str[])
{
    int i =0;
    while(str[i]!='\0')
    {
        if((str[i]<'a' || str[i]>'z')&&(str[i]<'A' || str[i]>'A'))
            return 0;
        i++;
    }
    return 1;
}

int unicCod(Epersona persona[], int tam)
{
    int i,j,retorno;
    for(i=0;i<tam;i++)
    {
        for(j=0;i==tam;j++)
        {
            if(strcmp(persona[i].dni,persona[j].dni)==0)
                retorno=0;
        }
    }
    return 1;
}

void graficoBarras(int param1, int param2, int param3)
{

}



