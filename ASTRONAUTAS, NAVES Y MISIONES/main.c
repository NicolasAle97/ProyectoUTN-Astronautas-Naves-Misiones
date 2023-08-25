#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Astronauta.h"
#include "Nave.h"
#include "Mision.h"
#include "Menu.h"

#define CANT_MAX 30
#define nomArch "Naves.bin"
#define nomArch2 "Mision.bin"

#define ESC 27


int main()
{
    int select = 0;
    char seguir = 's';
    int IDnave = 0;
    int id = 0;
    int cont = 0; // Contador para agregar naves.
    Nave naves[CANT_MAX];
    Astronauta aux;
    int flag=0;
    int idMision = 0;
    Mision auxMision;

    flag=Seguridad();
    if(flag==0)
    {

        do
        {

            imprimirOpcionesMenu();
            select=ingresarOpcion();
            char continuar='s';

            switch(select)
            {
            case 1:
            {
                do
                {
                    system("cls");
                    imprimirOpcionesMenuAstronautas();
                    select=ingresarOpcion();
                    system("cls");

                    switch(select)
                    {
                    case 1:
                    {

                        flag=MuestraOpcionesAstronautaDeBaja();
                        if(flag==1)
                        {
                            id=IngresarID();
                            if(verificarIDAstronauta(id)==0)
                            {
                                AltaAstronauta(id);
                            }
                        }
                        else
                        {
                            printf("\n\n\n");
                            imprimirCabecera("       No existe ningun Astronauta Desactivado");
                            printf("\n\n\n");
                        }
                        break;
                    }
                    case 2:
                    {
                        flag=MuestraOpcionesAstronautaDeAlta();
                        if(flag==1)
                        {
                            id=IngresarID();
                            if(verificarIDAstronauta(id)==0)
                            {
                                BajaAstronauta(id);
                            }
                        }
                        else
                        {
                            printf("\n\n\n");
                            imprimirCabecera("       No existe ningun Astronauta Activado");
                            printf("\n\n\n");
                        }
                        break;
                    }

                    case 3:
                    {
                        flag=MuestraOpcionesAstronauta();
                        if(flag==1)
                        {
                            id=IngresarID();
                            if(verificarIDAstronauta(id)==0)
                            {
                                ModificaArchivoDeAstronauta(id);
                            }
                        }
                        else
                        {
                            printf("\n\n\n");
                            imprimirCabecera("       No hay Astronautas Registrados");
                            printf("\n\n\n");
                        }
                        break;
                    }
                    case 4:
                    {
                        printf("\n\n\n");
                        imprimirCabecera("             LISTA DE ASTRONAUTAS POR ID");
                        printf("\n\n\n");
                        flag=MuestraAstronautaPorID(id);
                        if(flag==1)
                        {
                            id=IngresarID();
                            if(verificarIDAstronauta(id)==0)
                            {
                                aux=RetornaAstronautaPorSuID(id);
                                imprimirAstronautaEnCabecera(aux);
                            }
                        }
                        else
                        {
                            printf("\n\n\n");
                            imprimirCabecera("       No hay Astronautas Registrados");
                            printf("\n\n\n");
                        }
                        break;
                    }
                    case 5:
                    {

                        flag=MuestraOpcionesAstronauta();
                        if(flag==0)
                        {
                            printf("\n\n\n");
                            imprimirCabecera("       No hay Astronautas Registrados");
                            printf("\n\n\n");
                        }

                        break;
                    }

                    case 6:
                    {
                        CargaArchivoVariasVeces();
                        break;
                    }
                    case 0:
                    {
                        continuar='n';
                        break;
                    }
                    default:
                    {
                        printf("\nOpcion incorrecta. \n");
                        break;
                    }
                    }
                    system("pause");
                    system("cls");
                }
                while(continuar=='s');
                break;
            }
            case 2:
            {
                int select2 = 0;
                char continuar = 's';
                do
                {
                    system("cls");

                    imprimirOpcionesMenuNave();
                    select2=ingresarOpcion();
                    system("cls");

                    switch(select2)
                    {
                    case 1:
                    {
                        printf("\n\n\n");
                        imprimirCabecera("             [ MENU DE NAVES - ALTA NAVE ]");
                        mostrarArchivo();
                        printf("\n");
                        IDnave=IngresarID();
                        altaNave(IDnave);
                        verArchivo(IDnave);
                        break;
                    }
                    case 2:
                    {
                        printf("\n\n\n");
                        imprimirCabecera("             [ MENU DE NAVES - BAJA NAVE ]");
                        mostrarArchivo();
                        printf("\n");
                        IDnave=IngresarID();
                        bajaNave(IDnave);
                        verArchivo(IDnave);
                        break;
                    }
                    case 3:
                    {

                        modificarNave();
                        break;
                    }
                    case 4:
                    {
                        printf("\n\n\n");
                        imprimirCabecera("                  [ LISTA DE ID NAVES ]");

                        if(MuestraIdNave()==0)
                        {
                            imprimirCabecera("             ARCHIVO VACIO");
                        }
                        else
                        {
                            IDnave=IngresarID();
                            verArchivo(IDnave);
                        }
                        break;
                    }
                    case 5:
                    {
                        printf("\n\n\n");

                        imprimirCabecera("                  [ LISTA DE NAVES ]");

                        mostrarArchivo();
                        printf("\n");
                        break;
                    }
                    case 6:
                    {
                        cargarVariasNaves(&cont);
                        break;
                    }
                    case 0:
                    {
                        continuar = 'n';
                        break;
                    }
                    default:
                    {
                        printf("\n\n\n\n\t\t\t\t\t\t\t\t\t[ Opcion incorrecta ] \n");
                        break;
                    }
                    }
                    system("pause");
                    system("cls");
                }
                while(continuar == 's');
                break;
            }
            case 3:
            {
                char continuar ='s';
                int select3=0;

                do
                {
                    system("cls");
                    imprimirMenuMisiones();
                    select3=ingresarOpcion();
                    system("cls");

                    switch(select3)
                    {
                    case 1:
                    {
                        if(recorrerArchMision()==1)
                        {
                            imprimirCabecera("                   [VERIFICAR ALTA] ");
                            idMision=IngresarID();
                            flag = verificarIDMision(idMision);
                            if(flag == 1)
                            {
                                verificarAlta(idMision);
                            }
                            else
                            {
                                printf("\n\n\t\t\t\t\t\t\t             [ No hay mision registrada con esa ID ]\n\n");
                            }

                        }
                        break;
                    }
                    case 2:
                    {
                        if(recorrerArchMision()==1)
                        {
                            imprimirCabecera("                   [DAR DE BAJA UNA MISION] ");
                            elegirMision();
                        }
                        break;
                    }
                    case 3:
                    {
                        printf("\n\n\n");
                        imprimirCabecera("             [ LISTA DE MISIONES POR ID ]");
                        printf("\n");
                        flag=VerificaMisonesYmuestraID();
                        if(flag==1)
                        {
                            do
                            {
                                id=IngresarID();
                                if(verificarIDMision(id)==0)
                                {
                                    printf("\n\t\t\t\t\t\t\t             [ El ID %d No existe ]", id);
                                }
                            }
                            while(verificarIDMision(id)==0);
                            auxMision=RetornaMisionPorSuID(id);
                            mostrarMisiones(auxMision);
                        }
                        else
                        {
                            printf("\n\n\n");
                            imprimirCabecera("               [ No hay Misiones Registradas ]");
                            printf("\n\n\n");
                        }
                        system("pause");
                        break;

                    }
                    case 4:
                    {
                        ///FALTA ESCRIBIR ENCABEZADOS EN LIBREARIA MISIONES.H
                        flag=MuestraOpcionesMisiones();

                        if(flag==1)
                        {
                            do
                            {
                                id=IngresarID();
                                if(verificarIDMision(id)==0)
                                {
                                    printf("\n\n\t\t\t\t\t\t\t             [ El ID %d No existe ]", id);
                                }
                            }
                            while(verificarIDMision(id)==0);

                            ModificaArchivoDeMisiones(id);
                        }
                        else
                        {
                            printf("\n\n\n");
                            imprimirCabecera("                   [ No hay Misiones Registrados ]");
                            printf("\n\n\n");
                        }
                        system("pause");
                        break;
                    }
                    case 5:
                    {
                        do
                        {
                            if(recorrerArchMision()==1)
                            {
                                id=IngresarID();
                                if(verificarIDMision(id)== 1)
                                {
                                    lanzarMision(id);
                                }
                                else
                                {
                                    printf("\n\n\t\t\t\t\t\t\t             [ El ID %d No existe ]", id);
                                }
                            }
                        }
                        while(verificarIDMision(id)==0 && flag == 1);
                        break;
                    }
                    case 6:
                    {
                        printf("\n\n\n");
                        imprimirCabecera("                 [ LISTA DE MISIONES ]");
                        printf("\n\n");
                        recorrerArchMision();
                        break;
                    }
                    case 7:
                    {
                        printf("\n\n\n");
                        imprimirCabecera("             [ LISTA DE MISIONES POR ID ]");
                        printf("\n");
                        VerificaMisonesYmuestraID();
                        cargarMisiones();
                        break;
                    }
                    case 0:
                    {
                        continuar='n';
                        break;
                    }
                    default:
                    {
                        printf("\n\n\t\t\t\t\t\t\t [ Opcion incorrecta ]");
                        break;
                    }
                    }
                    system("pause");
                    system("cls");
                }
                while(continuar =='s');
                break;
            }
            case 0:
            {
                seguir='n';
                break;
            }
            default:
            {
                printf("\n\n\t\t\t\t\t\t\t [ Opcion incorrecta ]");
                break;
            }
            }
            system("cls");
        }
        while(seguir =='s');

        return 0;
    }
    else
    {
        return 0;
    }

}

