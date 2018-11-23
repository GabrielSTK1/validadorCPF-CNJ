#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void validaCPF (string &documento, int tamanho){
     int vetor[tamanho];
     int digito, contador, etapa, validador;
     etapa = 1;
     digito=0;
     contador=10;
     bool teste = false;
     for(int i = 0; i<tamanho; i++){
             char letra = documento[i];
             vetor[i] = atoi(&letra); 
     }
     
     
     //valida primeiro digito
     if(etapa ==1){
                        for(int i=0; i<tamanho-2; i++){
                                digito = digito + (vetor[i]* contador);        
                                contador--;
                        }            
 
     }  
    
           if(digito%11 <2){
                           validador = 0;
                           if(validador == vetor[tamanho-2]){
                                        etapa++;
                           }
           }
           else {
                validador = 11-(digito%11);  
                          if(validador == vetor[tamanho-2]){
                                        etapa++;
                           }         
           } 
    
 
     //apenas executa se primeiro digito for valido     
     if(etapa == 2){
              contador =11;
              digito=0;
              
                           for(int i =0; i<tamanho-1; i++){
                                  digito = digito + (vetor[i] * contador);
                                  contador--; 
                           }   
  
              if(digito%11 < 2){


                           validador =0;
                           if(validador == vetor[10]){
                                        
                                        teste = true;
                                        cout<<"CPF VALIDO"<<endl;
                           }
              }
              else{
                   
                   
                   validador = 11-(digito%11);
                           if(validador == vetor[10]){
                                        teste = true;
                                        cout<<"CPF VALIDO"<<endl;
              }   
              }      
     }
     if (teste == false){cout<<"CPF INVALIDO"<<endl;}
     
     
     
}


void validaCNPJ(string &documento, int tamanho){
     int vetor[tamanho];
     int digito, etapa, validador, contador;
     etapa =1;
     contador=2;
     digito = 0;
     bool teste = false;
     
     for(int i = 0; i<tamanho; i++){
             char letra = documento[i];
             vetor[i] = atoi(&letra); 
     }
     //valida primeiro digito
     if(etapa ==1){
              for(int i=11; i>=0; i--){
                      digito = digito + (vetor[i] * contador);
                      if(contador >=9){contador = 2;}
                      else{contador++;}
                      
                      
              }
              if(digito%11 <2){
                          validador =0;
                          if(validador == vetor[tamanho-2]){etapa++;}
              }
              else{
                   validador = 11-(digito%11);
                   if(validador == vetor[tamanho-2]){etapa++;}
              }
              
     }
     //valida segundo digito
     if(etapa==2){
                  
                  contador =2;
                  digito=0;
                  for(int i=12; i>=0; i--){
                          digito = digito + (vetor[i] * contador);
                          if(contador>=9){contador=2;}
                          else{contador++;}
                  }
                  if(digito%11 < 2){
                               validador =0;
                               if(validador == vetor[tamanho-1]){
                                            cout<<"CNPJ VALIDO"<<endl;
                                            teste = true;}
                  }             
                  
                  else{
                       validador = 11-(digito%11);
                       if(validador == vetor[tamanho-1]){
                                    cout<<"CNPJ VALIDO"<<endl;
                                    teste = true;
                       }
                  }
     }
     
     if(teste == false){cout<<"CNPJ INVALIDO"<<endl;}
     
     
     
}

int main (){
    
    string documento;
    int verificador =1;
    
    cout<<"Insira o CPF/CNPJ (APENAS NUMEROS)"<<endl;
    cin>>documento;
    
    
    

        if(documento.size()==11){
                                 for(int i=0; i<=9; i++){
                                         if(documento[i] == documento[i+1]){
                                            verificador++;             
                                         }
                                 }
                                 if(verificador ==11){cout<<"CPF INVALIDO"<<endl;}
                                 else{validaCPF(documento, documento.size()); }
        }
        
        else if(documento.size() == 14){
             for(int i=0; i<=13; i++){
                     if(documento[i] == documento[i+1]){
                                     verificador++;
                     }
             }
             
             if(verificador==14){cout<<"CNPJ INVALIDO"<<endl;}
             else{validaCNPJ(documento, documento.size());}
             
             
             
        }
    	
    	else {
			cout<<"Documento Inserido eh Invalido!!"<<endl;
		}
 
    
    
    system("PAUSE");    
    return 0;
}
