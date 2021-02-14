#include <iostream>
#include <string>
#include <math.h>
#include "Diretorio.h"


using namespace std;



Diretorio::Diretorio(int b,int m,int profundidadeGlobal,int profundidadeLocal,int numBaldes){
    this->profundidadeGlobal = profundidadeGlobal;
    this->profundidadeLocal = profundidadeLocal;
    this->bitsChave = b;
    this->tamBaldes = m;
    this->numBaldes = numBaldes;
    
    dir = new ElementosDir[pow(2, profundidadeGlobal)];
    
    
    Balde balde(m);
    numBaldes++;
    Balde balde2(m);
    numBaldes++;
    
    dir[0].elemento = "00";
    dir[0].ponteiro = &balde;
    
    dir[1].elemento = "01";
    dir[1].ponteiro = &balde;
    
    dir[2].elemento = "10";
    dir[2].ponteiro = &balde2;
    
    dir[3].elemento = "11";
    dir[3].ponteiro = &balde2;
    
}
        
Diretorio::~Diretorio(){
   
}

void Diretorio::setProfundidadeGlobal(int profundidadeGlobal){
    this->profundidadeGlobal = profundidadeGlobal;
}

int Diretorio::getProfundidadeGlobal(){
    return profundidadeGlobal;
}

int Diretorio::getBitsChave(){
    return bitsChave;
}
void Diretorio::setTamBaldes(int m){
    this->tamBaldes = m;
}

int Diretorio::getTamBaldes(){
    return tamBaldes;
}


//OPERAÇÕES OBRIGATORIAS
void Diretorio::inserir(string valor,Diretorio diretorio){
    //ACHAR QUAL BALDE A STRING RECEBIDA DEVERA SE ENCONTRAR
    for (int i = 0;i < pow(2, profundidadeGlobal);i++){
        if(dir[i].elemento == valor.substr(0,profundidadeGlobal)){ //identificar qual balde corresponde aos bits mais significativos
            if(dir[i].ponteiro->cheio() == true && dir[i].ponteiro->getProfundidadeLocal() < profundidadeGlobal){
                //balde cheio e a profundidade local menos do que a blobal
                
                Balde balde(tamBaldes);                                 //CRIAR NOVO BALDE
                balde.setProfundidadeLocal(1);                          //SET PROFUNDIDADE LOCAL DO NOVO BALDE
                dir[i].ponteiro->setProfundidadeLocal(1);               //SET PROFUNDIDADE LOCAL DO BALDE ANTIGO
                diretorio.numBaldes ++;                                 //AJUSTAR QUANTIDADE DE BALDES
                //AJUSTAR PONTEIROS
                //REDISTRIBUIR CHAVES
                //ADICIONAR ELEMENTO NO BALDE CORRETO
                break;                                                  //PARA EXECUCAO DESTA FUNCAO
            }
        }
        if(dir[i].ponteiro->cheio() == false && dir[i].ponteiro->getProfundidadeLocal() < profundidadeGlobal){
            //balde com espaco e profundidade local menor do que global
            
            dir[i].ponteiro->inserirBits(valor);                        //ADICIONAR ELEMENTO
            break;                                                      //PARA EXECUCAO DESTA FUNCAO
        }
        if(dir[i].ponteiro->cheio() == true && dir[i].ponteiro->getProfundidadeLocal() == profundidadeGlobal){
            //balde cheio e com profundidade local igual a global
            
            diretorio = duplicar(diretorio);                            //DUPLICA DIRETORIO,RETORNA UM DIRETORIO
            Balde balde(tamBaldes);                                     //CRIA UM NOVO BALDE
            balde.setProfundidadeLocal(profundidadeGlobal);             //SET PROFUNDIDADE LOCAL DO NOVO BALDE
            //AJUSTAR PONTEIROS DO BALDE NOVO NO DIRETORIO
            //REDISTRIBUIR AS CHAVES
            break;                                                       //PARA EXECUCAO DESTA FUNCAO
        }
        if(dir[i].ponteiro->cheio() == false && dir[i].ponteiro->getProfundidadeLocal() == profundidadeGlobal){
            //balde com espaco e profundidade local igual a global
            dir[i].ponteiro->inserirBits(valor);                        //ADICIONAR ELEMENTO
            
            break;                                                      //PARA EXECUCAO DESTA FUNCAO
        }
    }
}


bool Diretorio::buscar(string chave){
    for (int i = 0;i < pow(2, profundidadeGlobal);i++){                 //PERCORRENDO TODAS AS PSEUDO-CHAVES DO DIRETORIO
        if(dir[i].elemento == chave.substr(0,profundidadeGlobal)){      //ACHANDO A PSEUDO-CHAVE CORRESPONDENTE AO PRIMEIROS BITS DA CHAVE
            for(int j = 0;j < dir[i].ponteiro->getTamanhoBalde();j++){  //PERCORRER TODO O BALDE APONTADO PELA CHAVE ENCONTRADA
                if(chave == dir[i].ponteiro->vet[j]){                   //ENCONTRANDO A CHAVE DENTRO DO BALDE
                    return true;
                }
            }
        }
    }
    return false;
}

Diretorio Diretorio::duplicar(Diretorio diretorio){
    Diretorio diretorioaux(diretorio.getBitsChave(),diretorio.getTamBaldes(),diretorio.getProfundidadeGlobal(),diretorio.profundidadeLocal,diretorio.numBaldes);
                                                                                 //CRIAR UM NOVO DIRETORIO AUXILIAR
    diretorioaux.setProfundidadeGlobal(diretorio.getProfundidadeGlobal() + 1);   //SET PROFUNDIDADE GLOBAL DO DIRETORIO AUX
    //PREENCHER CADA DIR[I].ELEMENTO COM O CORRESPONDENTE EM BINARIO (DIRETORIO AUXILIAR)
    //ACERTAR OS PONTEIROS DO DIRETORIO NOVO PARA O AUXILIAR

    return diretorioaux;                                                         //RETORNAR DIRETORIO AUX
}

 
