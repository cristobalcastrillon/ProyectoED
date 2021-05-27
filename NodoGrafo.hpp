//INF: Infinito / número muy grande
#define INF 1000000

struct NodoGrafo{

    int posicionMatriz[2];
    char carBase;
    int valASCII;
    NodoGrafo * sup = NULL;
    NodoGrafo * inf = NULL;
    NodoGrafo * izq = NULL;
    NodoGrafo * der = NULL;

    int wSup = INF, wInf = INF, wIzq = INF, wDer = INF;

    NodoGrafo(char c, int i, int j){
        //Posicion en la matriz:
        //i: fila
        //j: columna
        posicionMatriz[0] = i;
        posicionMatriz[1] = j;
        carBase = c;
        valASCII = int(c);
    }
};