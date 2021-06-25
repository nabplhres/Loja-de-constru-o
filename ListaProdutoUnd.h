#ifndef LISTAUNIDADE_H
#define LISTAUNIDADE_H


#include "Produtounidade.h"

class ListaUnidade:public ProdutoUnidade
{
	private:
		vector<ProdutoUnidade> lista_Und;

	public:
		ListaUnidade();
		~ListaUnidade();
		bool inserirProdutoUnidade(ProdutoUnidade);
		bool salvarListaUnidade();
		bool pesquisarPorNome(string) const;
		bool pesquisarPorCodigo(int) const;
		bool removerProdutoUnidade(string, float);
		void imprimirLista() const;
		void imprimirListaOrdenada() const;
};

#endif
