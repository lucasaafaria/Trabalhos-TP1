#include <iostream>
#include <stdexcept>

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"
#include "controladoras.h"

bool CtrlAprAutenticacao::autenticar(Identificador * id) {
  string  entrada;
  Identificador identificador;
  Senha senha;

  while(true) {
    cout << endl << "Faça seu login:" << endl << endl;

    try {
      cout << "Digite seu identificador: ";
      cin >> entrada;
      identificador.setIdentificador(entrada);
      cout << "Digite sua senha: ";
      cin >> entrada;
      senha.setSenha(entrada);
      break;
    }
    catch(invalid_argument excecao) {
      cout << "\nIdentificador e/ou senha em formato inválido." << endl;
    }
  }

  id->setIdentificador(identificador.getIdentificador());

  /* Para quando implementarmos o banco de dados:

  bool resultado = servidor->autenticar(identificador, senha);

  if(resultado == false)
    cout << "Falha na autenticação" << endl;

  return resultado;

  */

  return true;
}

void CtrlAprUsuario(Identificador * id) {
  /*int opcao;

  while(true){
    // Apresentar as opções.

    cout << endl << "Gerenciamento de Opções." << endl << endl;

    cout << "Incluir   - " << INCLUIR << endl;
    cout << "Remover   - " << REMOVER << endl;
    cout << "Pesquisar - " << PESQUISAR << endl;
    cout << "Editar    - " << EDITAR << endl;
    cout << "Retornar  - " << RETORNAR << endl << endl;
    cout << "Selecione uma opcao :";

    cin >> opcao;

    switch(opcao){
      case INCLUIR:   
        comando = new ComandoIUGerenteIncluir();
        comando->executar(cntrLNGerente);
        delete comando;
        break;

      case REMOVER:   
        comando = new ComandoIUGerenteRemover();
        comando->executar(cntrLNGerente);
        delete comando;
        break;

      case PESQUISAR: 
        comando = new ComandoIUGerentePesquisar();
        comando->executar(cntrLNGerente);
        delete comando;
        break;

      case EDITAR:
        comando = new ComandoIUGerenteEditar();
        comando->executar(cntrLNGerente);
        delete comando;
        break;
    }

    if(opcao == RETORNAR){
      break;
    }

  }

  return;*/
  cout << "coe" << endl;
}