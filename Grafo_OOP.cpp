/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Objetivo:
    Implementar los algoritmos vistos en clase en un solo programa
    Se desea la utilizacion de Git y Github, asi como OOP.

Integrantes del equipo:
    -Angel Enrique Chavez Ponce
    -Daniela Moran
    -Diego Romo Muñoz
    -Maria Fernanda Barron
    -Noe Shaddai De Luna 
    -Jesus Alejandro Luevano

To Do List:                             Status
   -Grafo en matriz                     En progreso
   -Grafo en lista                      Sin Comenzar
   -Busqueda por anchura                Sin Comenzar
   -Busqueda por profundidad            Sin Comenzar
   -Grafo conexo                        Sin Comenzar
   -Djikstra                            Sin Comenzar
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <iostream>
#include <vector>
using namespace std;
//Tamaño del grafo como variable global
const int TAM = 10;

//Clase en al que encapsularemos las propiedades y metodos del objeto grafo
class Grafo {
    //PROPIEDADES
public:
    int grafo [TAM][TAM];

    Grafo() {
        //Constructor de la clase ... Por ahora no hace nada
    }

    ~Grafo() {
        //Destructor de la clase ... Por ahora no hace nada
    }

    //METODOS
    void capturarGrafo() {
        int opcion;
            do {
                cout << "~Capturando El Grafo~" << endl;
                cout << "1.-Agregar Arista" << endl;
                cout << "2.-Salir" << endl;
                fflush(stdin);
                cin >> opcion;
                switch (opcion) {
                case 1: {
                    int nodoInicio, nodoDestino;
                    cout << "Ingrese el nodo de inicio: ";
                    cin >> nodoInicio;
                    nodoInicio > 0 ? nodoInicio-- : nodoInicio = nodoInicio;
                    cout << "Ingrese el nodo de destino: ";
                    cin >> nodoDestino;
                    nodoDestino > 0 ? nodoDestino-- : nodoDestino = nodoDestino;
                    agregarArista(nodoInicio, nodoDestino);
                    break;
                    break;
                }
                case 2: {
                    cout << "Captura del grafo terminada" << endl;
                    fflush(stdin);
                    getchar();
                    break;
                }
                default: {
                    cout << "Opcion Invalida" << endl;
                    fflush(stdin);
                    getchar();
                    system("cls");
                    break;
                }
            }
        } while (opcion != 2);
    }

    void agregarArista(int nodoInicio, int nodoDestino) {
        system("cls");
        // Función para agregar una arista, toma como argumentos el nodo de inicio y el nodo de destino de la arista
        if (nodoInicio >= 0 && nodoInicio < TAM - 1 && nodoDestino >= 0 && nodoDestino < TAM - 1) {
            //Marcamos la conexion
            grafo[nodoInicio][nodoDestino] = 1;
        }
        else {
            cout << "Nodos de inicio o destino invalidos. La arista no se puede agregar." << endl;
            fflush(stdin);
            getchar();
            system("cls");
        }
    }

    void rellenarGrafo() {
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                grafo[i][j] = 0;
            }
        }
    }

    void imprimirGrafo() {
        cout << "Matriz de Adyacencia del Grafo:" << endl;
        for (int i = 0; i < TAM; ++i) {
            for (int j = 0; j < TAM; ++j) {
                cout << grafo[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main()
{
    Grafo grafo;
    //incializando el grafo en ceros
    grafo.rellenarGrafo();
    grafo.capturarGrafo();
    grafo.imprimirGrafo();
    fflush(stdin);
    getchar();
    return 0;
}