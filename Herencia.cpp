// Herencia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
// Herencia implementacional no es una buena practica dado que busca cosas en comun entre clases, la que generalmente usaba en java.
//  Herenica multiple tiene el problema del diamante donde la ultima clase que heredo cosas de dos clases anteriores y estas a si vez de una clase base(superclase en java)
   // puede tener un metodo que las dos clases anteriores tienen y por lo tanto no se sabe bien de cual puede ser lo que llevaria a estar conciente instanciando las clases 
  // lo que no es una buena practica y para un caracter mas profesional no es recomendable.

#include <iostream>
#include<string>

using namespace std;
class Animal {
public:
    Animal() {
        std::cout << "constructore Animal\n";
    }
    virtual void eat(){ // virtual me dice que mas abajo alguien lo va a redifinir y si sucede usa ese metodo, sin el virtual solo usa el de aca en palabras simples
       cout << "i am eating generic food" << endl;
    }
    virtual void sleep() = 0;//forma de difinir una clase abstracta en c++ dado que este debe ser implementado mas abajo

};

class Gato : public Animal {

public: 
    Gato() {
        cout << "constructor gato" << endl;
    }
    void eat() {  
       cout << "i am eating a mouse" << endl;
    }
    void sleep() {
        cout << "I am sleeping" << endl;
    }

};


void eat(Animal* gato) {
    gato->eat();
}

int main()
{
    //Animal* animal = new Animal(); // si yo hago abstracta la clase animal y no lo implemente en las clases derivadas(sub clase en java) no se puede instanciar gato, y animal como ya es abstarcta no se puede instanciar.
    Gato* gato = new Gato();

    eat(gato);



    //delete animal;
    delete gato;
}

//