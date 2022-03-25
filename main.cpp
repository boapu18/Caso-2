
#include <iostream>
#include <chrono>
#include <ctime>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

/**
Caso #2 Analisis de Algoritmos
María Paula Bolaños Apú
2021026046
**/

int cont = 0;

void printArray(int *array, int n){
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << std::endl;
}

void insertionSort(int arr[], int n){
    clock_t t = clock();

	int i, current, j;
	int contSwap, contFor = 0;
	for (i = 1; i < n; i++){
		current = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > current){
			arr[j + 1] = arr[j];
			j = j - 1;
			contSwap++;
		}
		arr[j + 1] = current;
		contFor++;
	}

    t = clock() - t;
    cout << "Ticks: " << (t) << endl;
    cout << "Segundos: " << (float(t) / CLOCKS_PER_SEC) << endl;
	cout << "Contador For: " << contFor << endl;
	cout << "Contador Swap: " << contSwap << endl << endl;
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
            cont++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int partition_r(int arr[], int low, int high){
    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);
    cont++;
    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high, int random){
    cont++;
    if (low < high){
        int pi;
        if (random  = 1){
            pi = partition_r(arr, low, high);
        }else{
            pi = partition(arr, low, high);
        }
        quickSort(arr, low, pi - 1, random);
        quickSort(arr, pi + 1, high, random);
    }
}

int naiveSearch(string mainString, string pattern) {
   int patLen = pattern.size();
   int strLen = mainString.size();
   int total = 0;
   int ite = 0;

   for(int i = 0; i<=(strLen - patLen); i++) {
      ite++;
      int j;
      for(j = 0; j<patLen; j++) {//check for each character of pattern if it is matched
         ite++;
         if(mainString[i+j] != pattern[j])
            break;
      }

      if(j == patLen) {     //the pattern is found
         total++;
      }
   }
   cout << "Iteraciones: " << ite << endl;
   return total;
}

int main(){

    int arr1[1000];
    int arr2[2000];
    int arr3[3000];
    int arr4[4000];
    int arr5[5000];
    int arr6[6000];
    int arr7[7000];
    int arr8[8000];
    int arr9[9000];
    int arr10[10000];
    vector<int> tams = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    vector<int *> arrays = {arr1, arr2, arr3, arr4, arr5, arr6, arr7, arr8, arr9, arr10};
    int arrayNum = 10;
    for(int i = 0; i < arrayNum; i++){
        for(int j = tams[i] - 1; j > 0; j--)
            arrays[i][j] = rand()%954;
    }


    for(int i = 0; i < arrays.size(); i++){
        clock_t t = clock();
        cont = 0;
        quickSort(arrays[i], 0, tams[i], 1);
        t = clock() - t;
        cout << "Cantidad de elementos: " << tams[i] << endl;
        cout << "Ticks: " << (t) << endl;
        cout << "Segundos: " << (float(t) / CLOCKS_PER_SEC) << endl;
        cout << "Iteraciones: " << cont << endl;
    }

    cout << endl;
    cout << "Quick sort pivote fijo en medio (logaritmico):" << endl;


    for(int i = 0; i < arrays.size(); i++){
        clock_t t = clock();
        cont = 0;
        quickSort(arrays[i], 0, tams[i], 0);
        t = clock() - t;
        cout << "Cantidad de elementos: " << tams[i] << endl;
        cout << "Ticks: " << (t) << endl;
        cout << "Segundos: " << (float(t) / CLOCKS_PER_SEC) << endl;
        cout << "Iteraciones: " << cont << endl;
    }

    cout << endl;
    cout << "Insertion sort cuadratcico: " << endl;
    for(int i = 0; i < arrays.size(); i++){
        cout << "Cantidad de elementos: " << tams[i] << endl;
        insertionSort(arrays[i], tams[i]);
    }

    int x = 0;
    for(int i = 0; i < arrayNum; i++){
        for(int j = tams[i] - 1; j > 0; j--){
            arrays[i][j] = x;
            x++;
        }
    }

    cout << "Insertion sort lineal: " << endl;
    for(int i = 0; i < arrays.size(); i++){
        cout << "Cantidad de elementos: " << tams[i] << endl;
        insertionSort(arrays[i], tams[i]);
    }


    cout << "Ejemplo de free text lineal: " << endl;

    cout << "Con un patrón existente: " << endl;

    cout << "Cantidad de veces encontrado el patron : " << naiveSearch("Esto es una prueba para que la aplicación del proyecto me distinga las diferentes palabras según la línea en la que está Esa es la línea 2 Mientras que por otro lado esta es la línea 3 en la cual necesito meter cada línea con un getline en un string y luego ese string puedo separarlo en palabras las cuales pueden ir en una lista kvpair donde un elemento es el número de línea y lo otro la palabra. ", "la") << endl;

    cout << "Con un patrón inexistente: " << endl;

    cout << "Cantidad de veces encontrado el patron : " << naiveSearch("Esto es una prueba para que la aplicación del proyecto me distinga las diferentes palabras según la línea en la que está Esa es la línea 2 Mientras que por otro lado esta es la línea 3 en la cual necesito meter cada línea con un getline en un string y luego ese string puedo separarlo en palabras las cuales pueden ir en una lista kvpair donde un elemento es el número de línea y lo otro la palabra. ", "aaaaaa") << endl;

    return (0);

}

