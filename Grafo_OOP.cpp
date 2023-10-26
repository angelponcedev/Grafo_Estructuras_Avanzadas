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
   -Grafo en matriz                     Listo
   -Grafo en lista                      Listo
   -Busqueda por anchura                Sin Comenzar
   -Busqueda por profundidad            En progreso =] 
   -Grafo conexo                        Sin Comenzar
   -Djikstra                            Sin Comenzar
   -Prim                                En progreso
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <climits>

using namespace std;
//TamaÃ±o del grafo como variable global
const int TAM = 10;
int nodos = 0;
//funciones de dijkstra
int encontrarMinimaDistancia(int dist[], bool sptSet[]);
void imprimirCamino(int parent[], int destino);
void dijkstraproceso(int grafo[TAM][TAM], int origen, int destino);

void cuadros(int nodos, int grafo[TAM][TAM], char letras[]);
int minimoPeso(int clave[], bool conjuntoMST[]);

//Clase en al que encapsularemos las propiedades y metodos del objeto grafo
class Grafo {
    //PROPIEDADES
public:
    int grafo [TAM][TAM];
    int grafoPrim[TAM][TAM];
    int grafodijkstra [TAM][TAM];

    Grafo() {
        //Inicializando matrices en ceros
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                grafo[i][j] = 0;
                grafoPrim[i][j] = 0;
                grafodijkstra[i][j]=0;
            }
        }
    }

    ~Grafo() {
        //Destructor de la clase ... Por ahora no hace nada
    }

    //METODOS
    void capturarGrafo() {
        int opcion;
        int peso;
        do {
            system("cls");
            cout << "~Capturando El Grafo~" << std::endl;
            cout << "1.-Agregar Arista" << std::endl;
            cout << "2.-Salir" << std::endl;
            cin >> opcion;
            switch (opcion) {
                case 1: {
                    int nodoInicio, nodoDestino, peso;
                        cout << "Ingrese el nodo de inicio: ";
                        cin >> nodoInicio;
                    nodoInicio--;
                        cout << "Ingrese el nodo de destino: ";
                        cin >> nodoDestino;
                    nodoDestino--;
                        cout << "Ingrese el peso de la arista: ";
                        cin >> peso;
                    agregarArista(nodoInicio, nodoDestino, peso);
                    break;
                }

                case 2: {
                        cout << "Captura del grafo terminada" << endl;
                    break;
                }
                default: {
                        cout << "Opcion Invalida" << endl;
                    break;
                }
            }
        } while (opcion != 2);
    }

    void agregarArista(int nodoInicio, int nodoDestino, int peso) {
        if (nodoInicio >= 0 && nodoInicio < TAM && nodoDestino >= 0 && nodoDestino < TAM) {
            grafo[nodoInicio][nodoDestino] = 1;
            grafo[nodoDestino][nodoInicio] = 1;
            grafoPrim[nodoInicio][nodoDestino] = peso;
            grafoPrim[nodoDestino][nodoInicio] = peso; // Añadir también la arista inversa si es un grafo no dirigido
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
        cout<<"Presiones una tecla para salir"<<endl;
        fflush(stdin);
        getchar();
        system("cls");
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
		
	    list<int> profundo;
	    list<int>::iterator it;
	
	    stack<int> pila;
	    stack<int> copiaPila;
	
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

    vector<vector<int>> listaAdy() {
    	vector<vector<int>> listaAdyacencia(TAM);
        for (int i = 0; i < TAM; ++i) {
            for (int j = 0; j < TAM; ++j) {
                if (grafo[i][j] == 1) {
                    listaAdyacencia[i].push_back(j);
                }
            }
        }
        return listaAdyacencia;
	}

    void Prim() {
        int padre[TAM];
        int clave[TAM];
        bool conjuntoMST[TAM];

        for (int i = 0; i < TAM; i++) {
            clave[i] = INT_MAX;
            conjuntoMST[i] = false;
        }

        clave[0] = 0;
        padre[0] = -1;

        for (int contador = 0; contador < TAM - 1; contador++) {
            int u = minimoPeso(clave, conjuntoMST);
            conjuntoMST[u] = true;

            for (int v = 0; v < TAM; v++) {
                if (grafoPrim[u][v] && !conjuntoMST[v] && grafoPrim[u][v] < clave[v]) {
                    padre[v] = u;
                    clave[v] = grafoPrim[u][v];
                }
            }
        }

        for (int i = 1; i < TAM; i++) {
            cout << "Arista: " << padre[i] << " - " << i << " Peso: " << grafoPrim[i][padre[i]] << endl;
        }
    }

    //Djikstra
    void dijkstra()
    {
        int opc;
        cout << "Agrega el peso de las aristas"<< endl;
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                if (grafo[i][j]== 1 ){
                    cout << "Nodo "<<i+1<<" a nodo " <<j+1<< endl;
                    fflush(stdin);
                    cin >> grafodijkstra[i][j];
                }
                else{
                    fflush(stdin);
                    grafodijkstra[i][j]=0;
                }
            }
        }
        cout << "Mostrar matriz de adyacencia con pesos" << endl;
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                cout << grafodijkstra[i][j]<<"\t";
            }
            cout << endl;
        }
        //jala bien
        int origen = 1; // Nodo origen
        int destino = 9; // Nodo destino
        dijkstraproceso(grafodijkstra, origen, destino);
    }
};
//Djikstra
int encontrarMinimaDistancia(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < TAM; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
// Función para imprimir el camino más corto
void imprimirCamino(int parent[], int destino) {
    if (parent[destino] == -1) {
        cout<<destino;
        return;
    }
    imprimirCamino(parent, parent[destino]);
    cout<<" -> "<< destino;
}

// Función que implementa el algoritmo de Dijkstra para encontrar el camino más corto desde un nodo origen
void dijkstraproceso(int grafodijkstra[TAM][TAM], int origen, int destino) {
    int dist[TAM];     // Array para almacenar las distancias más cortas
    bool sptSet[TAM];   // Conjunto de vértices incluidos en el camino más corto
    int parent[TAM];   // Array para almacenar el camino más corto
    // Inicializar todas las distancias como infinito y sptSet[] como falso
    for (int i = 0; i < TAM; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }
    // La distancia al origen siempre es 0
    dist[origen] = 0;
    // Encuentra el camino más corto para todos los vértices
    for (int count = 0; count < TAM - 1; count++) {
        int u = encontrarMinimaDistancia(dist, sptSet);
        sptSet[u] = 1;
        for (int v = 0; v < TAM; v++) {
            if (!sptSet[v] && grafodijkstra[u][v] && dist[u] != INT_MAX && (dist[u] + grafodijkstra[u][v] < dist[v])) {
                dist[v] = dist[u] + grafodijkstra[u][v];
                parent[v] = u;
            }
        }
    }
    // Imprimir la solución
    cout<<"Distancia más corta desde el nodo "<< origen<< " hasta el nodo "<<destino << dist[destino]<<"\n";
    cout<<"Camino más corto: ";
    imprimirCamino(parent, destino);
    printf("\n");
}


//Para el algo de Prim
int minimoPeso(int clave[], bool conjuntoMST[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < TAM; v++) {
        if (!conjuntoMST[v] && clave[v] < min) {
            min = clave[v];
            min_index = v;
        }
    }
    return min_index;
}

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
    bool grafoCapturado = false;
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
                grafoCapturado= true;
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
    		case 6:
                if(grafoCapturado){
                    grafo.dijkstra();
                }
                else{
                    cout<<"Error: Grafo sin Pesos, capture los pesos del grafo en la Opcion 1"<<endl;
                    fflush(stdin);
                    getchar();
                }
                break;
    		case 7: break;
            case 8:
                if(grafoCapturado){
                    grafo.Prim();
                }
                else{
                    cout<<"Error: Grafo sin Pesos, capture los pesos del grafo en la Opcion 1"<<endl;
                    fflush(stdin);
                    getchar();
                }
                break;
    		case 9: break;
    		case 0:
                cout<<"Saliendo"<<endl;
                fflush(stdin);
                getchar();
                break;
    		default: break;
		}
	}while(opcion!=0);
    return 0;
}