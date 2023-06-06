#include <iostream>

using namespace std;
///Prototipo de funcion
string twoSum(int[], int tamax, int target);

int main() {
    ///Generacion de vector prueba
    int vector1[10] = {3, 4, 7, 8, 12, 1, 2, 6, 9, 11};

    /// cout << "Dame el tamaño del arreglo:" << endl;

    /// Se genera la cadena para imprimir con el resultado del algoritmo
    string posibles = twoSum(vector1, 10, 17);

    /// Imprimimos dicha cadena
    cout << "Posibles parejas: " << posibles << endl;

    return 0;
}

/// Recibe el conjunto de elementos, el tamaño del arreglo y el objetivo
string twoSum(int analizame[], int tamax, int target) {
    ///Se genera una cedana que tendra todas las combinaciones posibles
    string resultado;

    /// Este primer for sera para recorrer todo el arreglo principal
    for(int i = 0; i <= tamax; i++) {
        /// Para hacer mas eficiente,
        /// revisaremos el objetivo menos el numero
        /// del arreglo en la posicion actual
        /// con el fin de revisar si ya existe ese elemento dentro
        /// si es asi, lo añadimos a la cadena resultado
        int possiblePareja = target - analizame[i];
        /// El segundo for es para revisar si el resulatado de la resta
        /// ya se encuentra en el arreglo principal
        for(int j = 0; j <= tamax; j++) {
            /// Se revisa si el resultado de la resta ya se encuentra
            if(analizame[j] == possiblePareja) {
                /// Si es asi, colocamos el resultado de la resta
                /// junto al elemento actual del arreglo del primer for
                resultado += to_string(possiblePareja) + ", " + to_string(analizame[i]) + " | ";
            }
        }
    }
    return resultado;
}
