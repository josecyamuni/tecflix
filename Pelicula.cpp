#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula(float ncali, float nacum, int nnumcali, int nid, int nduracion, string nnombre, string ngenero, string nactores)
	: Video{ncali, nacum, nnumcali, nid, nduracion, nnombre, ngenero}, actores{nactores}{
}

ostream &operator<<(ostream &os, const Pelicula &pelicula) {
    os << "[Pelicula: " << pelicula.nombre << ": " << pelicula.actores << ": " << pelicula.calificacion << "]";
    return os;
}

string Pelicula::toFile() {
	return "Pelicula:" + to_string(id) + ":" + nombre + ":" + to_string(duracion) + ":" + genero + ":0:0:0:" + actores + ":0:0:" + to_string(calificacion) + ":" + to_string(acumuladoCalif) + ":" + to_string(numCalif);
}