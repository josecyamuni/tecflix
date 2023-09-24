#include "Episodio.h"

using namespace std;

Episodio::Episodio(float ncali, float nacum, int nnumcali, int nid, int nduracion, string nnombre, string ngenero, int ntemporada, int nnumero, string ninvitados, string nserie)
	: Video{ncali, nacum, nnumcali, nid, nduracion, nnombre, ngenero}, temporada{ntemporada}, numero{nnumero}, invitados{ninvitados}, seriePertenece{nserie}{

}

ostream &operator<<(ostream &os, const Episodio &episodio){
	os << "[Episodio: " << episodio.nombre << ": " << episodio.temporada << ": " << episodio.invitados << ": " << episodio.calificacion <<"]";
    return os;
}

string Episodio::toFile() {
	return "Episodio:" + to_string(id) + ":" + nombre + ":" + to_string(duracion) + ":" + genero + ":" + to_string(temporada) + ":" + to_string(numero) + ":" + invitados + ":0:0:" + seriePertenece + ":" + to_string(calificacion) + ":" + to_string(acumuladoCalif) + ":" + to_string(numCalif);
}