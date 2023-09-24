#include "Serie.h"

using namespace std;

Serie::Serie(float ncali, string nnombre, int nt, string na) : calificacion{ncali}, nombre{nnombre}, num_temporadas{nt}, actores{na} {

}

bool Serie::addEpisodio(Episodio n) {
    for(int i{0}; i < episodios.size(); i++)
        if (episodios.at(i).getNombre() == n.getNombre())
            return false;
    episodios.push_back(n);
	return true;
}

string Serie::getNombre() {
    return nombre;
}

vector<Episodio> Serie::getEpisodios(){
    return episodios;
}

void Serie::calificarEpisodio(){
    string episode;
    cout << "Que episodio desea calificar?" << endl;
    cin >> episode;
    for(auto &episodio: episodios) {
		if(episodio.getNombre()==episode) {			
            float n_calif{0};
			cout << "Que calificacion desea dar al episodio?" << endl;
			cin >> n_calif;
			episodio.calificar(n_calif);
		}
	}
}

ostream &operator<<(ostream &os, const Serie &serie){
    os << "[Serie: " << serie.nombre << ": " << serie.num_temporadas << ": " << serie.actores <<": " << serie.calificacion <<"]";
    return os;
}

string Serie::toFile() {
	return "Serie:0:" + nombre + ":0:0:0:0:0:" + actores + ":" + to_string(num_temporadas) + ":0:" + to_string(calificacion) + ":0:0";
}

string Serie::guardarCambiosEpisodios() {
    string resultado{""};
    for(auto &episodio: episodios)
        resultado += episodio.toFile() + "\n";
    return resultado;
    
}