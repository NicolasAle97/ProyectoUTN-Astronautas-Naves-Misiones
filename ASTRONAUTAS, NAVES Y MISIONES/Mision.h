#ifndef MISION_H_INCLUDED
#define MISION_H_INCLUDED


typedef struct
{
    int ID;
    int IDnave;
    char Estado[20]; /// (Listo, En vuelo, Retornada, Cancelada, Fallida)
    char Destino[30]; ///  Destino (EEI, Órbita terrestre, Luna, etc)
    char Cargamento[100]; /// Satelite, Insumos para la EEI, El auto de Elon musk , etc )
    int Tripulantes[30];  /// (Guardar sus ID)
    char DetalleDeLaMision[300]; /// Breve descripcion de la mision
    int cantTripulantes; /// contado para el arreglo de tripulantes
}Mision;

Mision crearMision(); // creacion de la mision
int verificarIDMision(int ID); // verifica si ya hay una mision con ese ID
int verificarIDNave(int ID); // verifica si hay una nave con ese ID
int verificarIDAstronauta(int ID); // verificar si existe astronauta con ese ID
int verificarDistintosID(int IDastronautas[], int ID, int validos); // verifica que no ingrese 2 veces el mismo ID
void cargarMisiones(); // cargar misiones
void pasarMisionArchivo(Mision nueva); // pasarlas al archivo
Mision funcionMenuDestino();
int funcionVerificaTripulantes(int id, int tripulante[30], int validos);

int verificarAlta(int id); // verifica el alta de la mision
int verificarNaveLista(int id); // verifica si la nave esta lista

void darBajaMision(int id); //

void mostrarMisiones(Mision misionEjemplo);
int recorrerArchMision();

Mision RetornaMisionPorSuID(int id);
int VerificaMisonesYmuestraID();

///-------------------------------------------------------funcion para lanzar mision----------------------------------------------------------///

void lanzarMision(int ID);
void lanzarNave(int ID);
void lanzarTripulante(int x[], int validos);
void lanzarTripulante2(int IDtripulante);
///-------------------------------------------------------funcion para retornar mision----------------------------------------------------------///

int horasVueloAcumuladas();
#endif // MISION_H_INCLUDED
