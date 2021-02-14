#include <iostream>
#include <math.h>
#include <vector>
#include "Balde.h"

using namespace std;

struct ElementosDir{
    string elemento;
    Balde *ponteiro;
};


class Diretorio{
    private:
        //Balde *vetor;
        int profundidadeGlobal;
        int bitsChave;
        int tamBaldes;
    
    public:
        Diretorio(int b,int m,int profundidadeGlobal,int profundidadeLocal,int numBaldes);
        ~Diretorio();
        
        void setProfundidadeGlobal(int profundidadeGlobal);
        int getProfundidadeGlobal();
        int getBitsChave();
        int numBaldes;
        int profundidadeLocal;
        void setTamBaldes(int m);
        int getTamBaldes();
    
        string bitsComparacao[1];
        ElementosDir *dir;
        void teste();
    
    
        //OPERAÇÕES OBRIGATORIAS
        void inserir(string valor,Diretorio diretorio);
        bool buscar(string chave);
        Diretorio duplicar(Diretorio diretorio);
  
    
};
