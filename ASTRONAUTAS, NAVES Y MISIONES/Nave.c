#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Nave.h"

#define CANT_MAX 30
#define nomArch "Naves.bin"

///---------------------------------------------------FUNCIONES DE CARGADO DE DATOS-------------------------------------------///
Nave datosNaves()
{
    Nave naveEjemplo;
    int select = 0;
    int ID = 0;
    int flag = 0;
    char seguir = 's';
    char continuar = 's';

    imprimirCabecera("                 [ DATOS DE LA NAVE ]");
    printf("\n\n\t\t\t\t\t\t\t                   [ID]: ");
    while(flag == 0)
    {
        scanf("%d", &ID);
        flag = verificarID(ID); // verifico si ya existe una nave con ese ID.
    }
    naveEjemplo.ID = ID;

    printf("\n\n");
    do
    {
        imprimirCabecera("               [ TIPOS DE NAVE ]");
        printf("\n\n");
        printf("\n\n\t\t\t\t\t\t\t             1.    [ 'Starship' ]");
        printf("\n\n\t\t\t\t\t\t\t             2.    [ 'Falcon 9' ]");
        printf("\n\n\t\t\t\t\t\t\t             3.    [ 'Falcon Heavy' ]");

        select=ingresarOpcion();

        switch(select)
        {
        case 1:
        {
            strcpy(naveEjemplo.tipoNave, "Starship");
            seguir = 'n';
            break;
        }
        case 2:
        {
            strcpy(naveEjemplo.tipoNave, "Falcon 9");
            seguir = 'n';
            break;
        }
        case 3:
        {
            strcpy(naveEjemplo.tipoNave, "Falcon Heavy");
            seguir = 'n';
            break;
        }
        default:
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t\t [ Opcion incorrecta ] \n\n\t\t\t\t\t\t\t\t\t\t [ Por favor ingrese una de las opciones validas ]: \n");
            break;
            system("pause");
        }
        }
    }
    while(seguir == 's');

    naveEjemplo.cantVuelos=0;
    naveEjemplo.horasVuelo=0;
    /*
    do
    {

        printf("\n\t[Estado]: \n\t\t0 = Mantenimiento. \n\t\t1 = Lista para su uso. \n\t\t2 = Actualmente en mision. \n\t\t3 = De baja. \n");
        printf("\t\t");
        scanf("%d", &select);
        switch(select)
        {
        case 0:
        {
            strcpy(naveEjemplo.estado, "Mantenimiento");
            continuar = 'n';
            break;
        }
        case 1:
        {
            strcpy(naveEjemplo.estado, "Lista para su uso");
            continuar = 'n';
            break;
        }
        case 2:
        {
            strcpy(naveEjemplo.estado, "Actualmente en mision");
            continuar = 'n';
            break;
        }
        case 3:
        {
            strcpy(naveEjemplo.estado, "De baja");
            continuar = 'n';
            break;
        }
        default:
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t\t [ Opcion incorrecta ] \n\n\t\t\t\t\t\t\t\t\t\t [ Por favor ingrese una de las opciones validas ]: \n");
            break;
            system("pause");
        }
        }
    }
    while(continuar == 's');
    */


    strcpy(naveEjemplo.estado, "Lista para su uso");

    return naveEjemplo;
}//----------------------------------la paso al archivo-----------------------------//
void pasarUnaSolaNave(Nave nueva)
{
    FILE* fp = fopen(nomArch, "ab");
    if(fp != NULL)
    {
        fwrite(&nueva, sizeof(Nave), 1, fp);
        fclose(fp);
    }
}
//--------------------------------------------------------VERIFICO SI YA SE CARGO ESE ID-----------------------------------------------------------//
int verificarID(int ID)
{
    int flag = -1;
    Nave naveArch;
    FILE* fp = fopen(nomArch, "rb");
    if(fp != NULL)
    {
        while(fread(&naveArch, sizeof(Nave), 1, fp) > 0)
        {
            if(naveArch.ID == ID)
            {
                printf("\n\n\t\t\t\t\t\t\t\t [ Ya hay cargada una nave con el ID '%d' ] \n\n\n\t\t\t\t\t\t\t\t [ Por favor ingrese otro ]: ", ID);
                flag = 0;
            }
        }
        fclose(fp);
    }
    return flag;
}
///---------------------------------------------------DAR DE ALTA UNA NAVE (case 1)-----------------------------------------------------------///
void altaNave(int IDnave)
{
    int flag = 0;
    Nave naveArch;
    FILE* fp = fopen(nomArch, "r+b");
    if(fp != NULL)
    {
        while(flag == 0 && fread(&naveArch, sizeof(Nave), 1, fp) > 0)
        {
            if(naveArch.ID == IDnave)
            {
                if(strcmp(naveArch.estado, "Lista para su uso") != 0)
                {
                    strcpy(naveArch.estado, "Lista para su uso");
                    fseek(fp, sizeof(Nave)*-1, SEEK_CUR);
                    fwrite(&naveArch, sizeof(Nave), 1, fp);
                    printf("\n\n\t\t\t\t\t\t\t\t\t\t [ Nave con ID '%d' dada de alta correctamente ]\n", IDnave);
                    flag = 1;
                }
                else
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t\t [ Esa nave ya esta dada de alta y lista para su uso ]\n\n");
                }
            }
        }
        fclose(fp);
    }
}
///---------------------------------------------------DAR DE BAJA UNA NAVE (case 2)-----------------------------------------------------------///
void bajaNave(int ID)
{
    int flag = 0;
    Nave naveArch;
    FILE* fp = fopen(nomArch, "r+b");
    if(fp != NULL)
    {
        while(flag == 0 && fread(&naveArch, sizeof(Nave), 1, fp) > 0)
        {
            if(naveArch.ID == ID)
            {
                if(strcmp(naveArch.estado, "De baja") != 0)
                {
                    strcpy(naveArch.estado, "De baja");
                    fseek(fp, sizeof(Nave)*-1, SEEK_CUR);
                    fwrite(&naveArch, sizeof(Nave), 1, fp);
                    printf("\n\n\t\t\t\t\t\t\t\t\t\t [Nave con ID '%d' dada de baja correctamente]\n", ID);
                    flag = 1;
                }
                else
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t\t [ Esa nave ya esta dada de baja ] \n");
                }
            }
        }
        fclose(fp);
    }
}///---------------------------------------------------MOSTRAR LAS NAVES (case 5)-----------------------------------------------------------///
void mostrarNaves(Nave naveEjemplo)
{
    int i=0;
    printf("\n");
    printf("\t\t\t\t\t\t\t%c", 201);
    for(i= 0; i<53; i++)
    {
        printf ("%c", 205);
    }
    printf("%c\n", 187);
    printf("\t\t\t\t\t\t\t             [ ID ]                | %d \n", naveEjemplo.ID);
    printf("\t\t\t\t\t\t\t        [ Tipo de nave ]           | %s \n", naveEjemplo.tipoNave);
    printf("\t\t\t\t\t\t\t[ Cantidad de vuelos realizados ]  | %d \n", naveEjemplo.cantVuelos);
    printf("\t\t\t\t\t\t\t  [ Horas de vuelo acumuladas ]    | %d \n", naveEjemplo.horasVuelo);
    printf("\t\t\t\t\t\t\t           [ Estado ]              | %s \n", naveEjemplo.estado);
    printf("\t\t\t\t\t\t\t%c", 200);
    for(i=0; i<53; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 188);
}


void mostrarArchivo()
{
    Nave naveArch;
    FILE* fp = fopen(nomArch, "rb");
    if(fp != NULL)
    {
        while(fread(&naveArch, sizeof(Nave), 1, fp) > 0)
        {
            mostrarNaves(naveArch);
        }
        fclose(fp);
    }
    else
    {
        imprimirCabecera("            ARCHIVO VACIO");
    }
}
///-----------------------------------------------------------BUSCAR POR ID (case 4)-----------------------------------------------------------///
void verArchivo(int ID)
{
    Nave nave1;
    int flag = -1;
    FILE* fp = fopen(nomArch, "rb");
    if(fp != NULL)
    {
        while(flag == -1 && fread(&nave1, sizeof(Nave), 1, fp) > 0)
        {
            if(nave1.ID == ID)
            {
                mostrarNaves(nave1);
                flag = 0;
            }
        }
        fclose(fp);
    }
    if(flag == -1)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t\t [ No existe una nave con ese ID registrada ]\n\n");
    }
}
///-----------------------------------------------------------CARGAR NAVES (case 6)-----------------------------------------------------------///
void cargarVariasNaves()
{
    Nave aux;
    char control = 's';
    while(control == 's')
    {
        printf("\n");
        aux = datosNaves();
        pasarUnaSolaNave(aux);
        printf("\n");


        printf("\n\n\t\t\t\t\t\t\t\t [ Desea seguir cargando? s/n ] : ");
        fflush(stdin);
        scanf("%c", &control);
    }
}
///-----------------------------------------------------------MODIFICAR NAVES (case 3)-----------------------------------------------------------///
void modificarNave()
{
    int select = 0;
    int i = 0;
    int flag = -1;
    Nave naveArch;
    FILE* fp = fopen(nomArch, "r+b");
    if(fp != NULL)
    {
        printf("\n\n\n");
        imprimirCabecera("         [ ELEGIR NAVE PARA SU MODIFICACION ]");
        while(fread(&naveArch, sizeof(Nave), 1, fp) > 0)
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t\t[OPCION %d]", i);
            mostrarNaves(naveArch);
            i++;
        }
        while(flag == -1)
        {
            select=ingresarOpcion();

            if(select < i)
            {
                flag = 0;
                elegirQueModificar(select);
            }
            else
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t\t[ Opcion no valida, ingrese otra ]\n");
            }
        }
        fclose(fp);
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t\t[ No hay cargada ninguna nave ]\n\n");
    }

}//------------------------------------------------------PREGUNTO QUE DATO DESEA MODIFICAR---------------------------------------------------------//
void elegirQueModificar(int i)
{
    int select = 0;
    char seguir = 's';

    system("cls");
    do
    {
        imprimirCabecera("                [ MENU MODIFICACIONES ]");
        printf("\n\n\t\t\t\t\t\t\t          1.    [ Modificar ID ]\n");
        printf("\n\n\t\t\t\t\t\t\t          2.    [ Modificar horas de vuelo ] \n");
        printf("\n\n\t\t\t\t\t\t\t          3.    [ Modificar cantidad de vuelos realizados ] \n");
       /* printf("\n\n\t\t\t\t\t\t\t          4.    [ Modificar estado de la nave ] \n");*/
        printf("\n\n\t\t\t\t\t\t\t          0.    [ Salir ]\n");

        select=IngresarID();

        switch(select)
        {
        case 1:
        {
            modificarIDnave(i);
            break;
        }
        case 2:
        {
            modificarHsVuelo(i);
            break;
        }
        case 3:
        {
            modificarCantVuelos(i);
            break;
        }
        /*
        case 4:
        {
            modificarEstado(i);
            break;
        }
        */
        case 0:
        {
            seguir = 'n';
            break;
        }
        default:
        {
            printf("\n(Opcion incorrecta)\n");
            break;
        }
        }
        system("pause");
        system("cls");
    }
    while(seguir == 's');
}//------------------------------------------------------MODIFICA EL ID DE LA NAVE-----------------------------------------------------------//
void modificarIDnave(int i)
{
    Nave naveArch;
    int IDnuevo = 0;
    int flag = 0;
    FILE* fp = fopen(nomArch, "r+b");
    if(fp != NULL)
    {
        fseek(fp, sizeof(Nave)*i, SEEK_SET);
        fread(&naveArch, sizeof(Nave), 1, fp);
        printf("\n[ID anterior]: %d \n[Ingrese nuevo ID]: ", naveArch.ID);
        while(flag == 0)
        {
            scanf("%d", &IDnuevo);
            flag = verificarID(IDnuevo);
        }

        naveArch.ID = IDnuevo;
        fseek(fp, sizeof(Nave)*-1, SEEK_CUR);
        fwrite(&naveArch, sizeof(Nave), 1, fp);

        fclose(fp);
    }
    printf("\n(ID modificado correctamente!!!)\n\n");
}//------------------------------------------------------MODIFICA HORAS DE VUELO-----------------------------------------------------------//
void modificarHsVuelo(int i)
{
    Nave naveArch;
    int horasVuelo = 0;
    FILE* fp = fopen(nomArch, "r+b");
    if(fp != NULL)
    {
        fseek(fp, sizeof(Nave)*i, SEEK_SET);
        fread(&naveArch, sizeof(Nave), 1, fp);
        printf("\n[Horas de vuelo anteriores]: %d \n[Horas de vuelo actualizadas]: ", naveArch.horasVuelo);
        scanf("%d", &horasVuelo);

        naveArch.horasVuelo = horasVuelo;
        fseek(fp, sizeof(Nave)*-1, SEEK_CUR);
        fwrite(&naveArch, sizeof(Nave), 1, fp);

        fclose(fp);
    }
    printf("\n(Horas de vuelo actualizadas correctamente!!!)\n\n");
}//------------------------------------------------------MODIFICA CANT DE VUELOS-----------------------------------------------------------//
void modificarCantVuelos(int i)
{
    Nave naveArch;
    int cantVuelos = 0;
    FILE* fp = fopen(nomArch, "r+b");
    if(fp != NULL)
    {
        fseek(fp, sizeof(Nave)*i, SEEK_SET);
        fread(&naveArch, sizeof(Nave), 1, fp);
        printf("\n[Cantidad de vuelos anteriores]: %d \n[Cantidad de vuelos actualizados]: ", naveArch.cantVuelos);
        scanf("%d", &cantVuelos);

        naveArch.cantVuelos = cantVuelos;
        fseek(fp, sizeof(Nave)*-1, SEEK_CUR);
        fwrite(&naveArch, sizeof(Nave), 1, fp);

        fclose(fp);
    }
    printf("\n(Cantidad de vuelos actualizados correctamente!!!)\n\n");
}//------------------------------------------------------MODIFICA EL ESTADO A SU GUSTO-----------------------------------------------------------//
void modificarEstado(int i)
{
    Nave naveArch;
    char estadoNuevo[30];
    FILE* fp = fopen(nomArch, "r+b");
    if(fp != NULL)
    {
        fseek(fp, sizeof(Nave)*i, SEEK_SET);
        fread(&naveArch, sizeof(Nave), 1, fp);
        printf("\n[Estado anterior]: %s \n[Estado actualizado]: ", naveArch.estado);
        fflush(stdin);
        gets(estadoNuevo);

        strcpy(naveArch.estado, estadoNuevo);
        fseek(fp, sizeof(Nave)*-1, SEEK_CUR);
        fwrite(&naveArch, sizeof(Nave), 1, fp);

        fclose(fp);
    }
    printf("\n(Estado actualizado correctamente!!!)\n\n");
}



int MuestraIdNave()
{
    Nave aux;

    int flag=0;
    FILE *pArch=fopen(nomArch, "r+b");
    if(pArch!=NULL)
    {
        printf("\n\n\n");
        while(fread(&aux,sizeof(Nave),1,pArch) > 0)
        {
            flag=1;
            printf("\n                                                                          [ ID %d - %s ] ",aux.ID, aux.tipoNave);
        }
        printf("\n\n\n");
        fclose(pArch);
    }
    return flag;
}

