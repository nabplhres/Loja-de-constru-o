// Arquivo destinado as sobrecargas utilizadas no projeto.

#include "ProdutoKg.h"

ofstream& operator << (ofstream& arquivo, ProdutoKG& Kg){
	
	arquivo << endl<<Kg.getNome()<<endl;
	arquivo << Kg.getCodigo() << endl;
	arquivo << Kg.getPreco() << endl;
	
	return arquivo;
}

// Sobrecarregando o operador de entrada >> para que possa ler um objeto inteiro de um arquivo.
ifstream& operator >> (ifstream& arquivo, ProdutoKG& Kg){
	
	string nomeProduto;
	int codigo;
	float preco;
	
	getline(arquivo, nomeProduto);
	Kg.setNome(nomeProduto);
	arquivo >> codigo;
	Kg.setCodigo(codigo);
	arquivo >> preco;
	Kg.setPreco(preco);
	
	return arquivo;
}
