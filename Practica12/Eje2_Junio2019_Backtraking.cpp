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

void mejor_puntuacion(
						// datos del problema
						const tInfoTema info_temas[],
						unsigned int num_temas, 
						float tiempo_disponible,
					
						// solucion parcial
						int k,
						// marcaje
						float notaP1,
						float notaP2,
						float tiempoAcumulado,
						float maxNotaP1,
						float maxNotaP2,
						// mejor solucion
						float &mejorSolucion
) {
	
	if (k == num_temas) {
		if ((notaP1 + notaP2) / 2 > mejorSolucion)
			mejorSolucion = (notaP1 + notaP2) / 2;

		return;
	}


	// opcion 1: me lo estudio
	if (tiempoAcumulado + info_temas[k].tiempo_req <= tiempo_disponible) {
		mejor_puntuacion(info_temas, num_temas, tiempo_disponible, k + 1, notaP1 + info_temas[k].nota_prim, notaP2 + info_temas[k].nota_sec, tiempoAcumulado + info_temas[k].tiempo_req,maxNotaP1,maxNotaP2, mejorSolucion);

	}

	// opcion 2: no me lo estudio
	if ((maxNotaP1 - info_temas[k].nota_prim >= 5) && (maxNotaP2 - info_temas[k].nota_sec >= 5)) {

		mejor_puntuacion(info_temas, num_temas, tiempo_disponible, k + 1, notaP1, notaP2 , tiempoAcumulado , maxNotaP1 - info_temas[k].nota_prim, maxNotaP2-info_temas[k].nota_sec, mejorSolucion);

	}
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
		float mejorSolucion = 0;
		mejor_puntuacion(info_temas, num_temas, tiempo_disponible, 0, 0, 0, 0.0, 10, 10, mejorSolucion);

		if(mejorSolucion == 0)
		cout << -1 << endl;
		else 
			cout << mejorSolucion << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (procesa_caso());
}

