#include "ListaKG.h"
#include "sobrecargaKg.h"

ListaKG::ListaKG()
{
	ProdutoKG produtoKG;
	ifstream arquivo; // Criando um arquivo apenas para leitura.
	arquivo.open("Lista_de_produtoKG.txt"); // Abrindo o arquivo de leitura.

	if(arquivo.is_open()) // Verificando se o arquivo foi aberto.
	{
		while(!arquivo.eof()) // Enquanto for diferente de eof(end of file) continue se repetindo.
		{
			arquivo.ignore(); // Ignorando o caractere de quebra de linha que está no início de cada objeto.
			arquivo >> produtoKG; // Utilizando a sobrecarga do operador >> para inicializar o objeto.
			lista_KG.push_back(produtoKG); // Adicionando o objeto a lista.
		}
	}
	arquivo.close(); // Fechando o arquivo de leitura.
}

ListaKG::~ListaKG()
{
	salvarListaKg(); // Salvando lista caso o usuário não se lembre de salvar.
}

bool ListaKG::inserirProdutoKG(ProdutoKG produtoKG)
{
	for(unsigned i(0); i < lista_KG.size(); i++)
	{
		// Verificando se já não existe o produto na lista
		if(lista_KG[i].getCodigo() == produtoKG.getCodigo())
			return false;
	}

	lista_KG.push_back(produtoKG);
	return true;
}

bool ListaKG::salvarListaKg()
{
	ofstream arquivo; // Criando um arquivo para salvar a lista de objetos.

	arquivo.open("Lista_de_produtoKG.txt", std::ios::trunc);

	if(arquivo.is_open())
	{
		for(unsigned i(0); i < lista_KG.size(); i++)
		{
			// Utilizando a sobrecarga do operador << para gravar o objeto no arquivo.
			arquivo << lista_KG[i];
		}
		return true;
	}
	else
		return false;

	arquivo.close();
}

bool ListaKG::pesquisarPorCodigo(int codigo) const{

	unsigned count(0);
	for(unsigned i(0); i < lista_KG.size(); i++){

		if(lista_KG[i].getCodigo() == codigo){

			lista_KG[i].imprime();
			return true;
		}
		else
			count++;
	}
	if(count == lista_KG.size())
		return false;
}

bool ListaKG::pesquisarPorNome(string nomeProduto) const{

	unsigned count(0);
	for(unsigned i(0); i < lista_KG.size(); i++)
	{
		if(lista_KG[i].getNome() == nomeProduto)
		{
			lista_KG[i].imprime();
			return true;
		}
		else
			count++;
	}
	if(count == lista_KG.size())
		return false;
}

bool ListaKG::removerProdutoKG(string nomeProduto, float pesoTotal)
{	
	for(unsigned i(0); i < lista_KG.size(); i++)
	{
		if(lista_KG[i].getNome() == nomeProduto && lista_KG[i].getvendaKG() > pesoTotal){
			lista_KG[i].setvendaKG(lista_KG[i].getvendaKG() - pesoTotal);

                cout << "Produto removido parcialmente!" << endl;

                return restante();
			
		}
		else if(lista_KG[i].getNome() == nomeProduto && lista_KG[i].getvendaKG() <= pesoTotal){
			int resp = lista_KG[i].getvendaKG();
				lista_KG.erase(lista_KG.begin()+i);
				cout << " produto removido!"<< endl;
				return resp;
		}
	}
}

void ListaKG::imprimirLista() const{
	
	for(unsigned i(0); i < lista_KG.size(); i++)
	{
		cout << i+1 << "° Produto KG: " << endl;
		lista_KG[i].imprime();
		cout << endl;
	}
}

void ListaKG::imprimirListaOrdenada() const
{
	vector<string> aux(lista_KG.size());// Criando um vector auxiliar para armazenar todos os nomes da lista
	for(unsigned i(0); i < lista_KG.size(); i++)
	{
		aux[i] = lista_KG[i].getNome();
	}

	sort(aux.begin(), aux.end()); // Ordenado a lista auxiliar de nomes em ordem alfabética.

	// Forçando a impressão dos objetos na mesma ordem dos nomes do vector auxiliar.
	unsigned contador(1);
	for(unsigned k(0); k < aux.size(); k++)
	{
		for(unsigned i(0); i < lista_KG.size(); i++)
		{
			if(aux[k] == lista_KG[i].getNome())
			{
				cout << contador << "° Produto KG: " << endl;
				lista_KG[i].imprime();
				cout << endl;
				contador++;
			}
		}
	}
}
