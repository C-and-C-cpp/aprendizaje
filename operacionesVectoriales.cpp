

#include <iostream>

using namespace std;

class Vector2d {
private:// opcional dado que viene por defecto el caracter privado en los atributos
    float values[2];

public:
    Vector2d() { //defino constructor vector2 vacio cuando no se le entregan parametros.
        values[0] = values[1] = 0;
    }
    Vector2d(float x, float y) { //constructor vector2 con parametros dados
        values[0] = x;
        values[1] = y;
    }
    float getX() {  // metodo para obtner eje x
        return values[0];
    }
    float getY() {  //metodo para obtener eje y
        return values[1];
    }
    Vector2d *SumarVectores(Vector2d* v) { //funcion dentro del opbjeto vector2d para el calculo de sumatoria vectorial,se hace uso de punteros
        return new Vector2d(v->values[0] + this->values[0], v->values[1] + this->values[1]); 
    }
    void mostrar() {
        cout << "x:" << values[0] << "\n y:" << values[1] << endl;
    }

    ~Vector2d() { //destructor que siempre debe ser definido dado que Cpp no lo hace automatico como java.
        cout << "Destroy vector"<< endl;
    }
};

int main()
{
    Vector2d *v1 = new Vector2d(1, 5);
    Vector2d* v2 = new Vector2d(1,5);
    v1->mostrar(); //flecha es como el punto en java para acceder a los metodos del vector en este caso
    v2->mostrar();

    Vector2d* v3 = v1->SumarVectores(v2);
    cout << "Suma vectorial";
    v3->mostrar();
    

    delete v1;
    delete v2;
    delete v3;

    return 0;
}
