// prueba C++.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream> 
#include <conio.h>
using namespace std;

int main()
{
    char Iniciales[] = { 'A','E','I','O','U'};
    
    char *name = new char[30];
    cout << "name: \n";
    cin.getline(name, 30, '\n');
    
    int aux=0;
    for (int i = 0; i <sizeof(name)+1; i++) {
        for (int p = 0; p < sizeof(Iniciales); p++) {
            if (toupper(name[i])==Iniciales[p]) {
                aux++;
                cout << name[i];
             
            }
        }
    }
    cout << " Numero de vocales= " << aux;

   // cout << "name is " << name;

    delete name;
    name = nullptr;

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
