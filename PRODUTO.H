#ifndef PRODUTO_H
#define PRODUTO_H
#include<iostream>

using namespace std;

class Produto{
	private:
		string nomeProduto;
		int codigo;
		float preco;
    public:
    	Produto(string="", int=0,float=0.0);
    	void setNome(string);
    	void setCodigo(int);
    	void setPreco(float);
    	string getNome()const;
    	int getCodigo()const;
    	float getPreco()const;
    	void imprime()const;
};
#endif
