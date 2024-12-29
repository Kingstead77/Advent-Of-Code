#include <iostream>
#include <vector>
std::vector<int> Left = {0};
std::vector<int> Right = {0};

using namespace std;

void cargarDatos(char* path){
    
    FILE* file = fopen(path, "r");
    if(file == NULL){
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    int i = 0;
    int a,b;
    while(fscanf(file, "%d %d", &a, &b) != EOF){
        Left.push_back(a);
        Right.push_back(b);
        i++;
    }
    fclose(file);
    return;
}

// Función para intercambiar dos elementos
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función de partición
int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high]; // Elegimos el último elemento como pivote
    int i = low - 1; // Índice del elemento más pequeño

    for (int j = low; j < high; j++) {
        if (vec[j] < pivot) { // Si el elemento actual es menor que el pivote
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}

// Función recursiva de Quick Sort
void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high); // Índice de partición

        // Ordenar recursivamente las dos mitades
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

void sortVector(vector<int>& vec) {
    quickSort(vec, 0, vec.size() - 1);
}

int addDiff(vector<int> A,vector<int> B){
    unsigned long long int sum = 0;
    int n = A.size();
    for (int i = 0; i < n; i++){
        sum += abs(A[i] - B[i]);
    }
    return sum;
}

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Falta el path del archivo");
        return 1;
    }
    char* path = argv[1];
    cargarDatos(path);
    sortVector(Left);
    sortVector(Right);
    cout << addDiff(Left, Right);
    return 0;
}