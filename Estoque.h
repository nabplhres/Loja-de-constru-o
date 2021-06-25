#ifndef ESTOQUE_H
#define ESTOQUE_H
class Estoque{
	private:
		ProdutoUnitario EstoqueProdutoUnitario;
		ProdutoQuilo EstoqueProdutoQuilo;
		int TamMaximo;   
		int NumElementos;
    public:
     	Estoque();
     	void ordenaDados(string,int); //recebe o nome do produto e NumElementos
     	bool pesquisa(string); //recebe o nome, e retorna True ou False caso o nome esteja presente na lista
     	bool insereproduto(string,float,float);//recebe nome, quantidade do produto e preço  
     	bool retiraproduto(string); //retira produto á partir do nome
     	bool salvaRecuperaDados(); 
     	void venda(int,int); //recebe codigo do produto e quantidade, e retorna dados do produto
		~Estoque(); // Salva lista, caso não se lembre de salvar
};
#endif