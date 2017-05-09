#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/**
*brief pide un valor al usuario y valida que un string sea solo de numeros
*param1 Mensaje a imprimir
* param2 variable que guarda string validado
* return 1 si es solo numeros, sino 0
**/

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


/**
*brief Pide un numero al usuario y lo guarda
*param1 Mensaje a imprimir
* param2 variable que guarda string
* return void
**/
void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    gets(input);
}// getString

/**
*brief Valida que un string sea solo numeros
* param1 variable que guarda string validado
* return 1 si es solo numeros, sino 0
**/
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

/**
*brief recibe un string y cuenta la cantidad de caracteres ingresados
* param1 string a calcular la cantidad de caracteres
*return cantidad de caracteres de string
**/
int contadorChar(char str[])
 {
     int aux;
     aux=strlen(str);
     return aux;
 }//contadorChar


void altaProgramador(Eprogramador programador[], int tam)
{
    printf("-----------AGREGAR PROGRAMADOR-----------\n");
    int i,flagEncontro=0;
    for(i=0; i<tam; i++)
    {
        if(programador[i].estado==0)
        {
            printf("ID: %d", i+1);
            programador[i].id=i+1;
            printf("\nNombre: ");
            fflush(stdin);
            gets(programador[i].nombre);
            fflush(stdin);
            while(stringLetras(programador[i].nombre)==0)
            {
                printf("\nEl nombre no acepta numeros ");
                printf("\nNombre: ");
                fflush(stdin);
                gets(programador[i].nombre);
            }
            fflush(stdin);
            printf("\nApellido: ");
            gets(programador[i].apellido);
            while(stringLetras(programador[i].apellido)==0)
            {
                printf("\nEl apellido no acepta numeros ");
                printf("\Apellido: ");
                fflush(stdin);
                gets(programador[i].apellido);
            }
            fflush(stdin);
            printf("Ingrese categoria del programador (0=Junior, 1=SemiSenior, 2=Senior): ");
            scanf("%d", &programador[i].IdCategoria);
            while(programador[i].IdCategoria<0 || programador[i].IdCategoria>2)
            {
                printf("Categoria invalida.\nIngrese la categoria: ");
                scanf("%d", &programador[i].IdCategoria);
            }
            programador[i].estado=1;
            flagEncontro=1;
            system("cls");
            printf("\n----------PROGRAMADOR AGREGADO EXITOSAMENTE!--------");
            printf("\nNOMBRE\t\tAPELLIDO\tCATEGORIA\n");
            printf("%s\t\t%s\t\t%d\n", programador[i].nombre,programador[i].apellido,programador[i].IdCategoria);
            break;

        }
    }
    if(flagEncontro==0)
        printf("No hay espacio disponible");
}//agregarPersona

void modificarProgramador(Eprogramador programador[], int tam)
{
    int flagEncontro=0, i, auxInt;
    char opcion;
    float auxFloat;
    char auxString[50];
    char respuesta;
            printf("Ingrese ID: ");
            scanf("%d", &auxInt);
            for(i=0; i<tam; i++)
            {
                if(programador[i].estado==1)
                {
                    if(auxInt == programador[i].id)
                    {
                        printf("\nNOMBRE\t\tAPELLIDO\tCATEGORIA\n");
                        printf("%s\t\t%s\t\t%d\n", programador[i].nombre,programador[i].apellido,programador[i].IdCategoria);
                        printf("\nIngrese el dato a modificar(1.Nombre\n2.Apellido): ");
                        scanf("%c",&opcion);
                    while(opcion<'1' || opcion>'2')
                    {
                        printf("Opcion invalida.\nSeleccione una opcion: ");
                        fflush(stdin);
                        scanf("%c",&opcion);
                    }
                        switch(opcion)
                        {
                        case '1':
                            printf("Ingrese el nombre: ");
                            fflush(stdin);
                            gets(auxString);
                            printf("Esta seguro de realizar la modificacion s/n: ");
                        respuesta = getche();
                        if(respuesta=='s')
                        {
                            strcpy(programador[i].nombre,auxString);
                            printf("\nmodificacion realizada");
                        }
                        else
                        {
                            printf("Accion cancelada por el usuario!!!");
                        }
                            break;
                        case '2':
                            printf("Ingrese el apellido: ");
                            fflush(stdin);
                            gets(auxString);
                            printf("Esta seguro de realizar la modificacion s/n: ");
                            fflush(stdin);
                        respuesta = getche();
                        if(respuesta=='s')
                        {
                            strcpy(programador[i].apellido,auxString);
                            printf("\nmodificacion realizada");
                        }
                        else
                        {
                            printf("Accion cancelada por el usuario!!!");
                        }
                            break;

                        }

                        flagEncontro=1;
                        break;
                    }
                }
            }
            if(flagEncontro==0)
            {
                printf("Dato inexistente");
            }

}


void bajaProgramador(Eprogramador programador[], int tam)
{
    printf("-----------BAJA PROGRAMADOR-----------\n");
    int i,flagEncontro=0,auxInt;
    char opcion;
    printf("Ingrese el ID del programador a borrar: ");
    scanf("%d", &auxInt);
    for(i=0; i<tam; i++)
    {
        if(auxInt==programador[i].id)
        {
            flagEncontro=1;
            printf("%s\t\t%s\t\t%d\n", programador[i].nombre,programador[i].apellido,programador[i].IdCategoria);
            printf("\nDesea eliminar este registro?(s/n)");
            scanf(" %c", &opcion);
            while(opcion!='n' && opcion!='s')
            {
                printf("Respuesta invalida. Desea eliminar este registro?(s/n)\n");
                scanf("%d", &opcion);
            }
            if(opcion=='n')
            {
                programador[i].estado=0;
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
        printf("No se encontro el ID ingresado");
}//

void asignarProgramador(Eprogramador programador[], Eproyecto proyecto[], int tamProy, int tamProg)
{
    int i,auxInt, auxInt2;
    Eprogramador auxProg;

    printf("\nID\t\tNOMBRE\n");

    for(i=0;i<tamProy;i++)
    {
        printf("%d\t%s\n", proyecto[i].IdProyecto, proyecto[i].nombre);
    }
    printf("Indique el ID del proyecto: ");
    scanf("%d", &auxInt);


    printf("\nNOMBRE\t\tAPELLIDO\tCATEGORIA\tID\n");
    for(i=0;i<tamProg;i++)
    {
        if(programador[i].estado==1)
        {
        printf("%s\t\t%s\t\t%d\t\t%d\n", programador[i].nombre,programador[i].apellido,programador[i].IdCategoria,programador[i].id);
        }

    }
    printf("\nIndique el id del programador: ");
    scanf("%d", &auxInt2);


    programador[auxInt2-1].IdProy.IdProyecto=auxInt;
}


void listaProgramador(Eprogramador programador[], int tam)
{
    printf("-----------LISTA POR ID-----------\n\n");
    int i,j;
    Eprogramador auxStruct;
    printf("ID\t\tNOMBRE\tAPELLIDO\tPROYECTOS\n");
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(programador[i].id<programador[j].id)
            {
                auxStruct = programador[i];
                programador[i] = programador[j];
                programador[j] = auxStruct;
            }
        }

    }

    for(i=0; i<tam; i++)
    {
        if(programador[i].estado==1)
                printf("%d\t\t%s\t%s\t%d\n", programador[i].id,programador[i].nombre,programador[i].apellido,programador[i].IdProy.IdProyecto);
    }
}// listaOrdenada

void listaProyecto(Eproyecto proyecto[], int tam)
{
    printf("-----------LISTA PROYECTOS-----------\n\n");
    int i,j;
    Eproyecto auxStruct;
    printf("ID\t\tNOMBRE\n");
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(proyecto[i].IdProyecto<proyecto[j].IdProyecto)
            {
                auxStruct = proyecto[i];
                proyecto[i] = proyecto[j];
                proyecto[j] = auxStruct;
            }
        }

    }
    for(i=0; i<tam; i++)
    {

                printf("%d\t\t%s\n", proyecto[i].IdProyecto,proyecto[i].nombre);
    }

}


/**
*brief inicializa los estados de todos los registros del array en 0
*param1 array de persona
* param2 cantidad de posiciones del array
* return void
**/
void inicEstado(Eprogramador programador[],  int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        programador[i].estado=0;
    }
}// inicEstado


 int stringLetras(char str[])
{
    int i =0;
    while(str[i]!='\0')
    {
        if((str[i]<'a' || str[i]>'z')&&(str[i]<'A' || str[i]>'A') && str[i]!=' ')
            return 0;
        i++;
    }
    return 1;
}


