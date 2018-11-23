#include <iostream>
#include <cstdio>
#include <stdexcept>

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"
#include "controladoras.h"
#include "stubs.h"
#include "comandos.h"

// Implementação dos métodos das classes controladoras da camada de apresentação

// -------------------------------------------------------------------------- //
// Método que pede as informações do usuário para realizar o login e solicita
// serviços para realizar a autenticação. Retorna o resultado da autenticação.

bool CtrlAprAutenticacao::autenticar(Identificador * id) {

  // Variáveis utilizadas
  
  bool          resultado;
  string        entrada;
  Identificador identificador;
  Senha         senha;

  // Código de interação com o usuário:

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

  // Informa o sistema qual o identificador do usuário logado
  id->setIdentificador(identificador.getIdentificador());

  // Solicitação de serviço de autenticação
  resultado = servidor->autenticar(identificador, senha);

  if(resultado == false)
    cout << "Falha na autenticação." << endl << endl;
  else
    cout << "Usuário autenticado com sucesso!" << endl << endl;

  cout << "Pressione [Enter] para continuar >>";
  getchar();

  return resultado;
}

// -------------------------------------------------------------------------- //
// Método que apresenta as opções de ações possíveis para o usuário, instancia
// os objetos responsáveis por executá-las e dá o comando para que eles o façam.

void CtrlAprUsuario::executar(Identificador * id, bool * autenticado) {
  
  // Variáveis utilizadas

  int opcao;
  Cmd * comando;

  // Se o usuário não está autenticado, sua única opção além de login é 
  // cadastrar-se

  if((*autenticado) == false){
    comando = new CmdCadastrar();
    comando->executar(servidor, id, autenticado);
    delete comando;
    return;
  }

  // Opções para caso o usuário esteja autenticado:

  while(true){
    // Interação com o usuário
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

      // Caso de opções inválidas ou logout
      default:
        if(opcao != LOGOUT)
          cout << endl << "Escolha uma opção válida!" << endl;
        else
          (*autenticado) = false;
        break; 
    }

    // Sai da função caso a opção tenha sido logout ou caso o usuário tenha
    // se descadastrado
    if(opcao == LOGOUT || (*autenticado) == false)
      break;

  }

  return;
}