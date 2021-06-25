// Arquivo destinado as sobrecargas utilizadas no projeto.

#include "ProdutoUnidade.h"

ofstream& operator << (ofstream& arquivo, ProdutoUnidade& Und){
	
	arquivo << endl <<Und.getNome()<<endl;
	arquivo << Und.getCodigo() << endl;
	arquivo << Und.getPreco() << endl;
	
	return arquivo;
}

// Sobrecarregando o operador de entrada >> para que possa ler um objeto inteiro de um arquivo.
ifstream& operator >> (ifstream& arquivo, ProdutoUnidade& Und){
	
	string nomeProduto;
	int codigo;
	float preco;
	
	getline(arquivo, nomeProduto);
	Und.setNome(nomeProduto);
	arquivo >> codigo;
	Und.setCodigo(codigo);
	arquivo >> preco;
	Und.setPreco(preco);
	
	return arquivo;
}
