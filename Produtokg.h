#ifndef PRODUTOKG_H
#define PRODUTOKG_H

#include "Produto.h"

class ProdutoKG: public Produto{ //herança da classe produto
	protected:
		float pesoTotal; //  total em kg do produto
		float vendaKG; // peso restante do produto em kg
	public:
		ProdutoKG(string="",int=0,float=0.0, float=0.0,float=0.0);
		void setpesoTotal(float);
		float getpesoTotal()const;
		void  setvendaKG(float);
		float getvendaKG()const;
		float restante() const;
		void imprime() const;
};

#endif
