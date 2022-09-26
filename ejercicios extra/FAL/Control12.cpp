/*

NUMERO DE GRUPO:

NOMBRRE Y APELLIDOS DE LOS AUTORES:


*/

#include <iostream>
using namespace std;

// Representación de un tema
typedef struct {
	float tiempo_req;  // tiempo requerido para estudiar
	float nota_prim;   // Nota que supone en la primera parte
	float nota_sec;    // Nota que supone en la segunda parte
} tInfoTema;



/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/

bool esValida(float tiempo_disponible, int& sumaTiempo) {
	if (sumaTiempo <= tiempo_disponible)
		return true;
	else
		return false;
}

bool esSolucion(float& notaP1, float& notaP2) {
	if (notaP1 >= 5 && notaP2 >=5)
		return true;
	else
		return false;
	

}

void puntuacionMaxima(const tInfoTema info_temas[], unsigned int num_temas, float tiempo_disponible,
	int& sumaTiempo, unsigned int& k,unsigned int &i, float& notaP1, float& notaP2, float& mejorP) {
	
	//while (i < num_temas && k < num_temas) {
	if (k < num_temas) {
		sumaTiempo += info_temas[i].tiempo_req;
		notaP1 += info_temas[i].nota_prim;
		notaP2 += info_temas[i].nota_sec;
		if (esValida(tiempo_disponible, sumaTiempo)) {


			if (esSolucion(notaP1, notaP2)) {
				float solucion = (notaP1 + notaP2) / 2;
				if (solucion > mejorP)
					mejorP = solucion;
			}
			else {

				if (i < num_temas - 1) {
					i++;
					puntuacionMaxima(info_temas, num_temas, tiempo_disponible, sumaTiempo, k, i, notaP1, notaP2, mejorP);
				}
				else {
					k++;
					i = k;
					sumaTiempo = 0;
					notaP1 = 0;
					notaP2 = 0;
					puntuacionMaxima(info_temas, num_temas, tiempo_disponible, sumaTiempo, k, i, notaP1, notaP2, mejorP);
				}
				//sumaTiempo -= info_temas[i].tiempo_req;
				//notaP1 -= info_temas[i].nota_prim;
				//notaP2 -= info_temas[i].nota_sec;
			}
		}
		else {
			sumaTiempo -= info_temas[i].tiempo_req;
			notaP1 -= info_temas[i].nota_prim;
			notaP2 -= info_temas[i].nota_sec;

			if (i < num_temas - 1) {
				i++;
				puntuacionMaxima(info_temas, num_temas, tiempo_disponible, sumaTiempo, k, i, notaP1, notaP2, mejorP);

			}
			else {
				k++;
				i = k;
				sumaTiempo = 0;
				notaP1 = 0;
				notaP2 = 0;
				puntuacionMaxima(info_temas, num_temas, tiempo_disponible, sumaTiempo, k, i, notaP1, notaP2, mejorP);
			}
		}

	}

}

float mejor_puntuacion(const tInfoTema info_temas[], unsigned int num_temas, float tiempo_disponible) {
	// Punto de entrada al algoritmo: a implementar
	int sumaTiempo = 0;
	//bool marcas[20] = { false };
	unsigned int k = 0;
	unsigned int i = 0;
	float punt1=0,punt2=0,mejorPunt=-1;
	puntuacionMaxima(info_temas, num_temas, tiempo_disponible, sumaTiempo, k, i, punt1, punt2, mejorPunt);
	return mejorPunt;

}



const unsigned int MAX_TEMAS = 20;


bool procesa_caso() {
	int num_temas;
	tInfoTema info_temas[MAX_TEMAS];
	cin >> num_temas;
	if (num_temas != -1) {
		float tiempo_disponible;
		cin >> tiempo_disponible;
		for (int i = 0; i < num_temas; i++) {
			cin >> info_temas[i].tiempo_req;
			cin >> info_temas[i].nota_prim;
			cin >> info_temas[i].nota_sec;
		}
		cout << mejor_puntuacion(info_temas, num_temas, tiempo_disponible) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (procesa_caso());
}