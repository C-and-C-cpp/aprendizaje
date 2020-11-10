// ListaEnlazada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Un TDA es la definicion semantica como funciona una estructura, (o esto va a funcionar como pila no te habla como esta implementado eso lo hace la estructura de datos(implementacion))

#include <iostream>
#include<string>

using namespace std;
// implementacion stack estatico con objetos
class Persona {
    string nombre;
    string rut;

    public:
        Persona() { //se usa cuando hay herencia 
        }
        Persona(string nombre, string rut) {
            this->nombre = nombre;
            this->rut = rut;
        }
        void show() {
            cout << "nombre:"<<nombre<< "\nrut:"<<rut<<endl;
        }
        ~Persona() {
            cout << "eliminando" << nombre << endl;
        }

};

class Stack {
private:
    Persona** persona;
    int size;
public:
    Stack(int max) {
        persona = new Persona*[max]; //SE RESERVA MEMORIA CON UN MAX DEFINIDO Y DE TIPU PUNTEROS PERSONA
        size = 0;
    }
    void push(Persona* p){
        this->persona[size++] = p;//

    }
    Persona* pop() {
        Persona* aux = persona[size - 1];
        size--;
        return aux;
    }


    void Show() {
        for (int i = 0; i < size; i++) {
            this->persona[i]->show(); //obtengo el objeto persona y uso el metodo show de la clase persona
        }
    }
    ~Stack(){
        cout << "Eliminado Stack" << endl;
        delete [] persona;
        cout << "Eliminando persona";
    }

};

int main()
{
    Stack* s = new Stack(100);

    s->push(new Persona("pedro", "20-3"));   // si quisiera implemtar una pila dentro de una pila se tendria que ingresar un stack en el costructor
    s->push(new Persona("pablo", "30-3"));
    s->push(new Persona("juan", "14-2"));

    Persona* p = s->pop(); //metodo elimina el ultimo

    delete p;
    delete s;

    return 0;

}





/*
int pop() {
    Nodo* aux = this->firts;

    //para asumir casos de que el primeros este vacio y retorno el que elimino
    if(this->firts->next==Null){
        int retorno=firts->elemento
        delete firts;
        firts=nullprt;
        return retorno;
    }
    //implementacion pop en lista enlazadas asumiendo que hay elementos en los arreglos

    while(aux->next->next!=Null){ //veo si el ultimo es Null pero lo que obtengo luego de salir del while es el penultimo
        aux=aux->next;
    }
    int retorno = aux->next->elemento;              //retorno el ultimo
    nodo *eliminar = aux->next;                      //guardamos el espacio de memoria correspondiente al ultimo para eliminarlo mas abajo
    aux->next = nullptr;                            //le digo al penultimo su siguente es nulo
    delete eliminar;                               // eliminamos ese espacio de memoria

    return retorno                     //retorna el elemento que elimina

 }*/