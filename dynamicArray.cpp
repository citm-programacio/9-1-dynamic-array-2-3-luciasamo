// dynamicArray.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//    vector<int> arr;  // Dynamic array (vector in C++)
//    int number;
//
//    cout << "Enter numbers one by one. Type a non-number to stop.\n";
//
//    while (true) {
//        cout << "Enter a number: ";
//        cin >> number;
//
//        // If user enters a non-number, stop the loop
//        if (!cin) {
//            cout << "Exiting...\n";
//            break;
//        }
//
//        // Insert number into the array
//        arr.push_back(number);
//
//        // Sort the array to keep it in order
//        sort(arr.begin(), arr.end());
//
//        // Print the current array
//        cout << "Current array: [";
//        for (size_t i = 0; i < arr.size(); ++i) {
//            cout << arr[i];
//            if (i < arr.size() - 1) cout << ", ";
//        }
//        cout << "]\n";
//    }
//
//    return 0;
//}



#include <iostream>
using namespace std;

//// Función para ordenar el arreglo sin modificar el arreglo original, creando uno nuevo
//void sortArray(int*& arr, int size) {
//    // Crear un nuevo arreglo de la misma longitud
//    int* sortedArr = new int[size];
//
//    // Copiar los elementos del arreglo original al nuevo arreglo
//    for (int i = 0; i < size; ++i) {
//        sortedArr[i] = arr[i];
//    }
//
//    // Ordenar el nuevo arreglo utilizando el algoritmo de burbuja
//    for (int i = 0; i < size - 1; ++i) {
//        for (int j = 0; j < size - 1 - i; ++j) {
//            if (sortedArr[j] > sortedArr[j + 1]) {
//                // Intercambiar los elementos
//                int temp = sortedArr[j];
//                sortedArr[j] = sortedArr[j + 1];
//                sortedArr[j + 1] = temp;
//            }
//        }
//    }
//
//    // Liberar la memoria del arreglo original
//    delete[] arr;
//
//    // Reemplazar el arreglo original con el arreglo ordenado
//    arr = sortedArr;
//}

// Función para ordenar el arreglo con el algoritmo de burbuja (Bubble Sort)
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar arr[j] y arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int* arr = nullptr;  // Puntero para el arreglo dinámico
    int size = 0;        // Tamaño actual del arreglo
    int capacity = 0;    // Capacidad actual del arreglo
    int number;

    cout << "Introduce numeros uno por uno. Para salir, ingresa un valor no numerico.\n";

    while (true) {
        cout << "Introduce un numero: ";
        cin >> number;

        // Si el usuario ingresa un valor no numérico, termina el ciclo
        if (!cin) {
            cout << "Saliendo...\n";
            break;
        }

        // Si el tamaño actual alcanza la capacidad, redimensionamos el arreglo
        if (size == capacity) {
            capacity = capacity * 2;  // Duplica la capacidad
            int* newArr = new int[capacity];  // Nuevo arreglo con mayor capacidad

            // Copiar los elementos del arreglo viejo al nuevo
            for (int i = 0; i < size; ++i) {
                newArr[i] = arr[i];
            }

            delete[] arr;  // Liberamos la memoria del arreglo viejo
            arr = newArr;  // Ahora arr apunta al nuevo arreglo
        }

        // Insertamos el nuevo número
        arr[size] = number;
        size++;

        // Ordenamos el arreglo manualmente con el algoritmo burbuja
        bubbleSort(arr, size);

        // Imprimimos el arreglo actual
        cout << "Arreglo actual: [";
        for (int i = 0; i < size; ++i) {
            cout << arr[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]\n";
    }

    // Liberar la memoria antes de salir
    delete[] arr;

    return 0;
}


