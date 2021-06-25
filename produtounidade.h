#ifndef PRODUTOUNIDADE_H
#define PRODUTOUNIDADE_H

#include "Produto.h"

class ProdutoUnidade:public Produto{ //heran�a da classe produto
	protected:
		float quantidadeTotal; // quantidade total de produto
		float quantidadeVender; // quantidade a ser vendida do produto
	public:
		ProdutoUnidade(string="",int=0,float=0.0, float=0.0,float=0.0);
		void setQuantidadeTotal(float);
		float getQuantidadeTotal()const;
		void setQuantidadeVender(float);
		float getQuantidadeVender()const;
		float vender()const; // atritubuto que vai calcular a subtração de produto da qtd total
		void imprime()const;
};
#endif
