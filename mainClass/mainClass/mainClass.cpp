#include <iostream>
#include <vector>

class GrafoNoDirigido {
private:
    int numNodos;
    std::vector<std::vector<int>> matrizAdyacencia;

public:
    GrafoNoDirigido(int n) : numNodos(n) {
        matrizAdyacencia.resize(n, std::vector<int>(n, 0));
    }

    void agregarArista(int nodo1, int nodo2) {
        if (nodo1 >= 0 && nodo1 < numNodos && nodo2 >= 0 && nodo2 < numNodos) {
            matrizAdyacencia[nodo1][nodo2] = 1;
            matrizAdyacencia[nodo2][nodo1] = 1; // Grafo no dirigido, así que también agregamos la conexión en el otro sentido
        }
    }

    void imprimirMatrizAdyacencia() {
        std::cout << "Matriz de Adyacencia:" << std::endl;
        for (int i = 0; i < numNodos; i++) {
            for (int j = 0; j < numNodos; j++) {
                std::cout << matrizAdyacencia[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int numNodos = 4;
    GrafoNoDirigido grafo(numNodos);

    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 2);
    grafo.agregarArista(1, 3);

    grafo.imprimirMatrizAdyacencia();

    return 0;
}
