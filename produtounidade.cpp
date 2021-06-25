#include "produtounidade.h"

ProdutoUnidade::ProdutoUnidade(string nomeProduto,int codigo, float preco,float quantidadeTotal, float quantidadeVender):
    Produto(nomeProduto, codigo, preco){
    setQuantidadeTotal(quantidadeTotal);
    setQuantidadeVender(quantidadeVender);
}

void ProdutoUnidade::setQuantidadeTotal(float quantidadeTotal){
    this->quantidadeTotal=quantidadeTotal;
}

float ProdutoUnidade::getQuantidadeTotal()const{
    return quantidadeTotal;
}

void ProdutoUnidade::setQuantidadeVender(float quantidadeVender){
    this->quantidadeVender=quantidadeVender;
}

float ProdutoUnidade::getQuantidadeVender()const{
    return quantidadeVender;
}

float ProdutoUnidade::vender()const{
    return quantidadeTotal - quantidadeVender;
}

void ProdutoUnidade::imprime() const{
    Produto::imprime();
    cout<<"quantidade total de Produtos: "<<getQuantidadeTotal()<<endl;
    cout <<"quantidade testante: " << vender()<< endl;
}
