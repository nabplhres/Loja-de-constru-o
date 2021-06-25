#include "Produto.h"

Produto::Produto(string nomeProduto,int codigo, float preco){
	setNome(nomeProduto);
	setCodigo(codigo);
	setPreco(preco);
	
}
string Produto::getNome()const{
	return nomeProduto;
}
int Produto::getCodigo()const{
	return codigo;
}
float Produto::getPreco() const{
	return preco;
}
void Produto::setNome(string nomeProduto){
	this->nomeProduto=nomeProduto;
}
void Produto::setCodigo(int codigo){
	this->codigo=codigo;
}
void Produto::setPreco(float preco){
	this->preco=preco;
}
void Produto::imprime()const{
	cout<<"Produto: "<<getNome()<<endl;
	cout<<"Codigo: "<<getCodigo()<<endl;
	cout<<"Preco: "<<getPreco()<<endl;
}
