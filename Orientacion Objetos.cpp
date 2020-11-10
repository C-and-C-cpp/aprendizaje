// Orientacion Objetos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class Persona {
public:
    string nombre;//cuando no se expresa nada se coloca como provado por defecto
    int edad;


public://defino publico si quiero cambiar el de defecto
    Persona() {  //evitar usar estos constructores vacios
        nombre = "No name";
        edad = -1;
    }
    Persona(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    }
    void decirHola() {
        cout << "hola" << this->nombre << endl;
    }
    ~Persona() {
        cout << "se llama al destructor" << endl;
    }
};

void cambiarNombre(Persona p) {//se crea un copia de pedro lo cambia y lo elimina automaticamnete es por ello para que se vea reflejado en el main se debe usar puntero
    p.nombre = "thanos";
    p.decirHola();

}
void cambiarNombrePuntero(Persona* p) {

    p->nombre = "Thanos";
    p->decirHola();
}

int main()
{
    Persona juan = Persona();
    Persona pedro = Persona("pedro", 45);

    Persona* maria = new Persona("Maria", 30);


    juan.decirHola();

    cambiarNombre(pedro);
    pedro.decirHola();

    delete maria;//aunque aqui no es tan necesario dado que ya hay un return que hace que termina el programa
    
    return 0; //elimina las variables creadas dentro de esta funcion
}

