#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Balde{
    private:
       
        
        int profundidadeLocal;
        int tamanhoBalde;
        int bitsChave;
    
    public:
        Balde(int tamanhoBalde);
        ~Balde();
        int getProfundidadeLocal();
        void setProfundidadeLocal(int num);
        int getTamanhoBalde();
        void imprimirBalde();
        
        void inserirBits(string bits);
        string *vet;
        bool cheio();
        void teste();
};



