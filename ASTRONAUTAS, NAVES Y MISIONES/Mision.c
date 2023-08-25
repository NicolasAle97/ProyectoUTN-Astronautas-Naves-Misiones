#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Mision.h"
#include "Nave.h"
#include "Menu.h"
#include "Astronauta.h"

#define nomArch2 "Mision.bin"
#define nomArch "Naves.bin"
#define ArchivoAstronauta "AstronautasArch.dat"


#define ESC 27


Mision crearMision()
{
    Mision misionEjemplo;
    Mision aux;
    int ID = 0;
    char Destino[100];
    char continuar='s';
    int Tripulantes[30];
    int valido = 0;
    int flag3 = 0;
    int i = 0;

    ID=funcion01();
    misionEjemplo.ID=ID; // le pone ID la mision

    ID=funcion02(); // agrega el ID de la nave
    misionEjemplo.IDnave=ID;

    strcpy(&misionEjemplo.Estado, "Listo"); // le asigna directamente listo a la mision

    aux=funcionMenuDestino();
    strcpy(&misionEjemplo.Destino,aux.Destino); // agrega un destino a la mision

    printf("\n\t\n\n\t\t\t\t\t\t\t             [Cargamento]: ");
    fflush(stdin);
    gets(misionEjemplo.Cargamento); // agrega el cargamento a llevar

    printf("\n\t\n\n\t\t\t\t\t\t\t             [Tripulantes]:\n");

    while(continuar == 's')
    {
        ID=IngresarID();
        flag3 = verificarIDAstronauta(ID);
        if(flag3 == 0)
        {
            valido = verificarDistintosID(misionEjemplo.Tripulantes, ID, i);
            if(valido == 0)
            {
                misionEjemplo.Tripulantes[i] = ID;
                i++;
            }
        }
        printf("\n\t\n\n\t\t\t\t\t\t\t             [Desea cargar otro ID?] s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    misionEjemplo.cantTripulantes = i;

    system("pause");
    system("cls");
    printf("\n\t\n\n\t\t\t\t\t\t\t             [Detalle de la mision]: "); // detalle de la mision
    fflush(stdin);
    gets(misionEjemplo.DetalleDeLaMision);

    return misionEjemplo;
}

//--------------------------------------------------VERIFICAR ID DE LA MISION---------------------------------------------------------------//

int verificarIDMision(int IDmision)
{
    int flag = 0;
    Mision misionArch;
    FILE* fp2 = fopen(nomArch2, "rb");
    if(fp2 != NULL)
    {
        while(fread(&misionArch, sizeof(Mision), 1, fp2) > 0)
        {
            if(misionArch.ID == IDmision)
            {
                flag = 1;
            }
        }
        fclose(fp2);
    }
    return flag;
}




int funcion01()
{
    int ID = 0;
    do
    {
        ID=IngresarID();
        if(verificarIDMision(ID)==1)
        {
            printf("\n\n\t\t\t\t\t\t\t             [ El ID %d ya existe ]\n",ID);
        }
    }
    while(verificarIDMision(ID)==1);

    return ID;
}

//---------------------------------------------------VERIFICAR SI EXISTE NAVE CON ESE ID--------------------------------------------------------//
int verificarIDNave(int ID)
{
    int flag = 0;
    Nave naveArch;
    FILE* fp = fopen(nomArch, "rb");
    if(fp != NULL)
    {
        while(fread(&naveArch, sizeof(Nave), 1, fp) > 0)
        {
            if(naveArch.ID == ID)
            {
                flag = 1;
            }
        }
        fclose(fp);
    }
    return flag;
}




int funcion02()
{
    int ID = 0;
    do
    {
        printf("\n\t\t\t\t\t\t\t\t\t[ID de la Nave]: ");
        scanf("%d", &ID);
        if(verificarIDNave(ID)==0)
        {
            printf("\n\n\t\t\t\t\t\t\t             [ No existe la nave con el ID %d ] \n", ID);
            system("pause");
        }
    }
    while(verificarIDNave(ID)==0);
    return ID;
}

//-------------------------------------------------VERIFICAR SI EXISTE ASTRONAUTA CON ESE ID------------------------------------------------------//

int verificarIDAstronauta(int ID)
{
    int flag = -1;
    Astronauta astroArch;
    FILE* pArchAstronauta = fopen(ArchivoAstronauta, "rb");
    if(pArchAstronauta != NULL)
    {
        while(fread(&astroArch, sizeof(Astronauta), 1, pArchAstronauta) > 0)
        {
            if(astroArch.Id == ID)
            {
                flag = 0;
            }
        }
        fclose(pArchAstronauta);
    }
    if(flag == -1)
    {
        printf("\n\n\t\t\t\t\t\t\t            [ No hay astronautas con ese ID ]\n");
    }
    return flag;
}

//--------------------------------------------------VERIFICAR QUE NO INGRESA 2 VECES EL MISMO ID---------------------------------------------------//
int verificarDistintosID(int IDastronautas[], int ID, int validos)
{
    int flag = 0;
    int i = 0;
    for(i=0; i<validos; i++)
    {
        if(IDastronautas[i] == ID)
        {
            flag = -1;
        }
    }
    if(flag == -1)
    {
        printf("\n\n\t\t\t\t\t\t\t            [ Ese astronauta ya esta cargado en la mision ]\n");
    }
    return flag;
}

//----------------------------------------------------------------MENU DESTINOS -------------------------------------------------------------------//

Mision funcionMenuDestino()
{

    Mision Destino;
    int select;
    char seguir = 's';

    do
    {
        imprimirCabecera("              [ DESTINOS ] ");
        printf("\n\n\t\t\t\t\t                 1.                    'EEI'");
        printf("\n\n\t\t\t\t\t                 2.             'Orbita terrestre'");
        printf("\n\n\t\t\t\t\t                 3.                    'Luna'");
        printf("\n\n\t\t\t\t\t                 4.                    'Marte'");
        printf("\n\n\t\t\t\t\t                 5.       'Comprar medialunas de otro planeta'");

        select=ingresarOpcion();
        printf("\n\n");
        switch(select)
        {
        case 1:
        {
            strcpy(&Destino.Destino, "EEI");
            seguir = 'n';
            break;
        }
        case 2:
        {
            strcpy(&Destino.Destino, "Orbita terrestre");
            seguir = 'n';
            break;
        }
        case 3:
        {
            strcpy(&Destino.Destino, "Luna");
            seguir = 'n';
            break;
        }
        case 4:
        {
            strcpy(&Destino.Destino, "Marte");
            seguir = 'n';
            break;
        }
        case 5:
        {
            strcpy(&Destino.Destino, "Comprar medialunas de otro planeta");
            seguir = 'n';
            break;
        }
        default:
        {
            printf("\nOpcion incorrecta.\n");
            break;
        }
        }
        system("pause");
        system("cls");
    }
    while(seguir == 's');

    system("cls");
    printf("\n\n\t\t\t\t\t\t\t              [ DESTINO ACTUAL : %s ]",Destino.Destino);
    printf("\n\n\n");

    return Destino;
}
//----------------------------------------------------------------CARGAR MISIONES------------------------------------------------------------------//
void cargarMisiones()
{
    Mision aux;
    char seguir = 's';
    while(seguir == 's')
    {
        printf("\n\n");
        imprimirCabecera("                [CARGAR MISIONES]");
        printf("\n\n");

        aux = crearMision();
        pasarMisionArchivo(aux);

        printf("\n\n\t\t\t\t\t\t\t              [Desea cargar otra mision?] s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);
        system("cls");
    }
}
//----------------------------------------------------------------PASAR AL ARCHIVO-----------------------------------------------------------------//
void pasarMisionArchivo(Mision nueva)
{
    FILE* fp2 = fopen(nomArch2, "ab");
    if(fp2 != NULL)
    {
        fwrite(&nueva, sizeof(Mision), 1, fp2);
        fclose(fp2);
    }
    imprimirCabecera("             [ MISION CARGADA CON EXITO ] ");
    printf("\n\n");
}
///-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_VERIFICAR ALTA DE NAVE (case 1)_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-///

int verificarAlta(int id)
{
    int validarOK = 0;
    int flag = 0;
    int flag2 = 0;
    Mision misionArch;
    FILE* fp2 = fopen(nomArch2, "rb");
    if(fp2 != NULL)
    {
        while(fread(&misionArch, sizeof(Mision), 1, fp2) > 0)
        {
            if(misionArch.ID == id)
            {
                flag = verificarNaveLista(misionArch.IDnave);
                flag2 = verificarAstronautaListo(misionArch.Tripulantes, misionArch.cantTripulantes);
            }
        }
        fclose(fp2);
    }
    if(flag == 0)
    {
        printf("\n");
        printf("\n\t\t\t\t\t\t\t         [ La nave esta lista para el despegue ]\n\n");
    }
    else
    {
        printf("\n");
        printf("\n\t\t\t\t\t\t\t\t\t [ La nave aun no esta lista ]\n\n");
    }
    if(flag2 == 0)
    {
        printf("\n");
        printf("\n\t\t\t\t\t\t\t [ Todos los astronautas estan listos para el despegue ]\n\n");
    }
    if(flag == 0 && flag2 == 0)
    {
        validarOK = 1;
    }
    return validarOK;
}
int verificarNaveLista(int id)
{
    int flag = 0;
    Nave naveArch;
    FILE* fp = fopen(nomArch, "rb");
    if(fp != NULL)
    {
        while(fread(&naveArch, sizeof(Nave), 1, fp) > 0)
        {
            if(naveArch.ID == id)
            {
                if(strcmp(naveArch.estado, "Lista para su uso") != 0)
                {
                    flag = -1;
                }
            }
        }
        fclose(fp);
    }
    return flag;
}


int verificarAstronautaListo(int x[], int validos)
{
    int flag = 0;
    int flag2 = 0;
    int i=0;

    for(i=0; i<validos; i++)
    {
        flag = funcionAux(x[i]);
        if(flag == -1)
        {
            flag2 = -1;
        }
    }
    return flag2;
}



int funcionAux(int x)
{
    int flag = 0;
    Astronauta astroArch;
    FILE* pArchAstronauta = fopen (ArchivoAstronauta, "rb");
    if(pArchAstronauta != NULL)
    {
        while(fread(&astroArch, sizeof(Astronauta), 1, pArchAstronauta) > 0)
        {
            if(astroArch.Id == x)
            {
                if(strcmp(astroArch.Estado, "ACTIVADO") != 0)
                {
                    printf("\n\t\t\t\t\t\t\t\t [ El astronauta con ID '%d' no esta listo ]\n\n", x);
                    flag = -1;
                }
            }
        }
        fclose(pArchAstronauta);
    }
    return flag;
}


///-----------------------------------------------------------DAR DE BAJA UNA MISION (case 2)-----------------------------------------------------///


void elegirMision()
{
    int i = 0;
    int select = 0;
    int flag = 0;
    Mision misionArch;
    FILE* fp2 = fopen(nomArch2, "rb");
    if(fp2 != NULL)
    {
        printf("\n\n[ELIJA LA MISION QUE DESEA DAR DE BAJA]");
        while(fread(&misionArch, sizeof(Mision), 1, fp2) > 0)
        {
            printf("\n\n\t\t\t[ OPCION %d ]", i);
            mostrarMisiones(misionArch);
            i++;
        }
        while(flag == 0)
        {
            select=ingresarOpcion();

            if(select < i)
            {
                flag = 1;
                darBajaMision(select);
            }
            else
            {
                printf("\n\n\t\t\t\t\t\t\t [ Opcion no valida, ingrese otra]\n");
            }
        }
    }
    else
    {
        imprimirCabecera("                [ ARCHIVO VACIO ]");
        printf("\n\n\n");

    }
}


void darBajaMision(int select)
{
    Mision misionArch;
    FILE* fp2 = fopen(nomArch2, "r+b");
    if(fp2 != NULL)
    {
        fseek(fp2, sizeof(Mision)*select, SEEK_SET);
        fread(&misionArch, sizeof(Mision), 1, fp2);
        if(strcmp(misionArch.Estado, "Listo") == 0)
        {
            strcpy(misionArch.Estado, "Cancelada");
            fseek(fp2, sizeof(Mision)*-1, SEEK_CUR);
            fwrite(&misionArch, sizeof(Mision), 1, fp2);
            fclose(fp2);
            printf("\n\t\t\t\t\t\t\t\t[ MISION CANCELADA CON EXITO ]\n\n");
        }

        else
        {
            printf("\n\n\n\t\t\t\t\t\t\t       [ Esa mision no puede ser cancelada ]\n\n");
        }
        fclose(fp2);
    }
}



///---------------------------------------------------------LISTADO MISION------------------------------------------------------------------------///


void mostrarMisiones(Mision misionEjemplo)
{
    int i=0;
    printf("\n");
    printf("\t\t\t\t\t\t\t%c", 201);
    for(i= 0; i<50; i++)
    {
        printf ("%c", 205);
    }
    printf("%c", 187);
    printf("\n\t\t\t\t\t\t\t [ MISION : %s ] ", misionEjemplo.DetalleDeLaMision);
    ///Lo ideal es que cuando llegue a 30 letras haga un salto de linea...
    printf("\n\t\t\t\t\t\t\t ");
    for(i= 0; i<50; i++)
    {
        printf ("%c", 205);
    }
    printf("\n");
    printf("\t\t\t\t\t\t\t       [ID]                       | %d \n", misionEjemplo.ID);
    printf("\t\t\t\t\t\t\t  [ID de la Nave]                 | %d \n", misionEjemplo.IDnave);
    printf("\t\t\t\t\t\t\t     [Estado]                     | %s \n", misionEjemplo.Estado);
    printf("\t\t\t\t\t\t\t     [Destino]                    | %s \n", misionEjemplo.Destino);
    printf("\t\t\t\t\t\t\t   [Cargamentos]                  | %s \n", misionEjemplo.Cargamento);
    printf("\t\t\t\t\t\t\t [ID's Tripulantes]               | ");
    IDAstronauta(misionEjemplo.Tripulantes, misionEjemplo.cantTripulantes);
    printf("\n");
    printf("\t\t\t\t\t\t\t%c", 200);
    for(i=0; i<50; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 188);
    printf("\n\n\n");

}



int recorrerArchMision()
{
    int flag = 0;
    Mision misionArch;
    FILE* fp2 = fopen(nomArch2, "rb");
    if(fp2 != NULL)
    {
        flag = 1;
        while(fread(&misionArch, sizeof(Mision), 1, fp2) > 0)
        {
            mostrarMisiones(misionArch);
        }
        fclose(fp2);
    }
    else
    {
        imprimirCabecera("                [ ARCHIVO VACIO ]");
        printf("\n\n\n");

    }
    return flag;
}


void IDAstronauta(int x[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf(" [%i]", x[i]);
    }
}


//-------------------------------------------------------MUESTRA POR ID---------------------------------------------------------------------//

///**************************************************************************************///
/// PARAMETRO: Recibe ID
/// RETORNO: Mision buscada
/// FUNCION: Retorna una mision por su ID.
///**************************************************************************************///

Mision RetornaMisionPorSuID(int id)
{
    int flag = 0;

    Mision aux;

    FILE * pArchMision = fopen (nomArch2, "rb");

    if(pArchMision)
    {
        while(flag==0 && fread(&aux,sizeof(Mision),1,pArchMision)> 0)
        {
            if(aux.ID==id)
            {
                flag=1;
            }
        }
        fclose(pArchMision);
    }

    return aux;
}

///**************************************************************************************///
/// PARAMETRO: No tiene
/// RETORNO: Flag que dice si existen ID o no Existen ID.
/// FUNCION: Lo uso para validar la existencia de registros antes de que el usuario pueda Ingresar el ID.
///**************************************************************************************///


int VerificaMisonesYmuestraID()
{
    Mision aux;

    int flag=0;
    FILE *pArch=fopen(nomArch2, "r+b");
    if(pArch!=NULL)
    {
        printf("\n\n\n");
        while(fread(&aux,sizeof(Mision),1,pArch) > 0)
        {
            flag=1;
            printf("\n                                                                            [ ID %d ] ",aux.ID);
        }
        printf("\n\n\n");
        fclose(pArch);
    }
    return flag;
}

int MuestraOpcionesMisiones()
{
    FILE *pArchMisones=fopen(nomArch2,"r+b");
    Mision creada;

    int flag=0;
    if(pArchMisones!=NULL)
    {
        printf("\n\n\n");
        imprimirCabecera("\t          LISTA DE MISIONES");
        printf("\n\n\n");

        while(fread(&creada, sizeof(Mision), 1, pArchMisones) > 0)
        {
            mostrarMisiones(creada);
            flag=1;
            printf("\n");
        }
        fclose(pArchMisones);
    }
    return flag;
}



Mision ModificarMision(Mision creada)
{
    int opcion;
    int flag=0;
    int valido = 0;
    char control='s';
    int i=0;
    int ID = 0;
    Mision aux;

    printf("\n\n");

    imprimirCabecera("            MODIFICACION DE MISONES");
    printf("\n\n\n");
    printf("\n\n\t\t\t\t\t\t\t             1.            [ ID NAVE ] \n");
    printf("\n\n\t\t\t\t\t\t\t             2.            [ DESTINO ] \n");
    printf("\n\n\t\t\t\t\t\t\t             3.          [ CARGAMENTOS ] \n");
    printf("\n\n\t\t\t\t\t\t\t             4.          [ TRIPULANTES ] \n");
    printf("\n\n\t\t\t\t\t\t\t             5.     [ DETALLES DE LA MISION ] \n");
    printf("\n\n\n");
    printf("\n\n\t\t\t\t\t\t\t             0.              [ SALIR ] .\n");

    opcion=ingresarOpcion();
    printf("\n\n");

    switch(opcion)
    {
    case 1:
    {
        printf("\n\n\n\n");
        imprimirCabecera("                Modificar ID NAVE");
        printf("\n");
        printf("\n\t\t[ID Nave anterior]: %d.\n",creada.IDnave);
        printf("\n\tingrese el nuevo ID)*");
        ID=funcion02();
        creada.IDnave = ID;
        printf("\n\n\n\n");
        system("pause");
        system("cls");
        flag=1;
        break;
    }
    case 2:
    {
        printf("\n\n\n\n");
        imprimirCabecera("                Modificar DESTINO");
        printf("\n\n\t\t\t\t\t\t\t\t\t[DESTINO anterior]: %s .\n",creada.Destino);
        printf("\n");
        aux=funcionMenuDestino();
        strcpy(creada.Destino,aux.Destino);
        printf("\n\n\n\n");
        system("pause");
        flag=1;
        break;
    }
    case 3:
    {
        printf("\n\n\n\n");
        imprimirCabecera("                Modificar CARGAMENTO");
        printf("\n\n\n\n");
        printf("\n\t\t[CARGAMENTO anterior]: %s .\n",creada.Cargamento);
        printf("\n\t\t[Nuevo CARGAMENTO]: ");
        fflush(stdin);
        gets(&creada.Cargamento);
        printf("\n\n\n\n");
        system("cls");
        flag=1;
        break;
    }
    case 4:
    {
        printf("\n\n\n\n");
        imprimirCabecera("                Modificar TRIPULANTES");
        printf("\n\n\n\n");
        printf("\n\t\t[TRIPULANTES anteriores]: \n");

        for(int i=0; i<creada.cantTripulantes; i++)
        {
            printf("\n\t\t [ %d ] ", creada.Tripulantes[i]);
        }
        i=0;

        do
        {
            creada.Tripulantes[i]=0; // limpia todos los tripulantes para agregarlos todos de nuevo
            i++;
        }
        while(i<=creada.cantTripulantes);


        i=0;

        printf("\n\n\t\t[Nuevos TRIPULANTES] ");
        do
        {
            printf("\n\t(ingresar ID): ");
            scanf("\t%d", &ID);
            flag = verificarIDAstronauta(ID);
            if(flag == 0)
            {
                valido = verificarDistintosID(creada.Tripulantes, ID, i);
                if(valido == 0)
                {
                    creada.Tripulantes[i] = ID;
                    i++;
                }
            }
            printf("\n[Desea cargar otro ID?] s/n: ");
            fflush(stdin);
            scanf("%c", &control);
        }
        while(control == 's');

        creada.cantTripulantes=i;
        IDAstronauta(creada.Tripulantes,creada.cantTripulantes);
        printf("\n\n\n\n");
        system("pause");
        flag=1;
        break;
    }
    case 5:
    {
        printf("\n\n\n\n");
        imprimirCabecera("         Modificar DETALLES DE LA MISION");
        printf("\n\n\n\n");
        printf("\n\t\t[Detalles anteriores de la mision]: %s.\n",creada.DetalleDeLaMision);
        printf("\n\t\t[Nuevos DETALLES]: ");
        fflush(stdin);
        gets(&creada.DetalleDeLaMision);
        printf("\n\n\n\n");
        system("pause");
        flag=1;
        break;
    }
    default:
    {
        imprimirCabecera("              OPCION INCORRECTA");
        flag=0;
        break;
    }
    }

    if(flag==1)
    {
        printf("\n\n\n\n");
        imprimirCabecera("               MODIFICACION CON EXITO.");
        printf("\n\n\n\n");
    }
    else
    {
        printf("\n\n\n\n");
        imprimirCabecera("              SIN MODIFICACIONES REALIZADAS ");
        printf("\n\n\n\n");
    }

    return creada;
}


int ModificaArchivoDeMisiones(int id)
{
    FILE *pArchMisiones=fopen(nomArch2,"r+b");
    Mision creada;
    int flag=0;

    if(pArchMisiones!=NULL)
    {
        while(flag==0 && fread(&creada, sizeof(Mision),1,pArchMisiones) > 0)
        {
            if(creada.ID==id)
            {
                fseek(pArchMisiones,sizeof(Mision)*-1,SEEK_CUR);
                creada=ModificarMision(creada);
                fwrite(&creada,sizeof(Mision),1,pArchMisiones);
                flag=1;
            }
        }
        fclose(pArchMisiones);
    }
}
///--------------------------------------------------------------LANZAR MISION-------------------------------------------------------------------///
void lanzarMision(int ID)
{
    int cantHorasAcumuladas = 0;
    int horasEEI = 0;
    int flag = 0;
    int flag2 = 0;
    char control = 's';
    int option = 0;
    Mision misionArch;
    FILE* fp2 = fopen(nomArch2, "r+b");
    if(fp2 != NULL)
    {
        while(flag == 0 && fread(&misionArch, sizeof(Mision), 1, fp2) > 0)
        {
            if(misionArch.ID == ID)
            {
                if(strcmp(misionArch.Estado, "En vuelo") == 0)
                {
                    flag2 = 1;
                    flag = 1;
                    printf("\n\t\t\t\t\t\t\t\t[ LA MISION ESTA EN VUELO ] \n");

                    do
                    {
                        system("cls");
                        printf("\n\n");
                        imprimirCabecera("               DECICIONES SOBRE LA MISION");
                        printf("\n\n\t\t\t\t\t\t\t             1.    [ EN VUELO A RETORNADA ]\n");
                        printf("\n\n\t\t\t\t\t\t\t             2.    [ EN VUELO A FALLIDA ]\n");
                        printf("\n\n\t\t\t\t\t\t\t             0.    [ SALIR ]\n");

                        option=ingresarOpcion();

                        switch(option)
                        {
                        case 1:
                        {
                            strcpy(misionArch.Estado, "RETORNADA");
                            fseek(fp2, sizeof(Mision)*-1, SEEK_CUR);
                            fwrite(&misionArch, sizeof(Mision), 1, fp2);

                            if(strcmp(misionArch.Destino, "EEI") == 0)
                            {
                                printf("\n\n\t\t\t\t\t\t\t             [Tiempo que estuvieron en la EEI]: ");
                                horasEEI = horasVueloAcumuladas();
                            }
                            printf("\n\n\t\t\t\t\t\t\t             [ Cantidad horas de vuelo ] : ");
                            cantHorasAcumuladas = horasVueloAcumuladas();
                            retornarNave(misionArch.IDnave, "Lista para su uso", cantHorasAcumuladas);
                            retornarTripulantes(misionArch.Tripulantes, misionArch.cantTripulantes, cantHorasAcumuladas, horasEEI);
                            control = 'n';
                            fclose(fp2);
                            break;
                        }
                        case 2:
                        {
                            strcpy(misionArch.Estado, "FALLIDA");
                            fseek(fp2, sizeof(Mision)*-1, SEEK_CUR);
                            fwrite(&misionArch, sizeof(Mision), 1, fp2);

                            if(strcmp(misionArch.Destino, "EEI") == 0)
                            {
                                printf("\n\n\t\t\t\t\t\t\t             [ Tiempo que estuvieron en la EEI ] : ");
                                horasEEI = horasVueloAcumuladas();
                            }
                            printf("\n\n\t\t\t\t\t\t\t             [ Cantidad horas de vuelo ] : ");
                            cantHorasAcumuladas = horasVueloAcumuladas();
                            retornarNave(misionArch.IDnave, "Mantenimiento", cantHorasAcumuladas);
                            retornarTripulantes(misionArch.Tripulantes, misionArch.cantTripulantes, cantHorasAcumuladas, horasEEI);
                            control = 'n';
                            fclose(fp2);
                            break;
                        }
                        case 0:
                        {
                            control = 'n';
                            break;
                        }
                        default:
                        {
                            printf("\n\n\t\t\t\t\t\t\t            [ Opcion incorrecta ] \n");
                        }
                        }
                        system("pause");
                        system("cls");
                    }
                    while(control == 's');
                }
                if(verificarAlta(ID) == 1 && flag2 == 0)
                {
                    if(strcmp(misionArch.Estado, "Listo") == 0)
                    {
                        imprimirCabecera("                  [LA MISION ESTA LISTA] ");
                        printf("\n\n\t\t\t\t\t\t\t             [ Presione 'S' para confirmar lanzamiento de mision...... ]\n");
                        fflush(stdin);
                        scanf("%c", &control);
                        system("pause");
                        flag = 1;
                        if(control == 's')
                        {
                            strcpy(misionArch.Estado, "En vuelo");
                            fseek(fp2, sizeof(Mision)*-1, SEEK_CUR);
                            fwrite(&misionArch, sizeof(Mision), 1, fp2);

                            lanzarTripulante(misionArch.Tripulantes, misionArch.cantTripulantes);
                            lanzarNave(misionArch.IDnave);
                            fclose(fp2);
                        }
                        else
                        {
                            printf("\n\n\t\t\t\t\t\t\t             [ Usted decidio no lanzarla] \n");
                        }


                    }
                    else
                    {
                        printf("\n\n\t\t\t\t\t\t\t             [ LA MISION NO ESTA LISTA ]\n\n");
                    }
                }
            }
        }
    }
}
//-----------------------------------------------------------MODIFICO ESTADO TRIPULANTE-----------------------------------------------------------//
void lanzarTripulante(int x[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        lanzarTripulante2(x[i]);
    }
}
void lanzarTripulante2(int IDtripulante)
{
    int flag = 0;
    Astronauta astroArch;
    FILE* fp = fopen(ArchivoAstronauta, "r+b");
    if(fp != NULL)
    {
        while(flag == 0 && fread(&astroArch, sizeof(Astronauta), 1, fp) > 0)
        {
            if(astroArch.Id == IDtripulante)
            {
                strcpy(astroArch.Estado, "EN MISION");
                fseek(fp, sizeof(Astronauta)*-1, SEEK_CUR);
                fwrite(&astroArch, sizeof(Astronauta), 1, fp);
                flag = 1;
            }
        }
        fclose(fp);
    }
}
//-----------------------------------------------------------MODIFICO ESTADO NAVE-----------------------------------------------------------------//
void lanzarNave(int ID)
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
                strcpy(naveArch.estado, "Actualmente en mision");
                fseek(fp, sizeof(Nave)*-1, SEEK_CUR);
                fwrite(&naveArch, sizeof(Nave), 1, fp);
                flag = 1;
            }
        }
        fclose(fp);
    }
}
///----------------------------------------------------------RETORNADA o FALLIDA-----------------------------------------------------------///
void retornarTripulantes(int x[], int validos, int horas, int horasEEI)
{
    for(int i=0; i<validos; i++)
    {
        retornarTripulantes2(x[i], horas, horasEEI);
    }
}
void retornarTripulantes2(int IDtripulante[], int horas, int horasEEI)
{
    int flag = 0;
    Astronauta astroArch;
    FILE* fp = fopen(ArchivoAstronauta, "r+b");
    if(fp != NULL)
    {
        while(flag == 0 && fread(&astroArch, sizeof(Astronauta), 1, fp) > 0)
        {
            if(astroArch.Id == IDtripulante)
            {
                strcpy(astroArch.Estado, "ACTIVADO");
                astroArch.HorasDeVueloAcumuladas = astroArch.HorasDeVueloAcumuladas + horas;
                astroArch.HorasEnLaEstacionEspacial = astroArch.HorasEnLaEstacionEspacial + horasEEI;
                astroArch.MisionesEspacialesRealizadas = astroArch.MisionesEspacialesRealizadas + 1;
                fseek(fp, sizeof(Astronauta)*-1, SEEK_CUR);
                fwrite(&astroArch, sizeof(Astronauta), 1, fp);
                flag = 1;
            }
        }
        fclose(fp);
    }
}
void retornarNave(int IDnave, char estado[], int horas)
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
                strcpy(naveArch.estado, estado);
                naveArch.cantVuelos = naveArch.cantVuelos + 1;
                naveArch.horasVuelo = naveArch.horasVuelo + horas;
                fseek(fp, sizeof(Nave)*-1, SEEK_CUR);
                fwrite(&naveArch, sizeof(Nave), 1, fp);
                flag = 1;
            }
        }
        fclose(fp);
    }
}
int horasVueloAcumuladas()
{
    int flag = 0;
    int cantHoras = 0;
    int num = 0;
    do
    {
        scanf("%d", &num);
        if(num > 0)
        {
            cantHoras = num;
            flag = 1;
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t\t             [ No se pueden cargar horas negativas, try again: ] \n");
        }
    }
    while(flag == 0);

    return cantHoras;

}


