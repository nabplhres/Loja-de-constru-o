#ifndef LISTAKG_H
#define LISTAKG_H

#include "ProdutoKG.h"

class ListaKG:public ProdutoKG 
{
	private:
		vector<ProdutoKG> lista_KG;

	public:
		ListaKG();
		~ListaKG();
		bool inserirProdutoKG(ProdutoKG);
		bool salvarListaKg();
		bool pesquisarPorNome(string) const;
		bool pesquisarPorCodigo(int) const;
		bool removerProdutoKG(string,float) ;
		void imprimirLista()const;
		void imprimirListaOrdenada () const;
};

#endif
