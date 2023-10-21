#include <iostream>
#include <vector>

using namespace std;

// Clase padre grafo
class Grafo {

    // Atributos
protected:
    int numNodos;
    vector<vector<int>> matrizAdyacencia;
    vector<vector<int>> listaAdyacencia;

    // Constructor
public:
    Grafo(int numNodos) : numNodos(numNodos) {

        //hacer que la matriz tenga n x n tamaño 
        matrizAdyacencia.resize(numNodos, vector<int>(numNodos, 0));

        //hacer que la lista tenga n tamaño
        listaAdyacencia.resize(numNodos);
    }

    void agregarArista(int nodoOrigen, int nodoDestino) {
        if (nodoOrigen >= 0 && nodoOrigen < numNodos && nodoDestino >= 0 && nodoDestino < numNodos) {
            matrizAdyacencia[nodoOrigen][nodoDestino] = 1;

            listaAdyacencia[nodoOrigen].push_back(nodoDestino);
        }
    }

    void imprimirMatrizAdyacencia() {
        cout << "MATRIZ DE ADYACENCIA" << endl<<endl;
        cout << "    ";
        for (int i = 0; i < numNodos; i++) {
            cout << i << " ";
        }cout << endl;
        for (int i = 0; i < numNodos; i++) {
            cout << endl;
            cout << i<<"   ";
            for (int j = 0; j < numNodos; j++) {
                cout << matrizAdyacencia[i][j] << " ";
            }
        }
        cout << endl;
        cout << endl;
    }

    void imprimirListaAdyacencia() {
        cout << "LISTA DE ADYACENCIA" << endl;
        for (int i = 0; i < numNodos; i++) {
            cout << i;
            for (int j = 0; j < listaAdyacencia[i].size(); j++) {
                cout <<" -> " << listaAdyacencia[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }


    void recorrerGrafoAnchura(int inicio)
    {
        cout << "RECORRIDO EN ANCHURA" << endl;
        //poner todos los nodos en "no visitado"
        vector<bool>visitados(numNodos, false);

        //crear cola
        vector<int> cola;

        //nodo actual
        int nodoActual;

        //paso 2: Meter el vertice de partida a la cola
        cola.push_back(inicio);
        //paso 3: Marcar como visitado el vertice
        visitados[inicio] = true;

        while (cola.empty() == false)
        {
            //paso 4 marcar el nodo del incio de la cola como actual
            nodoActual = cola[0];

            //imprimir el recorrido
            cout << nodoActual << " -> ";
            //sacar nodo de la cola
            cola.erase(cola.begin());
            //paso 5 meter los nodos adyacentes del nodo actual a la cola
            for (int i = 0; i < listaAdyacencia[nodoActual].size(); i++)
            {
                int nodoAdyacente = listaAdyacencia[nodoActual][i];
                //Comprobar que no se haya visitado antes el nodo adyacente
                if (visitados[nodoAdyacente] == false)
                {
                    cola.push_back(nodoAdyacente);
                    visitados[nodoAdyacente] = true;
                }
            }
        }
        cout << endl;
        cout << endl;
    }

    void recorrerGrafoProfundidad(int inicio) {
        cout << "RECORRIDO EN PROFUNDIDAD" << endl;
        //poner todos los nodos en "no visitado"
        vector<bool>visitados(numNodos, false);

        //crear cola
        vector<int> pila;

        //nodo actual
        int nodoActual;

        //paso 2: Meter el vertice de partida a la pila
        pila.push_back(inicio);
        //paso 3: Marcar como visitado el vertice
        visitados[inicio] = true;

        while (pila.empty() == false) {
            //paso 4 marcar el nodo del final de la pila como actual
            nodoActual = pila.back();

            //imprimir el recorrido
            cout << nodoActual << " -> ";
            //sacar el ultimo elemento de la pila
            pila.pop_back();
            //paso 5 meter los nodos adyacentes del nodo actual a la cola
            for (int i = 0; i < listaAdyacencia[nodoActual].size(); i++)
            {
                int nodoAdyacente = listaAdyacencia[nodoActual][i];
                //Comprobar que no se haya visitado antes el nodo adyacente
                if (visitados[nodoAdyacente] == false)
                {
                    pila.push_back(nodoAdyacente);
                    visitados[nodoAdyacente] = true;
                }
            }
        }
        cout << endl;
        cout << endl;
    }
};

// GRAFO DIRIGIDO
class GrafoDirigido : public Grafo {
    public:
        GrafoDirigido(int numNodos) : Grafo(numNodos) {}

        void agregarArista(int nodoOrigen, int nodoDestino) {
            Grafo::agregarArista(nodoOrigen, nodoDestino);
        }
};

// GRAFO NO DIRIGIDO
class GrafoNoDirigido : public Grafo {
    public:
        GrafoNoDirigido(int numNodos) : Grafo(numNodos) {}

        void agregarArista(int nodoA, int nodoB) {
            Grafo::agregarArista(nodoA, nodoB);
            Grafo::agregarArista(nodoB, nodoA);
        }
};

int main() {
    GrafoDirigido grafoDirigido(5);
    grafoDirigido.agregarArista(0, 1);
    grafoDirigido.agregarArista(0, 3);
    grafoDirigido.agregarArista(1, 2);
    grafoDirigido.agregarArista(1, 3);
    grafoDirigido.agregarArista(1, 4);
    grafoDirigido.agregarArista(3, 4);
    grafoDirigido.agregarArista(2, 4);
    grafoDirigido.agregarArista(4, 3);

    grafoDirigido.imprimirListaAdyacencia();
    grafoDirigido.imprimirMatrizAdyacencia();
    grafoDirigido.recorrerGrafoAnchura(0);
    grafoDirigido.recorrerGrafoProfundidad(0);

    cout << endl;
    return 0;
}

