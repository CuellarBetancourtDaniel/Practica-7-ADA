#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string cadenaComprimida(const string& palabra) {
    string resultado;
    int n = palabra.length();

    for (int i = 0; i < n; ) {
        int j = i + 1;

        // Contar el número de repeticiones del carácter actual
        while (j < n && palabra[j] == palabra[i]) {
            ++j;
        }
        
        int cantidad = j - i;

        // Añadir la cantidad (hasta 9) y el carácter correspondiente al resultado
        while (cantidad > 0) {
            int x = min(9, cantidad);
            resultado += to_string(x);
            resultado += palabra[i];
            cantidad -= x;
        }

        i = j; // Avanzar a la siguiente secuencia de caracteres
    }

    return resultado;
}

int main() {
    // Ejemplo de entrada
    string palabra = "aaabbc";
    
    // Llamar a la función y mostrar el resultado
    string resultado = cadenaComprimida(palabra);
    cout << "Salida: \"" << resultado << "\"" << endl;

    return 0;
}
