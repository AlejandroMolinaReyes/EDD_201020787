#include "pasajero.h"

Pasajero::Pasajero(QString id, int numeroMaletas,int numeroDocumentos,int numeroTurnos)
{
    this->id = id;
    this->numeroMaletas = numeroMaletas;
    this->numeroDocumentos = numeroDocumentos;
    this->numeroTurnos = numeroTurnos;
}
