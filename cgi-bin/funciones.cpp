#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
    // Obtener la cadena de consulta
    const char* query_string = getenv("QUERY_STRING");
    // Inicializar variable para el nombre
    char nombre[100] = ""; 

    if (query_string != nullptr) {
        // Parsear los parámetros
        char* param = strdup(query_string);  // Hacer una copia de la cadena de consulta
        char* token = strtok(param, "&");    // Separar los parámetros
        while (token != nullptr) {
            sscanf(token, "nombre=%s", nombre); // Parsear el nombre
            token = strtok(nullptr, "&"); // Continuar con el siguiente parámetro
        }
        free(param);  // Liberar la memoria
    }

    // Generar la respuesta personalizada
    cout << "Content-Type: text/plain\n\n";
    cout << "Hola " << nombre;

    return 0;
}

