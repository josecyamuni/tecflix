#ifndef _SERIE_H_
#define _SERIE_H_
#include "Episodio.h"
#include <string>
#include <vector>
#include <iostream>

class Serie {
    friend std::ostream &operator<<(std::ostream &os, const Serie &serie);
    private: 
        float calificacion;
        std::string nombre;
		int num_temporadas;
		std::string actores;
		std::vector<Episodio> episodios;
    public:
        Serie(float ncali=0, std::string nnombre="", int nt=0, std::string na="");
		bool addEpisodio(Episodio n);
        std::string getNombre();
		std::vector<Episodio> getEpisodios();
        void calificarEpisodio();
        std::string toFile();
        std::string guardarCambiosEpisodios();

};

#endif