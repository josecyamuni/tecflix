#ifndef _TECLFIX_H_
#define _TECFLIX_H_
#include "Video.h"
#include "Serie.h"
#include "Pelicula.h"
#include <vector>

class Tecflix {
    private:
        std::vector<Pelicula> peliculas;
        std::vector<Serie> series;
    public:
        void cargarArchivo();
        void mostrarTodo();
        void mostrarPorGenero();
        void mostrarPorCalificacion();
        void mostrarEpisodiosPorCalificacion();
        void mostrarPeliculasPorCalificacion();
        void calificarVideo();
        void guardarCambios();

};

#endif