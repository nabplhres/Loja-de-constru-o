#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include <fstream> // Possibilita a leitura e gravação de dados em um arquivo.
using std::ofstream;
using std::ifstream;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort; // Ordena os elementos do vector por meio dos iteradores.

#include <stdexcept>
using std::out_of_range; // Exceção que indica tentativa de acesso a uma posição que o vector não possui.

#include <locale>
#include "Cliente.cpp"
#include "Produto.cpp"
#include "ProdutoKg.cpp"
#include "produtounidade.cpp"
#include "ListaKG.cpp"
#include "ListaProdutoUnd.cpp"

int main(){

	system("color f0");
	setlocale(LC_ALL, "Portuguese");

	ListaKG lista_Kg;
	ListaUnidade lista_Und;

	int opc=0;
	while(opc!=9){
       cout<<" ------- loja de construções -------\n"<<endl;
       cout<<" ---Insira uma das opcoes abaixo ---\n"<<endl;
       cout<<" 1- Inserir produtos no estoque"<<endl;
       cout<<" 2- Inserir dados do cliente"<<endl;
       cout<<" 3- Salvar lista em arquivo .txt"<<endl;
       cout<<" 4- Pesquisar produto por nome"<<endl;
       cout<<" 5- Pesquisar produto por codigo"<<endl;
       cout<<" 6- venda de produto da lista"<<endl;
       cout<<" 7- Imprimir lista"<<endl;
       cout<<" 8- Imprimir lista ordenada"<<endl;
       cout<<" 9- Sair"<<endl;
       cin>>opc;

		//system("pause");

		system("cls");
		switch(opc){
			case 1:{
                int opcproduto;
                cout<<"O produto é vendido por kg ou unidade ? 1-KG , 2-UNIDADE:"<<endl;
			    cin>>opcproduto;

				switch(opcproduto){
					case 1:{
                        Produto produto;
				        string nomeProduto;
				        int codigo;
				        float preco;
				        float pesoTotal;

      	                cout<<"Insira o nome do produto:"<< endl;
                       	cin >> nomeProduto;
       	                cout<<"Insira o codigo:"<< endl ;
      	                cin>>codigo;
      	                cout<<"Insira o preco:" << endl;
      	                cin>>preco;
                        cout <<"Insire o Peso total do produto"<<endl;
      	                cin >> pesoTotal;

                        ProdutoKG produtoKG (nomeProduto,codigo,preco, pesoTotal, pesoTotal);
                        if(lista_Kg.inserirProdutoKG(produtoKG))
                           cout << "Produto cadastrado com sucesso!" << endl;
                        else
                           cout << "O produto não foi cadastrado!" << endl;
                        break;
						}

					case 2:{

					    Produto produto;
				        string nomeProduto;
				        int codigo;
				        float preco;
				        float quantidadeTotal;

      	                cout<<"Insira o nome do produto:"<< endl;
      	                cin >> nomeProduto;
       	                cout<<"Insira o codigo:"<< endl ;
      	                cin>>codigo;
      	                cout<<"Insira o preco:" << endl;
      	                cin>>preco;
      	                cout <<"Insira a quantidade total do produto"<<endl;
      	                cin >> quantidadeTotal;
                        ProdutoUnidade produtoUnidade(nomeProduto,codigo,preco, quantidadeTotal,0.0);
			       	    if(lista_Und.inserirProdutoUnidade(produtoUnidade))
                           cout << "Produto cadastrado com sucesso!" << endl;
	  	  	  	        else
                           cout << "O produto não foi cadastrado!" << endl;
                        break;
						}
					}
				}
                system("pause");
		        system("cls");

				case 2:{
						Cliente cliente;
				
						string nome , cpf;
						cout << "Digite o nome do cliente:\n";
	            		cin>>nome;
	            		cliente.setNome(nome);
                		cout << "Digite o CPF do cliente:";
                		cin>>cpf;
                		cliente.setCPF(cpf);
                		system("cls");
                		cout << " ---Dados do cliente---"<< endl;

                		cliente.Imprime(); // impressão dos dados do cliente
                		system("pause");
		        		system("cls");
		        		break;
				}
            case 3:{
				lista_Kg.salvarListaKg();
				lista_Und.salvarListaUnidade();
				system("pause");
		        system("cls");
		        break;
			}
			case 4:{
				int opcproduto;
				cout<<"Qual produto você quer pesquisar ? 1-KG , 2-UNIDADE:"<<endl;
				cin>>opcproduto;
				if(opcproduto==1){
					
                   string nomeProduto;
      	           cout<<"Insira o nome do produto:"<<endl;
      	           cin >> nomeProduto;
                   if(!lista_Kg.pesquisarPorNome(nomeProduto))
     	              cout<<"Produto pesquisado não está na lista!"<<endl;
                      system("pause");
                      system("cls");
                      break;
                }
				if(opcproduto==2){
			       string nomeProduto;
	     	       cout<<"Insira o nome do produto:"<<endl;
      	           cin >> nomeProduto;
                   if(!lista_Und.pesquisarPorNome(nomeProduto))
    	              cout<<"Produto pesquisado não está na lista!"<<endl;
                      system("pause");
		              system("cls");
		              break;
				}
			}
			case 5:
			{
				int opcproduto;
                cout<<"Qual produto você quer pesquisar por codigo? 1-KG , 2-UNIDADE:"<<endl;
			 	cin>>opcproduto;
				if(opcproduto==1){
                   int codigo;
      	           cout<<"Insira o codigo do produto:"<<endl;
    	           cin >> codigo;
                   if(!lista_Kg.pesquisarPorCodigo(codigo))
     	              cout<<"Produto pesquisado não está na lista!"<<endl;
                      system("pause");
                      system("cls");
                      break;
				}
				if(opcproduto==2){
	               int codigo;
	     	       cout<<"Insira o codigo do produto:"<<endl;
      	           cin >> codigo;
                   if(!lista_Und.pesquisarPorCodigo(codigo))
     	              cout<<"Produto pesquisado não está na lista!"<<endl;
		              system("pause");
                      system("cls");
                      break;
				}
			}
			case 6:
			{
                int opcproduto;
                float quantidadeKG;
                
				cout<<"Insira 1 se o produto a ser vendido no KG e 2 se for vendido na unidade:"<<endl;
				cin>>opcproduto;
				
				if (opcproduto == 1){
                   string nomeProduto;
                   cout << "Insira o nome do produto a ser vendido:"<< endl;
                   cin>>nomeProduto;
                   cout << "Quantidade que deseja comprar: ";
                   cin >> quantidadeKG;
                   
                   quantidadeKG = lista_Kg.removerProdutoKG(nomeProduto, quantidadeKG);
                   lista_Kg.salvarListaKg();
                   
                       cout<<"----- venda feita-----\n"<<endl;
                       system("pause");
       	               system("cls");
                       break;
                   
				}
				
				int quantidadeUnd;
				
				if(opcproduto == 2){	
	               string nomeProduto;
     	           cout << "Insira o nome do produto a ser vendido:"<< endl;
                   cin>>nomeProduto;
                   cout << "Quantidade que deseja comprar: ";
                   cin >> quantidadeUnd;
                   quantidadeUnd = lista_Und.removerProdutoUnidade(nomeProduto, quantidadeUnd);
                   lista_Und.salvarListaUnidade();
                   
                   	   system("pause");
                       cout<<"----- venda feita-----\n"<<endl;
                       cout<<"Produto removido do estoque"<<endl;
       	               system("cls");
                       break;   
                       
				}
		
            	system("pause");
            	system("cls");
			}
			case 7:
			{
               lista_Kg.imprimirLista();
               lista_Und.imprimirLista();
               system("pause");
               system("cls");
               break;
			}
			case 8:{
				
               cout<<"Lista ordenada:"<<endl;
               lista_Kg.imprimirListaOrdenada();
               lista_Und.imprimirListaOrdenada();
               system("pause");
               system("cls");
               break;
			}
			case 9:{
               system("pause");
			   break;
			}
			default:
			{
               cout<<"Opcao incorreta"<<endl;
               system("pause");
               system("cls");
		       break;
			}
		}

	}
}

