struct NodoGrafo{
    char carBase;
    int valASCII;
    std::pair<int,int> key;

    NodoGrafo(std::pair<int,int> key,char c);
};

NodoGrafo::NodoGrafo(std::pair<int,int> pkey,char c){
    key=pkey;
    carBase = c;
    valASCII = int(c);
}