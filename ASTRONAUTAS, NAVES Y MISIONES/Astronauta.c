#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Astronauta.h"

#define ESC 27

const char ArchivoAstronauta[]="AstronautasArch.dat";


///**************************************************************************************///
/// PARAMETROS: NO TIENE.
/// RETORNO: Un identificador autoincremental(0-1-2-3-4...) que se le asigna a los astronautas nuevos.
/// FUNCION: SE ENCARGA EN QUE NO SE REPITAN LOS ID.
///**************************************************************************************///

int id_nuevo()
{
    int idnuevo=0;
    Astronauta aux;

    FILE *pArchAstronauta=fopen(ArchivoAstronauta,"r+b");

    if(pArchAstronauta!=NULL)
    {
        while(fread(&aux,sizeof(Astronauta),1,pArchAstronauta) > 0)
        {
            idnuevo=aux.Id+1;
        }
        fclose(pArchAstronauta);
    }
    return idnuevo;
}

///**************************************************************************************///
/// PARAMETROS: No tiene.
/// RETORNO: Un tipo de dato "Astronauta" con sus respectivos campos completados por el usuario.
/// FUNCION: ES LA PLANILLA DE REGISTRO QUE USA CADA ASTRONAUTA.
///**************************************************************************************///

Astronauta Crear()
{
    Astronauta nuevo;
    Astronauta aux;
    char Estado[30];

    imprimirCabecera("                 [REGISTRAR ASTRONAUTA]");

    printf("\n\n\n");
    nuevo.Id=id_nuevo();

    printf("\n\t                                                   [Nombre]: ");
    fflush(stdin);
    gets(nuevo.Nombre);

    printf("\n\t                                                   [Apellido]: ");
    fflush(stdin);
    gets(nuevo.Apellido);

    printf("\n\t                                                   [Apodo]: ");
    fflush(stdin);
    gets(nuevo.Apodo);

    printf("\n\t                                                   [Edad]: ");
    scanf("%d",&nuevo.Edad);

    printf("\n\t                                                   [Nacionalidad]: ");
    fflush(stdin);
    gets(nuevo.Nacionalidad);

    strcpy(nuevo.Estado,"ACTIVADO");///COPIA EN EL ESTADO DEL ASTRONAUTA EL RETORNO DE LA FUNCION ESTADO DEL ASTRONAUTA.

    nuevo.HorasDeVueloAcumuladas=0;
    nuevo.HorasEnLaEstacionEspacial=0;
    nuevo.MisionesEspacialesRealizadas=0;

    aux=Especialidades();
    strcpy(nuevo.Especialidad,aux.Especialidad); ///COPIA EN LA ESPECIALIDAD DEL ASTRONAUTA EL RETORNO DE LA FUNCION ESPECIALIDADES.


    return nuevo;
}



///**************************************************************************************///
/// PARAMETRO: No tiene.
/// RETORNO: Una variable de tipo Astronauta con un solo campo modificado.
/// FUNCION: Asignacion manual de el estado del Astronauta.
///**************************************************************************************///


Astronauta EstadoDelAstronauta()
{
    char Estado[30];
    int opcion=0;
    int flag=0;
    Astronauta nuevo;

    do
    {
        printf("\n\n\n\n");
        imprimirCabecera("                   ESTADOS DEL ASTRONAUTA");
        printf("\n\n\n");
        printf("\n\n\t\t\t\t\t\t\t             1.    [ ESTADO - ACTIVO ]\n");
        printf("\n\n\t\t\t\t\t\t\t             2.    [ ESTADO - DESACTIVADO ]\n");
        printf("\n\n\t\t\t\t\t\t\t             3.    [ ESTADO - EN MISION ]\n");
        printf("\n");
        opcion=ingresarOpcion();
        switch(opcion)
        {
        case 1:
        {
            strcpy(nuevo.Estado,"ACTIVADO");
            flag=1;
            break;
        }
        case 2:
        {
            strcpy(nuevo.Estado,"DESACTIVADO");
            flag=1;
            break;
        }
        case 3:
        {
            strcpy(nuevo.Estado,"EN MISION");
            flag=1;
            break;
        }
        default:
        {
            flag=0;
            break;
        }
        system("pause");
        system("cls");
        }
    }
    while(flag==0);

    return nuevo;
}

///**************************************************************************************///
/// PARAMETROS: No tiene.
/// RETORNA: Un tipo de dato "Astronauta" con sus respectivos campos completados por el usuario.
/// FUNCION: Modifica los campos de registro de un Astronauta ya creado.
///**************************************************************************************///

Astronauta Especialidades()
{
    Astronauta EspecialidadAstro;

    int opcion=0;
    char control = 's';

    int flag=0;

    do
    {
        printf("\n\n\n");
        imprimirCabecera("                   MENU ESPECIALIDADES");
        printf("\n\n\n");
        printf("\n\n\t\t\t\t\t\t\t             1.    [ Piloto ].\n");
        printf("\n\n\t\t\t\t\t\t\t             2.    [ Astrofisico ].\n");
        printf("\n\n\t\t\t\t\t\t\t             3.    [ Ingeniero Espacial ].\n");
        printf("\n\n\t\t\t\t\t\t\t             4.    [ Biologo Analista ].\n");
        opcion=ingresarOpcion();
        switch(opcion)
        {
        case 1:
        {
            control = 'n';
            strcpy(EspecialidadAstro.Especialidad,"Piloto");
            break;
        }
        case 2:
        {
            control = 'n';
            strcpy(EspecialidadAstro.Especialidad,"Astrofisico");
            break;
        }
        case 3:
        {
            control = 'n';
            strcpy(EspecialidadAstro.Especialidad,"Ingeniero Espacial");
            break;
        }
        case 4:
        {
            control = 'n';
            strcpy(EspecialidadAstro.Especialidad,"Biologo");
            break;
        }
        default:
        {
            printf("\nOPCION INCORRECTA.\n");
            break;
        }
        }
        system("pause");
        system("cls");
    }
    while(control == 's');

    return EspecialidadAstro;
}


///**************************************************************************************///
/// PARAMETROS: Recibe en primer lugar un dato de tipo Astronauta y en segundo lugar el nombre del archivo donde se guardara el Astronauta.
/// RETORNO: No tiene.
/// FUNCION: Guarda un Astronauta en un registro para conservar sus datos.
///**************************************************************************************///


void GuardaUnAstronauta(Astronauta nuevo, char nombreArchivo[])
{
    FILE *pArchAstronauta=fopen(nombreArchivo,"a+b");

    if(pArchAstronauta!=NULL)
    {
        fwrite(&nuevo,sizeof(Astronauta),1,pArchAstronauta);
        fclose(pArchAstronauta);
    }
}


///**************************************************************************************///
/// PARAMETRO: No tiene.
/// RETORNO: No tiene.
/// FUNCION: Guarda en un registro los Astronautas nuevos de forma secuencial.
///**************************************************************************************///


void CargaArchivoVariasVeces()
{
    Astronauta nuevo;
    int opcion=0;
    do
    {
        nuevo=Crear();             //ABRE EL ARCHIVO Y LO CIERRA, Si nuevo=Crear esta adentro de la funcion CargaArchivo , se abre 2 veces al mismo tiempo.
        GuardaUnAstronauta(nuevo,"AstronautasArch.dat"); //ABRE EL ARCHIVO Y LO CIERRA, Se abre el archivo , llama a la funcion crear, abre el archivo y se pierde el cursor que marca la ubicacion.
        printf("\nESC PARA SALIR, ENTER PARA CONTINUAR CARGANDO ARCHIVO.\n");
        opcion=getch();
        system("pause");
        system("cls");
    }
    while(opcion!=27);
}




///**************************************************************************************///
/// PARAMETRO: Recibe un ID ingresado por el usuario.
/// RETORNO: El numero donde se posiciona el Astronauta en el registro.
/// FUNCION: Busca la posicion de un Astronauta en el registro.
///**************************************************************************************///


int buscaPos(int id)
{
    int pos = -1;

    Astronauta c;

    FILE * pArchAstronauta = fopen (ArchivoAstronauta, "rb");

    if(pArchAstronauta)
    {
        while(pos==-1 && fread(&c,sizeof(Astronauta),1,pArchAstronauta)> 0)
        {
            if(c.Id==id)
            {
                pos=ftell(pArchAstronauta)/sizeof(Astronauta)-1;
            }
        }
        fclose(pArchAstronauta);
    }

    return pos;
}

///**************************************************************************************///
/// PARAMETRO:
/// RETORNO:
/// FUNCION:  Retorna un alumno por su ID
///**************************************************************************************///

Astronauta RetornaAstronautaPorSuID(int id)
{
    int flag = 0;

    Astronauta c;

    FILE * pArchAstronauta = fopen (ArchivoAstronauta, "rb");

    if(pArchAstronauta)
    {
        while(flag==0 && fread(&c,sizeof(Astronauta),1,pArchAstronauta)> 0)
        {
            if(c.Id==id)
            {
                flag=1;
            }
        }
        fclose(pArchAstronauta);
    }

    return c;
}

///**************************************************************************************///
/// PARAMETRO: Recibe un ID ingresado por el usuario.
/// RETORNO: No tiene.
/// FUNCION: Muestra un registro de tipo Astronauta por un determinado ID.
///**************************************************************************************///


int MuestraAstronautaPorID(int id)
{
    Astronauta aux;

    int flag=0;
    FILE *pArch=fopen(ArchivoAstronauta, "r+b");
    if(pArch!=NULL)
    {
        printf("\n\n\n");
        while(fread(&aux,sizeof(Astronauta),1,pArch) > 0)
        {
            flag=1;
            printf("\n                                                                          [ ID %d %s %s ] ",aux.Id,aux.Nombre, aux.Apellido);
        }
        printf("\n\n\n");
        fclose(pArch);
    }
    return flag;
}


///**************************************************************************************///
/// PARAMETRO: Recibe un ID cargado por el usuario, tambien recibe el estado del Astronauta, 1 Activado, 2 desactivado.
/// RETORNO: No tiene.
/// FUNCION: Modifica el estado del astronauta.
///**************************************************************************************///


void BajaAstronauta(int idAstronautaBaja)
{
    Astronauta c;
    FILE * pArchAstronauta = fopen(ArchivoAstronauta, "r+b");

    if(pArchAstronauta!=NULL)
    {
        if(strcmp(c.Estado, "DESACTIVADO") != 0)
        {
            fseek(pArchAstronauta,sizeof(Astronauta)*buscaPos(idAstronautaBaja), SEEK_SET);
            fread(&c,sizeof(Astronauta), 1, pArchAstronauta);
            strcpy(c.Estado,"DESACTIVADO");
            fseek(pArchAstronauta,sizeof(Astronauta)*buscaPos(idAstronautaBaja), SEEK_SET);
            fwrite(&c, sizeof(Astronauta), 1, pArchAstronauta);
            fclose(pArchAstronauta);
            printf("\n\n\t\t\t\t\t\t\t             [ASTRONAUTA DADO DE BAJA CORRECTAMENTE]\n\n");
        }
    }
}

///**************************************************************************************///
/// PARAMETRO: Recibe un ID cargado por el usuario, tambien recibe el estado del Astronauta, 1 Activado, 2 desactivado.
/// RETORNO: No tiene.
/// FUNCION: Modifica el estado del astronauta.
///**************************************************************************************///


void AltaAstronauta(int idAstronautaAlta)
{
    Astronauta c;

    FILE * pArchAstronauta = fopen(ArchivoAstronauta, "r+b");

    if(pArchAstronauta!=NULL)
    {
         if(strcmp(c.Estado, "ACTIVADO") != 0)
        {
        fseek(pArchAstronauta,sizeof(Astronauta)*buscaPos(idAstronautaAlta), SEEK_SET);
        fread(&c,sizeof(Astronauta), 1, pArchAstronauta);
        strcpy(c.Estado,"ACTIVADO");
        fseek(pArchAstronauta,sizeof(Astronauta)*buscaPos(idAstronautaAlta), SEEK_SET);
        fwrite(&c, sizeof(Astronauta), 1, pArchAstronauta);
        fclose(pArchAstronauta);
        printf("\n\n\t\t\t\t\t\t\t             [ASTRONAUTA DADO DE ALTA CORRECTAMENTE]\n\n");
        }
    }
}

///**************************************************************************************///
/// PARAMETRO: Recibe un ID cargado por el usuario, tambien recibe el estado del Astronauta, 1 Activado, 2 desactivado.
/// RETORNO: No tiene.
/// FUNCION: Modifica el estado del astronauta.
///**************************************************************************************///


void EstadoAstronautaEnMision(int idAstronautaAlta)
{
    Astronauta c;

    FILE * pArchAstronauta = fopen(ArchivoAstronauta, "r+b");

    if(pArchAstronauta!=NULL)
    {
        fseek(pArchAstronauta,sizeof(Astronauta)*buscaPos(idAstronautaAlta), SEEK_SET);
        fread(&c,sizeof(Astronauta), 1, pArchAstronauta);
        strcpy(c.Estado,"EN MISION");
        fseek(pArchAstronauta,sizeof(Astronauta)*buscaPos(idAstronautaAlta), SEEK_SET);
        fwrite(&c, sizeof(Astronauta), 1, pArchAstronauta);
        fclose(pArchAstronauta);
    }
}


///**************************************************************************************///
/// PARAMETRO: Recibe un Astronauta previamente creado, para ser modificado.
/// RETORNO: Retorna el Astronauta recibido por parametro pero ya modificado.
/// FUNCION: Modifica un registro de tipo Astronauta.
///**************************************************************************************///

Astronauta Modificaciones(Astronauta modifica)
{
    int opcion=0;
    char Estado[30];
    Astronauta aux;
    int flag=0;
    do
    {
        imprimirCabecera("            MENU PARA MODIFICAR ASTRONAUTA");
        printf("\n\n\t\t\t\t\t\t\t             1.    [ NOMBRE ] \n");
        printf("\n\n\t\t\t\t\t\t\t             2.    [ APELLIDO ] \n");
        printf("\n\n\t\t\t\t\t\t\t             3.    [ APODO ] \n");
        printf("\n\n\t\t\t\t\t\t\t             4.    [ EDAD ] \n");
        printf("\n\n\t\t\t\t\t\t\t             5.    [ NACIONALIDAD ] \n");
        printf("\n\n\t\t\t\t\t\t\t             6.    [ ESPECIALIDAD ] \n");
        printf("\n\n\t\t\t\t\t\t\t             0.    [ SALIR ]  \n");

        opcion=ingresarOpcion();

        switch(opcion)
        {
        case 1:
        {
            printf("\n\n\n\n");
            imprimirCabecera("                Modificar Nombre");
            printf("\n\n\n\n");
            printf("\n\t\t[Nombre anterior]: %s.\n",modifica.Nombre);
            printf("\n\t\t[Nuevo Nombre]: ");
            fflush(stdin);
            gets(modifica.Nombre);
            printf("\n\n\n\n");
            imprimirCabecera("                MODIFICACION CON EXITO.");
            printf("\n\n\n\n");
            system("pause");
            system("cls");
            flag=1;
            break;
        }
        case 2:
        {
            printf("\n\n\n\n");
            imprimirCabecera("                Modificar Apellido");
            printf("\n\n\n\n");
            printf("\n\t\t[Apellido anterior]: %s\n",modifica.Apellido);
            printf("\n\t\t[Nuevo Apellido]: ");
            fflush(stdin);
            gets(modifica.Apellido);
            printf("\n\n\n\n");
            imprimirCabecera("                MODIFICACION CON EXITO");
            printf("\n\n\n\n");
            system("pause");
            system("cls");
            flag=1;
            break;
        }
        case 3:
        {
            printf("\n\n\n\n");
            imprimirCabecera("                Modificar Apodo");
            printf("\n\n\n\n");
            printf("\n\t\t[Apodo anterior]: %s\n",modifica.Apodo);
            printf("\n\t\t[Nuevo Apodo]: ");
            fflush(stdin);
            gets(modifica.Apodo);
            printf("\n\n\n\n");
            imprimirCabecera("                MODIFICACION CON EXITO");
            printf("\n\n\n\n");
            system("pause");
            system("cls");
            flag=1;
            break;
        }
        case 4:
        {
            printf("\n\n\n\n");
            imprimirCabecera("                Modificar Edad");
            printf("\n\n\n\n");
            printf("\n\t\t[Edad anterior]: %d\n",modifica.Edad);
            printf("\n\t\t[Nueva Edad]: ");
            scanf("%d",&modifica.Edad);
            printf("\n\n\n\n");
            imprimirCabecera("                MODIFICACION CON EXITO");
            printf("\n\n\n\n");
            system("pause");
            system("cls");
            flag=1;
            break;
        }
        case 5:
        {
            printf("\n\n\n\n");
            imprimirCabecera("                Modificar Nacionalidad");
            printf("\n\n\n\n");
            printf("\n\t\t[Nacionalidad anterior]: %s\n",modifica.Nacionalidad);
            printf("\n\t\t[Nueva Nacionalidad]: ");
            fflush(stdin);
            gets(modifica.Nacionalidad);
            printf("\n\n\n\n");
            imprimirCabecera("                MODIFICACION CON EXITO");
            printf("\n\n\n\n");
            system("pause");
            system("cls");
            flag=1;
            break;
        }
        case 6:
        {
            printf("\n\n\n\n");
            imprimirCabecera("                Modificar Especialidad");
            printf("\n\n\n\n");
            printf("\n\t\t[Especialidad anterior]: %s", modifica.Especialidad);
            printf("\n\n\n\n");
            aux=Especialidades();
            strcpy(modifica.Especialidad,aux.Especialidad); ///COPIA EN LA ESPECIALIDAD DEL ASTRONAUTA EL RETORNO DE LA FUNCION ESPECIALIDADES.
            printf("\n\n\n\n");
            imprimirCabecera("                MODIFICACION CON EXITO");
            printf("\n\n\n\n");
            system("pause");
            system("cls");
            flag=1;
            break;

        }
        case 0:
        {
            opcion=ESC;
            flag=0;
            break;
        }
        default:
        {
            imprimirCabecera("              OPCION INCORRECTA");
            flag=0;
            break;
        }
        system("pause");
        system("cls");
        }
    }
    while(opcion!=ESC);

    if(flag==1)
    {
        printf("\n\n\n\n");

        imprimirCabecera("               MODIFICACION CON EXITO.");
        printf("\n\n\n\n");
    }

    return modifica;
}


///**************************************************************************************///
/// PARAMETRO: Recibe una variable de tipo int que guarda un ID cargado por el usuario.
/// RETORNO: No tiene
/// FUNCION: Modificar un astronauta previamente cargado, pisandolo con los datos del astronauta modificado.
///**************************************************************************************///

int ModificaArchivoDeAstronauta(int id)
{
    FILE *pArchAstronauta=fopen(ArchivoAstronauta,"r+b");
    Astronauta modifica;
    int flag=0;

    if(pArchAstronauta!=NULL)
    {
        while(flag==0 && fread(&modifica, sizeof(Astronauta),1,pArchAstronauta) > 0)
        {
            if(modifica.Id==id)
            {
                fseek(pArchAstronauta,sizeof(Astronauta)*-1,SEEK_CUR);
                modifica=Modificaciones(modifica);
                fwrite(&modifica,sizeof(Astronauta),1,pArchAstronauta);
                flag=1;
            }
        }
        fclose(pArchAstronauta);
    }

}


///**************************************************************************************///
/// PARAMETRO: No tiene.
/// RETORNO: Retorna una variable booleana.
/// FUNCION: Muestra una lista de Astronautas, Si el flag es 0 no se puede ingresar ID, si el flag es 1 se puede ingresar id.
///**************************************************************************************///


int MuestraOpcionesAstronauta()
{
    FILE *pArchAstronauta=fopen(ArchivoAstronauta,"r+b");
    Astronauta modifica;
    int flag=0;
    if(pArchAstronauta!=NULL)
    {
        printf("\n\n\n");
        imprimirCabecera("\tLISTA DE ASTRONAUTAS");
        printf("\n\n\n");

        while(fread(&modifica, sizeof(Astronauta), 1, pArchAstronauta) > 0)
        {
            imprimirAstronautaEnCabecera(modifica);
            flag=1;
            printf("\n");
        }
        fclose(pArchAstronauta);
    }
    return flag;
}


///**************************************************************************************///
/// PARAMETRO: No tiene.
/// RETORNO: Retorna una variable booleana.
/// FUNCION: Muestra una lista de Astronautas en estado Desactivado, Si el flag es 0 no se puede ingresar ID, si el flag es 1 se puede ingresar id.
///**************************************************************************************///


int MuestraOpcionesAstronautaDeBaja()
{
    FILE *pArchAstronauta=fopen(ArchivoAstronauta,"r+b");
    Astronauta modifica;
    int flag=0;
    if(pArchAstronauta!=NULL)
    {
        printf("\n\n\n");
        imprimirCabecera("             LISTA DE ASTRONAUTAS DE BAJA");
        printf("\n\n\n");

        while(fread(&modifica, sizeof(Astronauta), 1, pArchAstronauta) > 0)
        {
            if(strcmp(modifica.Estado,"DESACTIVADO")==0)
            {
                imprimirAstronautaEnCabecera(modifica);
                printf("\n");
                flag=1;
            }
        }
        fclose(pArchAstronauta);
    }
    return flag;
}



///**************************************************************************************///
/// PARAMETRO: No tiene.
/// RETORNO: Retorna una variable booleana.
/// FUNCION: Muestra una lista de Astronautas en estado Activado, Si el flag es 0 no se puede ingresar ID, si el flag es 1 se puede ingresar id.
///**************************************************************************************///

int MuestraOpcionesAstronautaDeAlta()
{
    FILE *pArchAstronauta=fopen(ArchivoAstronauta,"r+b");
    Astronauta modifica;
    int flag=0;
    if(pArchAstronauta!=NULL)
    {
        printf("\n\n\n");
        imprimirCabecera("             LISTA DE ASTRONAUTAS DE ALTA");
        printf("\n\n\n");

        while(fread(&modifica, sizeof(Astronauta), 1, pArchAstronauta) > 0)
        {
            if(strcmp(modifica.Estado,"DESACTIVADO")!=0)
            {
                imprimirAstronautaEnCabecera(modifica);
                printf("\n");
                flag=1;
            }
        }
        fclose(pArchAstronauta);
    }
    return flag;
}


///**************************************************************************************///
/// PARAMETRO: No tiene.
/// RETORNO: Retorna una variable booleana.
/// FUNCION: Muestra una lista de Astronautas en estado EN MISION, Si el flag es 0 no se puede ingresar ID, si el flag es 1 se puede ingresar id.
///**************************************************************************************///

