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
int nodos = 0;

void cuadros(int nodos, int grafo[TAM][TAM], char letras[]);

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
	    }while (opcion != 3);
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
	 void crearConexo(){
    	int ar, nodo1, nodo2, cont1, contB, temp;
        char letras[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
        int matAd[100][100], contN[50], ind[100], temMa[100][100], tempCon[50], diagonal[50];
        cout << "Dame la cantidad de nodos: ";
        cin >> nodos;
        cout << "Dame la cantidad de aristas: ";
        cin >> ar;
        for (int i = 0; i < ar; i++) {
            cout << "Valor de nodo 1: ";
            cin >> nodo1;
            cout << "Valor de nodo 2: ";
            cin >> nodo2;
            matAd[nodo1 - 1][nodo2 - 1] = 1;
        	}
	}

    void conexo() {
        char letras[TAM];
        for (int i = 0; i < TAM; i++) {
            letras[i] = 'A' + i;
        }
        cuadros(nodos, grafo, letras);
    }
};

void cuadros(int nodos, int grafo[TAM][TAM], char letras[]) {
    bool visited[TAM] = { false };
    printf("Componentes Conexas:\n");

    for (int i = 0; i < nodos; i++) {
        if (!visited[i]) {
            printf("V%d={%c", i + 1, letras[i]);
            visited[i] = true;

            for (int j = 0; j < nodos; j++) {
                if (grafo[i][j] && !visited[j]) {
                    printf(",%c", letras[j]);
                    visited[j] = true;
                }
            }
            printf("}\n");
        }
    }
}

int main()
{
	int opcion;
    Grafo grafo;
    //incializando el grafo en ceros
    do{
    	cout<<"Bienvenido :)"<<endl<<endl;
    	cout<<"(1)-Ingresar Grafo"<<endl;
    	cout<<"(2)-Lista de Adyacencia"<<endl;
    	cout<<"(3)-Busqueda por Anchura"<<endl;
    	cout<<"(4)-Busqueda por Profundidad"<<endl;
    	cout<<"(5)-Grafo Conexo"<<endl;
    	cout<<"(6)-Grafo Dijkstra"<<endl;
    	cout<<"(7)-Verificacion de Arbol"<<endl;
    	cout<<"(8)-Algoritmo de Prim/Kruskal"<<endl;
    	cout<<"(0)-Salir"<<endl;
    	cout<<endl<<"Ingrese su opcion: ";
    	cin>>opcion;
    	switch(opcion){
    		case 1:
				grafo.rellenarGrafo();
			    grafo.capturarGrafo();
			    grafo.imprimirGrafo();
				break;
    		case 2: break;
    		case 3: break;
    		case 4:
				grafo.recorridoProfundidad();
				break;
    		case 5:
				grafo.crearConexo();
                grafo.conexo();
				break;
    		case 6: break;
    		case 7: break;
    		case 8: break;
    		case 9: break;
    		case 0: break;
    		default: break;
		}
    	
	}while(opcion!=8);
    
    fflush(stdin);
    getchar();
    return 0;
}
