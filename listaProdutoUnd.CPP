#include "ListaProdutoUnd.h"
#include "sobrecargaUnd.h"

ListaUnidade::ListaUnidade(){

	ProdutoUnidade Und;
	ifstream arquivo; //criando um arquivo para leitura
	arquivo.open("lista_de_produtosUnd.txt"); // Abrindo o arquivo de leiura

	if(arquivo.is_open()){ // verificando se o arquivo foi aberto

		while(!arquivo.eof()){
			arquivo.ignore();
			arquivo >> Und;
			lista_Und.push_back(Und);// Adicionando o objeto a lista.
		}
	}
	arquivo.close(); // Fechando o arquivo de leitura.
}

ListaUnidade::~ListaUnidade(){

	salvarListaUnidade(); // Salvando lista
}

bool ListaUnidade::inserirProdutoUnidade(ProdutoUnidade Und){

	for(unsigned i(0); i< lista_Und.size(); i++){

		// Verificando se já não existe um produto com esse codigo
		if(lista_Und[i].getCodigo() == Und.getCodigo())
			return false;
	}

	lista_Und.push_back(Und);
	return true;
}


bool ListaUnidade::salvarListaUnidade(){

	ofstream arquivo;
	arquivo.open("lista_de_produtosUnd.txt", std::ios::trunc);

	if(arquivo.is_open()){

		for(unsigned i(0); i < lista_Und.size(); i++){

			// gravando o produto no arquivo.
			arquivo << lista_Und[i];

		}
		return true;
	}
	else
		return false;

	arquivo.close();
}

bool ListaUnidade::pesquisarPorCodigo(int codigo) const{

	unsigned count(0);
	for(unsigned i(0); i < lista_Und.size(); i++){

		if(lista_Und[i].getCodigo() == codigo){

			lista_Und[i].imprime();
			return true;
		}
		else
			count++;
	}
	if(count == lista_Und.size())
		return false;
}
bool ListaUnidade::pesquisarPorNome(string nomeProduto) const{

	unsigned count(0);
	for(unsigned i(0); i < lista_Und.size(); i++){

		if(lista_Und[i].getNome() == nomeProduto){

			lista_Und[i].imprime();
			return true;
		}
		else
			count++;
	}
	if(count == lista_Und.size())
		return false;
}

bool ListaUnidade::removerProdutoUnidade(string nomeProduto, float quantidadeTotal)
{
	unsigned count(0);
	for(unsigned i(0); i < lista_Und.size(); i++)
	{
		if(lista_Und[i].getNome() == nomeProduto)
		{
			if(lista_Und[i].getQuantidadeVender()<= quantidadeTotal){
				int resp = lista_Und[i].getQuantidadeVender();
				lista_Und.erase(lista_Und.begin()+i);
				cout << " produto removido!"<< endl;
				return resp;
		}
		else{
			lista_Und[i].setQuantidadeVender(lista_Und[i].getQuantidadeVender() - quantidadeTotal);

                cout << "Produto removido parcialmente!" << endl;

                return quantidadeTotal;
			
		}
			
	}

	if(count == lista_Und.size())
		return false;
	}
}

void ListaUnidade::imprimirLista() const{

	for(unsigned i(0); i < lista_Und.size(); i++){

		cout<< i+1 << "° Produto Unidade: " << endl;
		lista_Und[i].imprime();
		cout << endl;
	}
}

void ListaUnidade::imprimirListaOrdenada() const{

	vector<string> aux(lista_Und.size());
	for(unsigned i(0); i < lista_Und.size(); i++){

		aux[i] = lista_Und[i].getNome();

	}
	sort(aux.begin(), aux.end());// Ordenado a lista auxiliar de produto em ordem alfabética.

	// impressão dos objetos
	unsigned contador(1);
	for(unsigned k(0); k < aux.size(); k++){

		for(unsigned i(0); i < lista_Und.size(); i++){

			if(aux[k] == lista_Und[i].getNome()){
				cout<< contador << "° Produto Unidade; " <<endl;
				lista_Und[i].imprime();
				cout << endl;
				contador++;
			}
		}
	}
}
