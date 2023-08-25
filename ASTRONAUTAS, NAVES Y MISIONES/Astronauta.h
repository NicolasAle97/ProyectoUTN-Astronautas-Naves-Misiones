#ifndef ASTRONAUTA_H_INCLUDED
#define ASTRONAUTA_H_INCLUDED


typedef struct
{
    int Id;
    char Nombre[25];
    char Apellido[25];
    char Apodo[25];
    int Edad;
    char Nacionalidad[5][25];
    char Especialidad[25];//
    int HorasDeVueloAcumuladas;
    int MisionesEspacialesRealizadas;
    int HorasEnLaEstacionEspacial;
    char Estado[20]; // ACTIVADO , DESACTIVADO O EN MISION.
} Astronauta;

///FUNCIONES BASICAS PARA LOS ASTRONAUTAS
Astronauta Crear();
Astronauta Especialidades();
void GuardaUnAstronauta(Astronauta nuevo, char nombreArchivo[]);
void CargaArchivoVariasVeces();
int id_nuevo();

///FUNCIONES BASICAS PARA MOSTRAR ASTRONAUTAS.
void MostrarAstronauta(Astronauta X);
void MuestraArchivoDeAstronauta();
int MuestraAstronautaPorID(int id);
void imprimirAstronautaEnCabecera(Astronauta X);
///FUNCIONES PARA MOSTRAR LOS REGISTROS Y TOMAR UNA OPCION
int MuestraOpcionesAstronauta();
int MuestraAstronautaResumido(Astronauta X);
int MuestraOpcionesAstronautaParaSuBaja();
int MuestraOpcionesAstronautaParaSuAlta();
int MuestraOpcionesAstronautaEnMision();

///FUNCIONES PARA MODIFICAR ASTRONAUTA.
int ModificaArchivoDeAstronauta(int id);
Astronauta Modificaciones(Astronauta modifica);
///FUNCIONES DE ALTA Y BAJA - BUSCA POS.
int buscaPos(int id);
Astronauta EstadoDelAstronauta();

void BajaAstronauta(int idAstronautaBaja);
void AltaAstronauta(int idAstronataAlta);
///IMPRIMIR ASTRONAUTA.
///MAS FUNCIONES
Astronauta RetornaAstronautaPorSuID(int id);

#endif // ASTRONAUTA_H_INCLUDED
