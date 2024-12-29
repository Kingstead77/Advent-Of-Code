#include <iostream>
#include <vector>
std::vector<int> Left = {0};
std::vector<int> Right = {0};

using namespace std;
//Declaracion de funciones
void cargarDatos(char* path);
void bubbleShort(vector<int> &A);
unsigned long long int buscadorRepeticiones(vector<int> A,vector<int> B);
std::pair<int, int> counter(vector<int> A, int n);
int searchBinary(vector<int> A, int n);




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

std::pair<int, int> counter(vector<int> A, int n){
    int count = 0;
    int index = searchBinary(A, n);
    if (index != -1) {
        for (int i = index; i < A.size() && A[i] == n; ++i) {
            count++;
        }
    }
    return std::make_pair(index, count);
}

unsigned long long int buscadorRepeticiones(vector<int> A,vector<int> B){
    unsigned long long int sum = 0;
    int n = A.size();
    int last = 0, lastValue = 0;
    for (int i = 0; i <n; i++){
        if (A[i] == last){//Al tener el vector ordenado, esto dota de una "memoria" para hacer la busqueda solo una vez
            sum += lastValue;
            continue;
        }
        std::pair<int, int> p = counter(B, A[i]);
        sum += (p.second*A[i]);
        last = A[i];
        lastValue = (p.second*A[i]);
    }
    return sum;
}
//esta funcion devuelve la primera posicion en la cual se encuentra el valor n del vector
//en caso de que no se encuentre, devuelve -1
//en caso de que haya mas de un valor igual, devuelve la primera posicion



int searchBinary(std::vector<int> data, int target) {
    int left = 0;
    int right = data.size() - 1;
    int mid = 0;

    while (left <= right) { // Busca el valor target en el vector data
        mid = left + (right - left) / 2;

        if (data[mid] == target) {
            while (true) { // Busca la primera posición en la que se encuentra el valor target
                if (mid == 0) {
                    return 0;
                } else if (data[mid - 1] != target) {
                    return mid;
                } else {
                    mid--;
                }
            }
        }

        if (data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}


int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Falta el path del archivo");
        return 1;
    }
    char* path = argv[1];
    cargarDatos(path);
    sortVector(Right);
    sortVector(Left);
    cout << buscadorRepeticiones(Left, Right);
    return 0;
}