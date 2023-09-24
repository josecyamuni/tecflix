#ifndef _PELICULA_H_
#define _PELICULA_H_
#include "Video.h"
#include <string>
#include <iostream>

class Pelicula: public Video {
	friend std::ostream &operator<<(std::ostream &os, const Pelicula &pelicula);
	private:
		std::string actores;
	public:
		Pelicula(float ncali=0, float nacum=0, int nnumcali=0, int nid=0, int nduracion=0, std::string nnombre="", std::string ngenero="", std::string nactores="");
		std::string toFile();
};

#endif