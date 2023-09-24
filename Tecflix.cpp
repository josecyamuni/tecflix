#include "Tecflix.h"
#include <cstdlib>  // for the fail member function
#include <fstream>  // for file I/O definitions
#include <iostream> // for cout definition
#include <sstream>

using namespace std;

void Tecflix::cargarArchivo() {
	ifstream input_file;
    
	input_file.open("VideosXXXX.txt");
	if (input_file.fail()) {
		cout << "Sorry, the file couldn't be opened!\n";
	}

	vector<string> atributos;
    string input{};
	while (getline(input_file, input)) {
		stringstream sstr{input};
		while(sstr.good()) {
			string substr;
			getline(sstr, substr, ':');
			atributos.push_back(substr);
		}
		if (atributos.at(0) == "Serie") {
			Serie nueva{stof(atributos.at(11)), atributos.at(2), stoi(atributos.at(9)), atributos.at(8)};
			series.push_back(nueva);
		} else if(atributos.at(0) == "Pelicula") {
			Pelicula nueva{stof(atributos.at(11)), stof(atributos.at(12)), stoi(atributos.at(13)), stoi(atributos.at(1)), stoi(atributos.at(3)), atributos.at(2), atributos.at(4), atributos.at(8)};
			peliculas.push_back(nueva);
		} else if(atributos.at(0) == "Episodio") {
			Episodio nuevo{stof(atributos.at(11)), stof(atributos.at(12)), stoi(atributos.at(13)), stoi(atributos.at(1)), stoi(atributos.at(3)), atributos.at(2), atributos.at(4), stoi(atributos.at(5)), stoi(atributos.at(6)), atributos.at(7), atributos.at(10)};
			for(auto &serie: series) {
				if(serie.getNombre() == atributos.at(10)) {
					serie.addEpisodio(nuevo);
					break;
				}
			}
		}
		atributos.clear();
	}

	input_file.close();
}

void Tecflix::mostrarTodo() {
    for (auto serie: series) {
		cout << serie << endl;
		for(auto episodio: serie.getEpisodios()) {
			cout << episodio << endl;
		}
	}

	for (auto pelicula: peliculas) {
		cout << pelicula << endl;
	}    
}


void Tecflix::mostrarPorGenero() {
    string genero;
	cout << "Que genero desea buscar?" << endl;
	cin >> genero;
    for (auto serie: series) {
		for(auto episodio: serie.getEpisodios()) {
			if(episodio.getGenero()==genero)
            cout << episodio << endl;
		}
	}
	for (auto pelicula: peliculas) {
		if(pelicula.getGenero()==genero)
            cout << pelicula << endl;
	}    
}
	
void Tecflix::mostrarPorCalificacion() {
	float caliMin;
	cout << "Ingrese la calificacion minima" << endl;
	cin >> caliMin;
    for (auto serie: series) {
		for(auto episodio: serie.getEpisodios()) {
			if(episodio.getCali()>=caliMin)
            	cout << episodio << endl;
		}
	}
	for (auto pelicula: peliculas) {
		if(pelicula.getCali()>=caliMin)
            cout << pelicula << endl;
	}    
}

void Tecflix::mostrarEpisodiosPorCalificacion() {
	string serieSelec;
	float caliMin;
	cout << "Ingrese la serie que desea consultar" << endl;
	cin >> serieSelec;
	cout << "Ingrese la calificacion minima de los episodios" << endl;
	cin >> caliMin;
    for (auto serie: series) {
		if(serie.getNombre()==serieSelec){
			cout << serie.getNombre();
			for(auto episodio: serie.getEpisodios()) {
				if(episodio.getCali()>=caliMin)
            		cout << episodio << endl;
			}
		}
	}
}

void Tecflix::mostrarPeliculasPorCalificacion(){
	float caliMin;
	cout << "Ingrese la calificacion minima" << endl;
	cin >> caliMin;
	for (auto pelicula: peliculas) {
		if(pelicula.getCali()>=caliMin)
            cout << pelicula << endl;
	}    
}

void Tecflix::calificarVideo() {
	string seleccion{""};
	cout << "Desea calificar episodio (escriba: 1) o pelicula (escriba: 2)?" << endl;
	cin >> seleccion;
	if (seleccion == "1"){
		string selecSeries;
		cout << "En que serie se encuentra el episodio que desea calificar?" << endl;
		cin >> selecSeries;
		for (auto &serie: series) {
			if(serie.getNombre()==selecSeries)
				serie.calificarEpisodio();
		}
	
	}
	else if (seleccion == "2"){
		string movie{""};
		cout << "Que pelicula desea calificar?" << endl;
		cin >> movie;
		for (auto &pelicula: peliculas) {
			if(pelicula.getNombre()==movie){
				float n_calif{0};
				cout << "Que calificacion desea dar a la pelicula?" << endl;
				cin >> n_calif;
				pelicula.calificar(n_calif);
				pelicula.getCali();
			}
		} 
	}

}

void Tecflix::guardarCambios() {
	ofstream output_file;
	output_file.open("VideosXXXX.txt");
	if (output_file.fail()) {
		cout << "Sorry, the file couldn't be opened!\n";
	}

	for (auto &serie: series) {
		output_file << serie.toFile() << endl;
		output_file << serie.guardarCambiosEpisodios() << endl;
	}

	for (auto &pelicula: peliculas) {
		output_file << pelicula.toFile() << endl;
	}

	output_file.close();
}
