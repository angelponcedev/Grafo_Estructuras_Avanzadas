/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Objetivo:
    Implmentar los algoritmos vistos en clase en un solo programa
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
   -Busqueda por profundidad            En progreso =] 
   -Grafo conexo                        Sin Comenzar
   -Djikstra                            Sin Comenzar
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;
//TamaÃ±o del grafo como variable global
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
        // FunciÃ³n para agregar una arista, toma como argumentos el nodo de inicio y el nodo de destino de la arista
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
    
    void recorridoProfundidad() {
    	int i,j, temporal, inicial;
    	cout<<"Dame el nodo inicial: ";
    	cin>>inicial;
    	inicial=inicial-1;
    	vector<vector<int> >grafoP(TAM);
    	//Pasamos la matriz a lista de adyacencia
    	for(i=0;i<TAM;i++){
    		for(j=0;j<TAM;j++){
    			if(grafo[i][j]==1){
    				grafoP[i].push_back(j);
				}
			}
		}
		
		bool vali;
		
	    std::list<int> profundo;
	    std::list<int>::iterator it;
	
	    std::stack<int> pila;
	    std::stack<int> copiaPila;
	
	    pila.push(inicial);
	
	    while (!pila.empty()) {
	        temporal = pila.top(); // Temporal toma el primer valor de la pila
	        pila.pop();
	        profundo.push_back(temporal); // Le asignamos a profundo el valor de la pila
	
	        for (j = 0; j < grafoP[temporal].size(); j++) {
	            // Checamos si las conexiones no están repetidas
	            it = profundo.begin();
	            vali = true;
	            while (it != profundo.end()) {
	                if (*it == grafoP[temporal][j])
	                    vali = false;
	                ++it; // Avanzar al siguiente elemento
	            }
	            copiaPila = pila;
	            while (!copiaPila.empty() && vali) {
	                if (copiaPila.top() == grafoP[temporal][j])
	                    vali = false;
	                copiaPila.pop();
	            }
	            if (vali)
	                pila.push(grafoP[temporal][j]);
	        }
	    }
	    
	    cout<<endl<<"Elementos visitados en profundidad"<<endl;
	    
	    it = profundo.begin();
	    while (it != profundo.end()) {
	        cout <<*it+1<<endl;
	        ++it; // Avanzar al siguiente elemento
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
    grafo.recorridoProfundidad();
    fflush(stdin);
    getchar();
    return 0;
}
