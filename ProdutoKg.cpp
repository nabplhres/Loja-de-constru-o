#include "Produtokg.h"

ProdutoKG::ProdutoKG(string nomeProduto,int codigo,float preco, float pesoTotal,float vendaKG):
    Produto(nomeProduto, codigo, preco){
      setpesoTotal(pesoTotal);
      setvendaKG(vendaKG);

}
void ProdutoKG::setpesoTotal(float pesoTotal){
    this -> pesoTotal = pesoTotal;
}
float ProdutoKG::getpesoTotal()const{
    return pesoTotal;
}
void ProdutoKG::setvendaKG(float vendaKG){
    this -> vendaKG = vendaKG;
}
float ProdutoKG::getvendaKG()const{
    return vendaKG;
}
float ProdutoKG::restante() const{
  return pesoTotal - vendaKG;
}
void ProdutoKG::imprime()const{
    Produto::imprime();
    cout << "Peso total produto em KG: " << getpesoTotal()<<endl;
    cout << "Peso restante produto em KG: " << restante() <<endl;
}
