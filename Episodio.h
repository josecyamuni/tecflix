#ifndef _EPISODIO_H_
#define _EPISODIO_H_
#include "Video.h"
#include <string>
#include <iostream>

class Episodio: public Video {
	friend std::ostream &operator<<(std::ostream &os, const Episodio &episodio);
	private:
		int temporada, numero;
		std::string invitados, seriePertenece;
	public:
		Episodio(float ncali=0, float nacum=0, int nnumcali=0, int nid=0, int nduracion=0, std::string nnombre="", std::string ngenero="", int ntemporada=0, int nnumero=0, std::string ninvitados="", std::string nserie="");
		std::string toFile();
};

#endif