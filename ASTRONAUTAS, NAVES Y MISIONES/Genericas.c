#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESC 27
///ACA SE CREAN LAS FUNCIONES DE USO GENERICO, PARA UTILIZARLAS DEBEN LLAMAR A LAS FUNCIONES EN EL MAIN.
///LAS FUNCIONES COMENTADAS ESTAN EN REPOSO, CON EL TIEMPO SI SE PUEDEN MEJORAR SE USARAN.

void MuestraDiaHoraYanio()
{
    time_t tiempoahora;
    time(&tiempoahora);
    printf("%s\n", ctime(&tiempoahora));
}


///**************************************************************************************///
///
///
///
///**************************************************************************************///
/*

int cuentaRegistros(char nombreArchivo[], int dato) /// dato = sizeof tipo de dato del archivo
{
    int total = 0;
    FILE * pArch = fopen (nombreArchivo, "rb");
    if (pArch! = NULL)
    {
        fseek(pArch, 0, SEEK_END);
        total=ftell(pArch)/dato;
        fclose(pArch);
    }
    return total;
}

*/


///**************************************************************************************///
///
///
///
///**************************************************************************************///

/*
void GuardaUnAstronauta(Astronauta nuevo, char nombreArchivo[])
{
    FILE *pArchAstronauta=fopen(nombreArchivo,"a+b");

    if(pArchAstronauta!=NULL)
    {
        fwrite(&nuevo,sizeof(Astronauta),1,pArchAstronauta);
        fclose(pArchAstronauta);
    }
}

*/


///**************************************************************************************///
///
///
///
///**************************************************************************************///

/*

/// Función que pasa clientes en alta o baja a un archivo:
/// Si queres pasar todos los astronautas en estado desactivado a un archivo "AstronautasDesactivados" usas esta funcion.
/// Si queres pasar todos los astronautas en estado activado a un archivo "AstronautasActivados" usas esta funcion.
void creaArchivo(char nombreArchivo [], int bajaOalta, int opcion)
{
    Astronauta c;

    FILE*pArchAstronauta = fopen (nombreArchivo, "rb");

    if(pArchAstronauta)
    {
        while(fread(&c, sizeof(Astronauta), 1,pArchAstronauta)> 0)
        {
            if(c.Estado == bajaOalta)
            {
                GuardaUnAstronauta(c);
            }
        }
        fclose (pArchAstronauta);
    }
}
*/
