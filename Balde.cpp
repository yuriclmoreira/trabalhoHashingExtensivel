#include <iostream>
#include <math.h>
#include "Balde.h"

using namespace std;

Balde::Balde(int tamanhoBalde){
    this->profundidadeLocal = 1;
    this->tamanhoBalde = tamanhoBalde;
    vet = new string[this->tamanhoBalde];
    for(int i = 0;i<tamanhoBalde;i++){
        vet[i] = "-";
    }
}
Balde::~Balde(){
    delete []vet;
}
int Balde::getProfundidadeLocal(){
    return this->profundidadeLocal;
}

void Balde::setProfundidadeLocal(int num){
    this->profundidadeLocal = num;
}

void Balde::inserirBits(string bits){
    for(int i = 0;i<tamanhoBalde;i++){
        if(vet[i] == "-"){
            vet[i] = bits;
            break;
        }
    }
}

bool Balde::cheio(){
    int cont = 0;
    for(int i = 0;i<tamanhoBalde;i++){
        if(vet[i] != "-"){
            cont++;
        }
    }
    if(cont == tamanhoBalde){
        return true;
    }else return false;
}

int Balde::getTamanhoBalde(){
    return this->tamanhoBalde;
}

void Balde::imprimirBalde(){
    for (int i = 0;i < pow(2, profundidadeLocal);i++){
        cout<<vet[i]<<" ";
    }
}
