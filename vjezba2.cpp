#include <iostream>
#include <list>
#include <iomanip>
using namespace std;


struct kruznica {
	int x;
	int y;
	int radius;
};

struct vector {
	int* niz = new int[5];
	int logicka = 5;
	int fizicka;
};


// Sesti zadatak -> radi
vector* vector_new() {
	vector* vect = new vector();
	return vect;
}

void vector_delete(vector* vect) {
	free(vect);
}

void vector_push_back(vector* vect, int data) {
	if (vect->fizicka == vect->logicka) {
		int* temp = new int[2 * vect->logicka];

		// copying old array elements to new array 
		for (int i = 0; i < vect->logicka; i++) {
			temp[i] = vect->niz[i];
		}

		// deleting previous array 
		delete[] vect->niz;
		vect->logicka *= 2;
		vect->niz = temp;
	}

	// Inserting data 
	vect->niz[vect->fizicka] = data;
	vect->fizicka++;
}

int vector_pop_back(vector* vect) {
	int zadnji = vect->niz[(vect->fizicka) - 1];
	vect->fizicka--;
	return zadnji;
}

int vector_front(vector* vect) {
	return vect->niz[0];
}

int vector_back(vector* vect) {
	return vect->niz[(vect->fizicka) - 1];
}

int vector_size(vector* vect) {
	return vect->fizicka;
}

//------------------------------------------------------

// Prvi zadatak -> RADI
void vratiNajveciINajmanji(int niz[], int& najmanji, int& najveci, int size) {
	najmanji = niz[0];
	najveci = niz[0];
	for (int i = 1; i < size; i++) {
		if (najmanji > niz[i]) {
			najmanji = niz[i];
		}
		if (najveci < niz[i]) {
			najveci = niz[i];
		}
	}
}

// POMOCNA FUNKCIJA
// funkcija vraca dali se dva kruga sijeku
int presjeciKrugove(kruznica krug1, kruznica krug2) {
	int udaljenost_X = krug1.x - krug2.x;
	int udaljenost_Y = krug1.y - krug2.y;
	int sumaRadiusa = krug1.radius + krug2.radius;
	if ((udaljenost_X * udaljenost_X + udaljenost_Y * udaljenost_Y) < (sumaRadiusa * sumaRadiusa)) {
		return 1;
	}
	return 0;
}

// Drugi zadatak -> mislim da treba jos popravit dio sa const reference parametrima
int vratiPresjecanja(const kruznica &krug, const kruznica krugovi[], int size) {
	int c = 0;
	//int size = sizeof(krugovi) / sizeof(krugovi[0]);
	for (int i = 0; i < size; i++) {
		if (presjeciKrugove(krug, krugovi[i]) == 1) {
			c = c + 1;
		}
	}
	return c;
}

// Treci zadatak -> RADI
int& vratiUvecani(int niz[], int index) {
	return niz[index];
}

// Cetvrti zadatak -> RADI
int* vratiNiz(int n) {
	int* niz = new int[n];
	niz[0] = 1;
	niz[1] = 1;
	for (int i = 0; i < n; i++) {
		niz[i + 2] = niz[i] + niz[i + 1];
	}
	return niz;
}

// Peti zadatak -> RADI
void ispisiNiz() {
	int size = 10;
	int* niz = new int[size];
	int broj = 1;
	int i = 0;
	while (broj != 0) {
		cout << "Unesite broj " << endl;
		cin >> broj;
		niz[i] = broj;
		i++;
		if (i == size) {
			// ovde treba dinamicki prosirit memoriju za niz na duplo vise
			//realloc(niz, size*2);
			//size *= 2;
			int* temp = new int[2 * size];
			for (int i = 0; i < size; i++) {
				temp[i] = niz[i];
			}
			free(niz);
			size *= 2;
			niz = temp;
		}
	}
	for (int j = 0; j < i; j++) {
		cout << niz[j] << endl;
	}
	//free(niz);
}

int main()
{
	kruznica krug = {2, 2, 1};
	kruznica krugovi[] = { {3, 2, 1}, {7, 6, 8}, {9, 3, 2} , {7, 1, 2}, {3, 6, 4} };

	int sizeK = sizeof(krugovi) / sizeof(krugovi[0]);

	//vratiUvecani(brojevi, 5) += 1;

	vector* vect = vector_new();
	vector_push_back(vect, 5);
	vector_push_back(vect, 3);
	vector_push_back(vect, 4);
	vector_push_back(vect, 40);
	vector_push_back(vect, 35);
	vector_push_back(vect, 2);
	vector_push_back(vect, 8);
	vector_push_back(vect, 7);
	
}
