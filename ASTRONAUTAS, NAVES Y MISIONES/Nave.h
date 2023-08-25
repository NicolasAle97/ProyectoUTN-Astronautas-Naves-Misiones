#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED

typedef struct
{
    int ID;
    char tipoNave[15];
    int cantVuelos;
    int horasVuelo;
    char estado[30]; //Mantenimiento; Lista para su uso; Actualmente en mision; De baja
} Nave;

Nave datosNaves(); // cargar nave modularizadamente
void mostrarNaves(Nave naveEjemplo); // mostrar nave modularizadamente
void verArchivo(int ID); // mostrar por ID una nave
void mostrarArchivo(); // mostrar el archivo modularizadamente
void cargarVariasNaves(); // carga naves de a 1 al archivo
void pasarUnaSolaNave(Nave nueva); // agregar de a 1 nave
void modificarNave(); // que nave desea modificar
void elegirQueModificar(int i); // le pregunto que dato desea modificar
void modificarIDnave(int i); // modifica el id de la nave elegida
void modificarHsVuelo(int i); // modifica las horas de vuelo
void modificarCantVuelos(int i); // modifica la cantidad de vuelos
void modificarEstado(int i); // modifica el estado
int verificarID(int ID); // funcion para verificar si hay una nave cargada con ese ID
int MuestraIdNave();

void altaNave(int ID); // Funcion del switch nave para dar de ALTA una nave
void bajaNave(int ID); // Funcion del switch nave para dar de BAJA una nave

#endif // NAVE_H_INCLUDED
