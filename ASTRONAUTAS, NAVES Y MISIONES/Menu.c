#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "Astronauta.h"

#define ESC 27


///**************************************************************************************///
///           [ FUNCIONES QUE MUESTRAN LOS DATOS EN CABECERAS O SIN CABECERAS  ]
///         Tipo de muestras: Astronautas, Naves, Misiones, Menu Principal, Encabezados
///**************************************************************************************///

void imprimirAstronautaEnCabecera(Astronauta X)
{
    int i;
    printf ("\t\t\t\t\t\t\t%c", 201);
    for(i= 0; i<52; i++)
    {
        printf ("%c", 205);
    }
    printf("%c\n", 187);
    printf("\t\t\t\t\t\t\t  [ID]                    |   %d \n", X.Id);
    printf("\t\t\t\t\t\t\t  [Nombre]                |   %s \n",X.Nombre);
    printf("\t\t\t\t\t\t\t  [Apellido]              |   %s \n",X.Apellido);
    printf("\t\t\t\t\t\t\t  [Apodo]                 |   %s \n",X.Apodo);
    printf("\t\t\t\t\t\t\t  [Edad]                  |   %d \n",X.Edad);
    printf("\t\t\t\t\t\t\t  [Nacionalidad]          |   %s \n",X.Nacionalidad);
    printf("\t\t\t\t\t\t\t  [Especialidad]          |   %s \n",X.Especialidad);
    printf("\t\t\t\t\t\t\t  [Estado]                |   %s \n",X.Estado);
    printf("\t\t\t\t\t\t\t%c",206);
    for(i=0; i<52; i++)
    {
        printf("%c",205);
    }
    printf("%c\n",206);
    printf("\t\t\t\t\t\t\t  [Misiones Realizadas]   |   %d \n",X.MisionesEspacialesRealizadas);
    printf("\t\t\t\t\t\t\t  [Horas En La EEI]       |   %d \n",X.HorasEnLaEstacionEspacial);
    printf("\t\t\t\t\t\t\t  [Horas De Vuelo]        |   %d \n",X.HorasDeVueloAcumuladas);

    printf("\t\t\t\t\t\t\t%c", 200);
    for(i=0; i<52; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 188);
    printf("\n\n");
}



void imprimirMenuModificacionesAstronauta()
{
    int i;
    printf ("\t\t\t\t\t\t\t%c", 201);
    for(i= 0; i<52; i++)
    {
        printf ("%c", 205);
    }
    printf("%c\n", 187);

    printf("\n\n\t\t\t\t\t\t\t             1.    [ NOMBRE ] \n");
    printf("\n\n\t\t\t\t\t\t\t             2.    [ APELLIDO ] \n");
    printf("\n\n\t\t\t\t\t\t\t             3.    [ APODO ] \n");
    printf("\n\n\t\t\t\t\t\t\t             4.    [ EDAD ] \n");
    printf("\n\n\t\t\t\t\t\t\t             5.    [ NACIONALIDAD ]  \n");
    printf("\n\n\t\t\t\t\t\t\t             6.    [ ESPECIALIDAD ] \n");
    printf("\n\n\t\t\t\t\t\t\t             7.    [ ESTADO ] \n");
    printf("\n\n\t\t\t\t\t\t\t             0.    [ SALIR ] \n");


    printf("\t\t\t\t\t\t\t%c", 200);
    for(i=0; i<52; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 188);
    printf("\n\n");
}



void imprimirCabecera(char cabecera[])
{
    int i;
    printf ("\t\t\t\t\t\t\t%c", 201);
    for(i= 0; i<53; i++)
    {
        printf ("%c", 205);
    }
    printf("%c\n", 187);
    printf("\t\t\t\t\t\t\t%32s\n",cabecera);
    printf("\t\t\t\t\t\t\t%c", 200);
    for(i=0; i<53; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 188);
}



void imprimirOpcionesMenu()
{
    printf ("\n\n\n\n");
    imprimirCabecera("                   [ MENU PRINCIPAL ]");
    printf ("\n\n");

    printf ("\n\n\t\t\t\t\t\t\t             1.    [ ASTRONAUTAS ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             2.    [ NAVES ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             3.    [ MISIONES ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             0.    [ Salir ] \n\n");
}

void imprimirOpcionesMenuNave()
{

    printf ("\n\n\n\n");
    imprimirCabecera("                   [ MENU NAVES ]");
    printf ("\n\n");

    printf ("\n\n\t\t\t\t\t\t\t             1.    [ DAR DE ALTA UNA NAVE ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             2.    [ DAR DE BAJA UNA NAVE ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             3.    [ MODIFICAR UNA NAVE ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             4.    [ CONSULTAR POR ID ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             5.    [ LISTADO DE NAVES ]\n");
    printf ("\n\n\t\t\t\t\t\t\t             6.    [ CARGAR UNA NAVE NUEVA ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             0.    [ Salir ]\n\n");
}


void imprimirOpcionesMenuAstronautas()
{
    printf ("\n\n\n\n");
    imprimirCabecera("                   [MENU ASTRONAUTAS]");
    printf ("\n\n");
    printf ("\n\n\t\t\t\t\t\t\t             1.    [ DAR DE ALTA UN ASTRONAUTA ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             2.    [ DAR DE BAJA UN ASTRONAUTA ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             3.    [ MODIFICAR UN ASTRONAUTA ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             4.    [ CONSULTAR POR ID ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             5.    [ LISTADO DE ASTRONAUTAS ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             6.    [ CARGA NUEVOS ASTRONAUTAS ] \n");

    printf ("\n\n\t\t\t\t\t\t\t             0.    [ Salir ] \n\n");
}

void imprimirMenuMisiones()
{
    printf ("\n\n\n\n");
    imprimirCabecera("                   [MENU MISIONES]");
    printf ("\n\n");
    printf ("\n\n\t\t\t\t\t\t\t             1.    [ VERIFICAR ALTA ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             2.    [ DAR DE BAJA UNA MISION ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             3.    [ BUSCAR POR ID ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             4.    [ MODIFICAR MISION ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             5.    [ LANZAR/RETORNAR MISION ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             6.    [ MOSTRAR LISTADO DE MISIONES ]\n");
    printf ("\n\n\t\t\t\t\t\t\t             7.    [ CARGAR UNA MISION NUEVA ] \n");
    printf ("\n\n\t\t\t\t\t\t\t             0.    [ SALIR ]\n\n");
}





///*************************************************************************************************************///
/// PARAMETROS: No tiene.
/// RETORNO: No tiene
/// FUNCION: MENU
///*************************************************************************************************************///

void Seguridad()
{
    int cont = 0;
    char contraseniaUser[30];
    char usuarioUser[30];
    int flag = 0;

    while(flag == 0)
    {
        flag = ingresarSistema(usuarioUser, contraseniaUser, &cont);
        if(flag == 0)
        {
            system("cls");
            printf("\n\n\n\n\t\t\t\t\t\t\t           [ Intentos hasta ahora %d de 3 ]\n", cont);
        }
        if(cont == 3)
        {
            return 0;
        }
    }
    system("cls");
}


int ingresarSistema(char usuarioUser[], char contraseniaUser[], int* cont)
{
    char contrasenia[30] = {"UTN"};
    char usuario[30] = {"Elon Musk"};
    int flag = 0;

    printf("\n\n\n");
    imprimirCabecera("                    [ SEGURIDAD ] ");
    printf("\n\n\n");

    int i;
    printf ("\t\t\t\t\t\t\t%c", 201);
    for(i= 0; i<53; i++)
    {
        printf ("%c", 205);
    }
    printf("%c\n", 187);

    printf("\n\t\t\t\t\t\t\t            [ USERNAME ] : Elon Musk");
    printf("\n\n\t\t\t\t\t\t\t");
    for(i= 0; i<53; i++)
    {
        printf ("%c", 205);
    }
    fflush(stdin);
    strcpy(usuarioUser,usuario);

    printf("\n\n\t\t\t\t\t\t\t            [ PASSWORD ]: ");

    fflush(stdin);
    gets(contraseniaUser);
    printf("\n");

    printf("\t\t\t\t\t\t\t%c", 200);
    for(i=0; i<53; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 188);
    printf("\n\n");

    if(strcmp(contrasenia, contraseniaUser) == 0 && strcmp(usuario, usuarioUser) == 0)
    {
        flag = 1;
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t\t    [ Nombre de usuario o contrasenia incorrectos. ] \n\n");
        (*cont)++;
    }

    system("pause");
    return flag;
}



///*************************************************************************************************************///
/// PARAMETROS: No tiene.
/// RETORNO: Una opcion ( digito tipo int ) que es mayor a 0
/// FUNCION: Ingresar una opcion ( digito int )  sin tener que repetir codigo y evita que los id sean negativos.
///*************************************************************************************************************///

int ingresarOpcion()
{
    int opcion;
    do
    {
        printf ("\n\n\n\n\t\t\t\t\t\t\t\t\t  [ Ingrese opcion ] : ");
        scanf("%i", &opcion);
        printf("\n\n\n\n");
    }
    while(opcion<0);

    return opcion;
}
///**************************************************************************************///
/// PARAMETROS: No tiene.
/// RETORNO: Un Id que es mayor a 0
/// FUNCION: Ingresar un ID sin tener que repetir codigo y evita que los id sean negativos.
///**************************************************************************************///

int IngresarID()
{
    int id;

    do
    {
        printf("\n\n\n\n\t\t\t\t\t\t\t\t\t  [ Ingresar ID ] : ");
        scanf("%d", &id);
        printf("\n\n\n\n");
    }
    while(id<0);

    return id;
}

