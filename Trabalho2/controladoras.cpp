#include <iostream>
#include <cstdio>
#include <stdexcept>

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"
#include "controladoras.h"
#include "stubs.h"
#include "comandos.h"

bool CtrlAprAutenticacao::autenticar(Identificador * id) {
  bool          resultado;
  string        entrada;
  Identificador identificador;
  Senha         senha;

  system("clear || cls");
  
  while(true) {
    cout << endl << "Faça seu login:" << endl << endl;

    try {
      cout << "Digite seu identificador: ";
      cin >> entrada;
      getchar();
      identificador.setIdentificador(entrada);
      cout << "Digite sua senha: ";
      cin >> entrada;
      getchar();
      senha.setSenha(entrada);
      break;
    }
    catch(invalid_argument excecao) {
      cout << "\nIdentificador e/ou senha em formato inválido." << endl;
    }
  }

  id->setIdentificador(identificador.getIdentificador());

  resultado = servidor->autenticar(identificador, senha);

  if(resultado == false)
    cout << "Falha na autenticação." << endl << endl;
  else
    cout << "Usuário autenticado com sucesso!" << endl << endl;

  cout << "Pressione [Enter] para continuar >>";
  getchar();

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
    system("clear || cls");
    cout << "ID do usuário logado: " << id->getIdentificador() << endl << endl;
    cout << "Gerenciamento de Opções:" << endl << endl;

    cout << EDITAR       << " - Editar"        << endl;
    cout << DESCADASTRAR << " - Descadastrar"  << endl;
    cout << LOGOUT       << " - Logout"      << endl << endl;
    cout << "Selecione uma opção: ";

    cin >> opcao;
    getchar();

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
        if(opcao != LOGOUT)
          cout << endl << "Escolha uma opção válida!" << endl;
        else
          (*autenticado) = false;
        break; 
    }

    if(opcao == LOGOUT || (*autenticado) == false)
      break;

  }

  return;
}