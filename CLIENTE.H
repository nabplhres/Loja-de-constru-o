#ifndef CLIENTE_H
#define CLIENTE_H
#include<iostream>

using namespace std;

class Cliente{
      private:
              string nome;
              string endereco;
              string cpf;


      public:
             Cliente(string="", string="", string="");
             void setNome(string);
             string getNome();
             void setEndereco(string);
             string getEndereco();
             void setCPF(string);
             string getCPF();
             void Imprime();


};
#endif

