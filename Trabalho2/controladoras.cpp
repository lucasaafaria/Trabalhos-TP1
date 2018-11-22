#include <iostream>
#include <stdexcept>

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"
#include "controladoras.h"
#include "stubs.h"
#include "comandos.h"

bool CtrlAprAutenticacao::autenticar(Identificador * id) {
  string        entrada;
  Identificador identificador;
  Senha         senha;

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

  bool resultado = servidor->autenticar(identificador, senha);

  if(resultado == false)
    cout << "Falha na autenticação" << endl;

  return resultado;
}

void CtrlAprUsuario::executar(Identificador * id, bool * autenticado) {
  int opcao;
  Cmd * comando;

  if((*autenticado) == false){
    comando = new CmdCadastrar();
    comando->executar(servidor, id, autenticado);
    delete comando;
    return;
  }

  while(true){
    // Apresentar as opções.

    cout << endl << "Gerenciamento de Opções." << endl << endl;

    cout << EDITAR       << " - Editar"        << endl;
    cout << DESCADASTRAR << " - Descadastrar"  << endl;
    cout << RETORNAR     << " - Retornar"      << endl << endl;
    cout << "Selecione uma opção: ";

    cin >> opcao;

    switch(opcao){
      case EDITAR:   
        comando = new CmdEditar();
        comando->executar(servidor, id, autenticado);
        delete comando;
        break;

      case DESCADASTRAR:   
        comando = new CmdDescadastrar();
        comando->executar(servidor, id, autenticado);
        delete comando;
        break;

      default:
        if(opcao != RETORNAR)
          cout << endl << "Escolha uma opção válida!" << endl;
        break; 
    }

    if(opcao == RETORNAR || opcao == DESCADASTRAR){
      break;
    }

  }

  return;
}