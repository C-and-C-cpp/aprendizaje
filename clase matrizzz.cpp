
#include <iostream>
#include<stdlib.h> //for new and delete
using namespace std;

class Matriz {
private:
    int** puntero_Matriz; // --->*puntero filas ----> [int][int]  puntero que apunta a una fila de punteros
    int Filas, Col;

public:
    Matriz(int nFilas, int nCol) {
        puntero_Matriz = new int* [nFilas]; // arreglo puntero con valores correspondientes a las filas
        for (int i = 0; i < nFilas; i++) {
            puntero_Matriz[i] = new int[nCol];  //accedemos a cada puntero de la fila y le asignamos una espacio dimamico de columna

        }
        Filas = nFilas;
        Col = nCol;
    }
    void rellenarMatrizAleatoria() {
        for (int i = 0; i < Filas; i++) {
            for (int j = 0; j < Col; j++) {
                puntero_Matriz[i][j] = rand() % 9;
            }
        }
    }
    void mostrarMatriz() {
        for (int i = 0; i < Filas; ++i) {
            for (int j = 0; j < Col; ++j) {
                cout <<puntero_Matriz[i][j]<<" "; //lo mismo que puntero_Matriz[i][j]
            }
            cout << "\n";
        }
    }
    Matriz* sumar(Matriz *matriz) {
        for (int i = 0; i < matriz->Filas; ++i) {
            for (int j = 0; j < matriz->Col; ++j) {
                matriz->puntero_Matriz[i][j] += this->puntero_Matriz[i][j];
            }
        }
        return matriz;
    }
    friend void showMatriz(Matriz* m);//no se debe usar aqui


    
    
    ~Matriz() {
        cout << "Destruyendo";

        for (int k = 0; k < Filas; k++) {  //liberar memoria de cada puntero de las filas
            delete[] puntero_Matriz[k];
        }
        delete[]puntero_Matriz;      //liber memoria de los punteros que apuntan hacia los punteros de filas.
    }
  

};
void showMatriz(Matriz* m) { // no ss recomienda usar ya que esta funcion tiene acceso a metodos de las clases lo que lo hace peligroso, se recomienda friebd void para clases que estan netamente relacionadas.
    for (int i = 0; i < m->Filas; ++i) {
        for (int j = 0; j<m->Col; ++j) {
            cout << m->puntero_Matriz[i][j] << " "; //lo mismo que puntero_Matriz[i][j]
        }
        cout << "\n";
    }

}
int main()
{   
    Matriz *matriz1 = new Matriz(5, 10); //tiene que ser tipo puntero para que se pueda acceder a sus metodos de la clase.
    Matriz* matriz2 = new Matriz(5, 10);

    matriz1->rellenarMatrizAleatoria();
    matriz2->rellenarMatrizAleatoria();

    cout << "Matriz 1 \n";  
    //matriz1->mostrarMatriz();
    showMatriz(matriz1);
    cout << "\nMatriz 2"<<endl;
    matriz2->mostrarMatriz();

    Matriz* matriz3 = matriz1->sumar(matriz2);

    cout << "\nMatriz 1 + Matriz 2 \n";
    matriz3->mostrarMatriz();

    cout << "\nEliminando matriz 1 y matriz 2"<<endl;
    delete matriz1, matriz2;
  
    return 0;
}