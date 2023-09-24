#include "Video.h"
#include <iostream>

using namespace std;

Video::Video(float ncali, float nacum, int nnumcali, int nid, int nduracion, string nnombre, string ngenero) : calificacion{ncali}, acumuladoCalif{nacum}, numCalif{nnumcali}, id{nid}, duracion{nduracion}, nombre{nnombre}, genero{ngenero} {

}

string Video::getGenero(){
    return genero;
}

float Video::getCali(){
    return calificacion;
}

string Video::getNombre(){
	return nombre;
}

bool Video::calificar(float calif) {
    if(calif < 1 || calif > 10) {
        cout << "Las calificacion debe ser un numero mayor a 1 y menor a 10" << endl;
        return false;
    }
    acumuladoCalif += calif;
    numCalif ++;
    calificacion = acumuladoCalif/numCalif;
    cout << "El video ha sido calificado" << endl;
    return true;
}