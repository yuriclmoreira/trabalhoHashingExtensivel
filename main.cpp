
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include "Diretorio.h"
#define STRING(num) #num

using namespace std;


int gerar_binario(int k);

int main() {
    
    int m = 0;
    int b = 0;
    int n = 0;
    int opcao;
    
  

    cout<<"--------------------------------------------"<<endl;
    cout<<"|BEM VINDO A ATIVIDADE DE HASHING EXTENSIVEL|"<<endl;
    cout<<"--------------------------------------------"<<endl;
    
    cout<<endl<<"Digite o tamanho m que sera ultilizado nos baldes:";
    cin>>m;
    
    cout<<endl<<"Digite o numero de bits a ser usado para as pseudo-chaves:";
    cin>>b;
    
    Diretorio diretorio(b,m,1,sqrt(m),2);
    
    cout<<endl<<"Digite o numero de chaves n que seram inseridas: ";
    cin>>n;
    
    string vetor[n];
    
    cout<<endl<<"Digite uma das seguintes opcoes: "<<endl;
    cout<<"1)Inserções de N pseudo-chaves aleatórias."<<endl;
    cout<<"2)Inserções de N pseudo-chaves iniciadas com um mesmo padrão de bits."<<endl;
    cin>>opcao;
   

    switch (opcao)
    {
    case 1:
            for(int i = 0;i < n;i++){
                for(int j = 0;j < b;j++){
                    int aux = rand() % 2;
                    vetor[i] +=  to_string(aux);
                }
            }
        
               break;

    case 2:
            for(int i = 0;i < n;i++){
                for(int j = 0;j < b;j++){
                    if(j == 0) {
                        vetor[i] = "0";
                    }else {
                        int aux = rand() % 2;
                        vetor[i] += to_string(aux);
                    }
                    
                    
                }
            }
        break;
    default:
        cout << "Opcao invalida, digite o valor 1 ou 2:" << endl;
        return 0;
    }


    for (int i = 0;i < n;i++){
        diretorio.inserir(vetor[i], diretorio);
    }
    
   
    for (int i = 0;i < diretorio.getProfundidadeGlobal();i++){
        diretorio.dir[i].ponteiro->imprimirBalde();
    }

    
}
