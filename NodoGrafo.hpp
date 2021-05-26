struct NodoGrafo{
    char carBase;
    int valASCII;

    NodoGrafo(char c);
};

NodoGrafo::NodoGrafo(char c){
    carBase = c;
    valASCII = int(c);
}