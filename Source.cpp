
#include <iostream>


using namespace std;

//Ejercicio 1
/*Define	un	tipo	Vector que	permita	representar	secuencias	de	N	enteros	e	implementa,	además	
de	subprogramas	para	leer	y	mostrar	un	vector:
1 Un	subprograma	que,	dado	un	vector,	mueva	sus	componentes	un	lugar	a	la	derecha.	El	
último	componente	se	moverá	al	1er lugar.
2 Un	subprograma	que,	dado	un	vector,	calcule	y	devuelva	la	suma	de	los	elementos	que	
se	encuentran	en	las	posiciones	pares	del	vector.
3 Un	 subprograma	 que,	 dado	 un	 vector,	 encuentre	 y	 devuelva	 la	 componente	 de	 mayor	
valor.
4 Un	subprograma	que,	dados	dos	vectores,	devuelva	un	valor	que	indique	si	son	iguales.
5 Un	subprograma	que	obtenga	si	alguno	de	los	valores	almacenados	en	el	vector	es	igual	
a	la	suma	del	resto	de	los	valores	del	mismo.
6 Un	 subprograma	 que	 obtenga	 si	 alguno	 de	 los	 valores	 almacenados	 en	 el	 vector	 está	
repetido.*/


void escribeArray(int arr [], int size) {
	for (int x = 0; x < size; x++) {
		cout << arr[x] << " ";
	}
	cout << "\n";
}

void subprograma1(int nums [] , int size) {

	int act, ant;

	ant = nums[0];


	//act es acutual y guyarda al principio de cada vuelta del bucle el número del que se encuentra
	//ant guarda el número del anterior, al finalizar cada vuelta del bucle se hace que el anterioir sea el que era el actual
	for (int x = 0; x < size - 1; x++) {
		
		act = nums[x + 1];
		nums[x + 1] = ant;
		ant = act;

	}

	nums[0] = ant;
}

int subprograma2(int nums[], int size) {

	int sumaPares = 0;
	for (int x = 0; x < size; x += 2) {
		sumaPares += nums[x];
	}

	return sumaPares;

}


int subprograma3(int nums[], int size) {
	int mayor = 0;
	
	for (int x = 0; x < size; x++) {

		if (nums[x] > mayor)mayor = nums[x];
	}


	return mayor;
}


bool subprograma4(int nums[], int nums2[], int tam, int tam2) {

	bool iguales = true;


	if (tam != tam2) iguales = false;

	if (iguales) {
		int x = 0;
		while ( iguales && x < tam ) {

			if (nums[x] != nums2[x]) iguales = false;

			x++;
		}
	}

	return iguales;
}



bool subprograma5(int nums[], int size) {
	
	bool igualSuma = false;

	int x = 0;

	while (!igualSuma && x < size) {
		int suma = 0;

		for (int y = 0; y < size; y++) {
			if (y != x) suma += nums[y];
		}

		if (nums[x] == suma) igualSuma = true;
		x++;
	}

	return igualSuma;

}

bool subprograma6(int nums[], int size) {
	bool repetido = false;
	int x = 0;

	while (!repetido && x < size) {

		int  y = x+1;
		while (!repetido && y < size) {

			if (nums[x] == nums[y]) repetido = true;
			y++;
		}
		x++;
	}

	return repetido;
}

int main1() {
	
	int nums[5] = { 10, 11, 12, 13, 14 };
	int nums2[6] = { 10, 11,12, 13, 14, 15 };
	
	//lo que ocupa el array entero / lo que ocupa un elemento de él
	//no existe nums.tam
	int tam = sizeof(nums) / sizeof(sizeof(nums[0]));
	int tam2 = sizeof(nums2) / sizeof(sizeof(nums2[0]));
	escribeArray(nums, tam);

	

	//subprograma1(nums, tam)
	//cout << "Suma: " << subprograma2(nums, tam) << "\n" ;
	//cout << "Mayor: " << subprograma3(nums, tam) << "\n" ;
	
	//cout << "Iguales? "; if (subprograma4(nums, nums2, tam, tam2) == 1) cout << "true" << "\n"; else cout << "false" << "\n";
	//cout << "Iguales a la suma de los demás? "; if (subprograma5(nums, tam) == 1) cout << "true" << "\n"; else cout << "false" << "\n";
	cout << "Repetidos? "; if (subprograma6(nums, tam) == 1) cout << "true" << "\n"; else cout << "false" << "\n";
	
	escribeArray(nums, tam);
	
	
	return 0;
}



//Ejercicio 2
/*
2. Dado	 un	 array de	 N	 caracteres	 v1,	 en	 el	 que	 no	 hay	 elementos	 repetidos,	 y	 otro	 array de	M
caracteres	 v2,	 donde	 N	 ≤	 M,	 se	 quiere	 comprobar	 si	 todos	 los	 elementos	 del	 array	 v1	 están
también	en	el	array v2.	Por	ejemplo,	si:
v1	= ‘a’ ‘h’ ‘i’ ‘m’
v2	= ‘h’ ‘a’ ‘x’ ‘x’ ‘m’ ‘i’
El	resultado	sería	cierto,	ya	que	todos	los	elementos	de	v1 están	en	v2.
*/



bool v1Cv2(const char v1[], int tam1, const char v2[],int tam2) {

	
	//HAy dos bool, cada uno es para controlar cada bucle, al final del bucle inerno se le comiunica al bool externo cual es el resultado del bool interno
	//así, si no se encuentra a la primera no se sigue buscando
	//Se puede hacer con un solo bool
	bool contenido = true;
	int x = 0;
	while (x < tam1 && contenido) {
		int y = 0;
		bool estaDentro = false;
		while (y < tam2 && !estaDentro) {

			if (v1[x] == v2[y]) estaDentro = true;
			y++;
		}

		contenido = estaDentro;
		x++;
	}

	return contenido;
}

/*Se deberia poner así en vez de con lo de sizeof
	const int  tam1 = 5;
	const int  tam1 = 6;
*/

int main2() {

	char v1[5] = { 'a' , 'b', 'c', 'd', 'f' };
	char v2[6] = { 'b', 'c', 'd', 'e', 'f', 'a' };

	int tam1, tam2;
	tam1 = sizeof(v1) / sizeof(v1[0]);
	tam2 = sizeof(v2) / sizeof(v2[0]);

	bool contenido = v1Cv2(v1,tam1, v2, tam2);
	if (contenido) cout << "Esta contenido";
	else cout << "NO esta contenido";

	return 0;
}

//Ejercicio 4
/*
4. Escribe	un	programa	que	lea	dos	cadenas	del	teclado	y	determine	si	una	es	un	anagrama	de	la
otra,	es	decir,	si	una	cadena	es	una	permutación	de	los	caracteres	de	la	otra.	Por	ejemplo,	“acre”
es	 un	anagrama	 de	 “cera”	y	 de	 “arce”.	 Ten	en	 cuenta	 que	 puede	 haber	letras	 repetidas	en	la
cadena	(“carro”,	“llave”)
*/


#include <string>


bool Anagrama(const string& palabra1 , const string& palabra2) {


	//HAy dos bool, cada uno es para controlar cada bucle, al final del bucle inerno se le comiunica al bool externo cual es el resultado del bool interno
	//así, si no se encuentra a la primera no se sigue buscando
	//Se puede hacer con un solo


	int tam1 = palabra1.length();
	int tam2 = palabra2.length();
	
	bool contenido = true;
	if (tam1 == tam2) {
		int x = 0;
		while (x < tam1 && contenido) {
			int y = 0;
			bool estaDentro = false;
			while (y < tam2 && !estaDentro) {

				if (palabra1[x] == palabra2[y]) estaDentro = true;
				y++;
			}

			contenido = estaDentro;
			x++;
		}
	}
	else contenido = false;
	

	return contenido;
}

int main4() {
	string palabra1, palabra2;
	cout << "Escribir palabra 1 \n";
	cin >> palabra1;

	cout << "Escribir palabra 2 \n";
	cin >> palabra2;

	bool anagrama = Anagrama(palabra1, palabra2);
	if (anagrama) cout << "Es un anagrama";
	else cout << "NO es un anagrama";

	return 0;
}


// Ejercicio 5
/*
5. Escribe	un	programa	que	lea	del	teclado	una	frase	y	a	continuación	visualice	las	palabras	de	la
frase	en	 columna,	 seguida	 cada	 una	 del	 número	 de	letras	 que	la	 componen.	 Implementa	 tres
versiones	diferentes:
- Sin	utilizar	ningún	string,	simplemente	procesando la	entrada	carácter	a	carácter	hasta
el	final	(con	cin.get()).
- Leyendo	la	entrada	palabra	a	palabra	con	el	extractor	de	cadenas.
- Leyendo	la	frase	de	una	vez	con	getline(cin,frase) y	luego	procesando	el	string
*/


void cinGet() {
	char frase[100];

	cin.get(frase, 100);

	bool punto = false;
	int x = 0;
	while (!punto && x < 100) {
		if (frase[x] == ' ')  cout << "\n";
		
		else {
			if (frase[x] == '.') punto = true;
			cout << frase[x];
			
		}
		
		x++;
	}
	cout << "\n";
	
}

void extractor() {
	
	string frase = "";
	string palabra;
	bool parar = false;
	while (!parar) {
		cin >> palabra;
		frase = frase + palabra;
		if (frase[frase.size() - 1] == '.') parar = true;
		frase = frase + " ";
	}
	/* No vale, no detecta los espacios
	string frase = "";
	string palabra;
	bool parar = false;
	while (!parar) {
		cin >> palabra;
		frase = frase + palabra;
		if (palabra[0] == ' ') parar = true;
		frase = frase + " ";
	}
	*/
	

	

	for (int x = 0; x < frase.size(); x++) {
		if (frase[x] == ' ')cout << "\n";
		else cout << frase[x];
	}
}

void getLineMeth() {
	string frase;
	getline(cin, frase);

	for (int x = 0; x < frase.size(); x++) {
		if (frase[x] == ' ')cout << "\n";
		else cout << frase[x];
	}

}

int main5() {

	//cinGet();
	 extractor();
	//getLineMeth();

	return 0;
}


int main() {

	main5();


	system("pause");
}