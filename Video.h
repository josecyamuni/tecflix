#ifndef _VIDEO_H_
#define _VIDEO_H_
#include <string>

class Video {
	protected:
		float calificacion, acumuladoCalif;
		int id, duracion, numCalif;
		std::string nombre, genero;
	public:
		Video(float ncali=0, float nacum=0, int nnumcali=0, int nid=0, int nduracion=0, std::string nnombre="", std::string ngenero="");
		std::string getGenero();
		float getCali();
		bool calificar(float);
		std::string getNombre();
};

#endif