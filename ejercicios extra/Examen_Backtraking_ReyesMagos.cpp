//REYES MAGOS- PROBLEMA OPTIMIZACIÓN


void asigna(
	//descripcion pronlema
	int numNinyos, int numJuguetes,
	int minJuguetesPorNinyo, 
	int edad[],  //edad niño
	int pegi[], //edad minima 
	int beneficio[MAX_NINYOS][MAX_J],

	//Solucion parcial
	//int asignados[],
	int k,
	int satisfaccionParcial,
	int numAsignados[], //juguetes asignados para el niño i


	//marcaje 
	int faltanParaMinimo, //Usado para descartar una solucion en caso de que tenga 
						  //menos juguetes que juguetes me faltan para que cada niño 
						  //tenga el minimo numero de juguetes

	//mejor solucion
	int &maxSatisfaccion
) {

	if (k == numJuguetes) {
		if (satisfaccionParcial > maxSatisfaccion)
			maxSatisfaccion = satisfaccionParcial;

		return;
	}

	//CASO RECURSIVO
	//DECIDIR A QUE NIÑO LE DOY EL JUGUETE (BUCLE)
	
	for (int i = 0; i < numNinyos; i++) {//Asignamos el juguete k a cada niño posible
		//COMPROBAR LA EDAD MINIMA DEL NIÑO
		//Asignar el juguet k al niño i, ¿Es prometedora?

		if (pegi[k] > edad[i])
			continue;  //salta a la siguiente vuelta

		/*Si le doy al niño i un juguete mas,
		¿podrán el resto de niños llegar al mínimo número de juguetes?
		*/

		if (numAsignados[i] >= minJuguetesPorNinyo && 
			(faltanParaMinimo > numJuguetes - k + 1) //pensar el + 1
			) {
			continue;
		}

		//Solucion prometedora Asignamos
		if (numAsignados[i] < minJuguetesPorNinyo)
			faltanParaMinimo--;
				
		numAsignados[i]++;

		//LLamamos recursivamente
		asigna(numNinyos, numJuguetes, minJuguetesPorNinyo, edad, pegi, beneficio, k + 1, satisfaccionParcial + beneficio[i][k],
			numAsignados, faltanParaMinimo, maxSatisfaccion);

		//Deshacemos la asignacion

		numAsignados[i]--;
		if (numAsignados[i] > minJuguetesPorNinyo)//Pensar si < o >=
			faltanParaMinimo++;

	}

}