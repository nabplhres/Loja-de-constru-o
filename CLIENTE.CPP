#include "Cliente.h"

Cliente::Cliente(string nome,string endereco, string cpf){
    this->nome="";
	this->endereco="";
	this->cpf="";
}
void Cliente::setNome(string nome){
    this->nome=nome;
}
string Cliente::getNome(){
    return nome;
}
void Cliente::setEndereco(string endereco){
    this-> endereco= endereco;
}
string Cliente::getEndereco(){
    return endereco;
}
void Cliente::setCPF(string cpf ){
    this->cpf=cpf;
}
string Cliente::getCPF(){
    return cpf;
}

void Cliente::Imprime(){
    cout <<"Nome do cliente:" << getNome()<< endl;
    cout <<"Endereço do cliente:" << getEndereco()<< endl;
    cout <<"CPF do cliente:" << getCPF()<< endl;
}
