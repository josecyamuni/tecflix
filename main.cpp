#include <cstdlib>  // for the fail member function
#include <fstream>  // for file I/O definitions
#include <iostream> // for cout definition
#include <string>
#include <vector>
#include <sstream>
#include "Tecflix.h"
#include "Serie.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Video.h"


using namespace std;

int main() {
	Tecflix tecflix{};
	tecflix.cargarArchivo();
    string selection{};
    cout << "Bienvenido a Tecflix" << endl;

    do {

		cout << "Mostrar todos los videos (Escriba: 1)" << endl;
        cout << "Mostrar videos con una calificacion en especifico (Escriba: 2)" << endl;
        cout << "Mostrar videos de un genero en especifico (Escriba: 3)" << endl;
        cout << "Mostrar los episodios de una serie con una calificacion en especifico (Escriba: 4)" << endl;
        cout << "Mostrar peliculas con una calificacion en especifico (Escriba: 5)" << endl;
		cout << "Calificar video (Escriba: 6)" << endl;
        cout << "Guardar cambios (Escriba: 7)" <<endl;
        cout << "Salir del programa (Escriba: Q)" <<endl;
        cin >> selection;

        if (selection == "1")      
			tecflix.mostrarTodo();
        else if (selection == "2")
			tecflix.mostrarPorCalificacion();
        else if (selection == "3")
			tecflix.mostrarPorGenero();  
        else if (selection == "4")
            tecflix.mostrarEpisodiosPorCalificacion();
		else if (selection == "5")
            tecflix.mostrarPeliculasPorCalificacion();
		else if (selection == "6")
            tecflix.calificarVideo();
        else if (selection == "7")
            tecflix.guardarCambios();
        else if (selection == "Q")
            cout << "Se salio del programa" << endl;
        else
            cout << "Se ingreso una respuesta incorrecta, lea bien las instrucciones" <<endl;

    } while (selection != "Q");	
	return 0;
}