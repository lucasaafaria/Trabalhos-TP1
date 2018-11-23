#include "comandos.h"

#include <iostream>
#include <cstdio>

using namespace std;

// ------------------------------------------------------------------------- //
// O comando a seguir coleta as informações necessárias do usuário e solicita
// à camada de serviços o seu cadastramento

void CmdCadastrar::executar(ISerUsuario * servidor, Identificador * id, bool * autenticado) {
  
  // Variáveis utilizadas

  bool          resultado;
  string        entrada;
  Nome          nome;
  Identificador identificador;
  Senha         senha;
  Usuario *     usuario;

  // Código de interação com o usuário.
  system("clear || cls");
  cout << "Olá! Vamos prosseguir ao seu cadastramento:" << endl << endl;
  
  while(true){
    try{
      cout << "Digite seu nome: ";
      getline(cin, entrada);
      nome.setNome(entrada);
      cout << endl;

      cout << "Escolha um identificador de 5 letras: ";
      getline(cin, entrada);
      identificador.setIdentificador(entrada);
      cout << endl;

      cout << "Escolha uma senha (8 caracteres diferentes, com pelo menos 1 letra maiúscula, 1 letra minúscula, um número e um símbolo): ";
      getline(cin, entrada);
      senha.setSenha(entrada);      
      cout << endl;
      break;
    }
    catch(invalid_argument &exp){
      cout << "Dados com formato incorreto" << endl << endl;
    }
  }

  // Solicitar serviço.

  usuario   = new Usuario(nome, identificador, senha);
  resultado = servidor->cadastrar(*usuario);

  if(resultado == true){
    cout << "Usuário cadastrado com sucesso!" << endl << endl;
    id->setIdentificador(identificador.getIdentificador());
    (*autenticado) = true;
  } else{
    cout << "Falha no cadastramento!" << endl << endl;
  }

  cout << "Pressione [Enter] para continuar >>";
  getchar();
}

// ------------------------------------------------------------------------- //
// O comando a seguir coleta as novas informações do usuário e solicita
// à camada de serviços a edição dos dados

void CmdEditar::executar(ISerUsuario * servidor, Identificador * id, bool * autenticado) {

  // Variáveis utilizadas

  bool          resultado;
  string        entrada;
  Nome          nome;
  Identificador identificador;
  Senha         senha;
  Usuario *     usuario;

  // Código de interação com o usuário.
  system("clear || cls");
  cout << "Olá! Informe os seus novos dados:" << endl << endl;

  while(true){
    try{
      cout << "Digite seu nome: ";
      getline(cin, entrada);
      nome.setNome(entrada);
      cout << endl;

      cout << "Escolha seu novo identificador de 5 letras: ";
      getline(cin, entrada);
      identificador.setIdentificador(entrada);
      cout << endl;

      cout << "Escolha uma nova senha (8 caracteres diferentes, com pelo menos 1 letra maiúscula, 1 letra minúscula, um número e um símbolo): ";
      getline(cin, entrada);
      senha.setSenha(entrada);      
      cout << endl;

      break;
    }
    catch(invalid_argument &exp){
      cout << endl << "Dados em formato incorreto!" << endl << endl;
    }
  }

  // Solicitar serviço.

  usuario   = new Usuario(nome, identificador, senha);
  resultado = servidor->editar(id, *usuario);

  if(resultado == true){
    cout << "Dados editados com sucesso!" << endl << endl;
    id->setIdentificador(identificador.getIdentificador());
    (*autenticado) = true;
  } else{
    cout << "Falha ao tentar editar os dados!" << endl << endl;
  }

  cout << "Pressione [Enter] para continuar >>";
  getchar();
}

// ------------------------------------------------------------------------- //
// O comando a seguir confirma com o usuário se o mesmo deseja descadastrar-se
// e solicita esse serviço, se for o caso.

void CmdDescadastrar::executar(ISerUsuario * servidor, Identificador * id, bool * autenticado){
  bool  resultado;
  int   opcao;

  // Código de interação com o usuário.
  system("clear || cls");
  cout << "Olá! Você realmente deseja descadastrar-se do sistema?" << endl;
  cout << "\t1 - Sim" << endl;
  cout << "\t2 - Não" << endl;
  cout << "Sua escolha: ";
  cin >> opcao;
  getchar();

  if(opcao == 2)
    return;

  // Solicitar serviço.

  resultado = servidor->descadastrar(id);

  if(resultado == true) {
    cout << "Usuario descadastrado com sucesso!" << endl << endl;
    (*autenticado) = false;
  } else {
    cout << "Falha no descadastramento!" << endl << endl;
  }
  
  cout << "Pressione [Enter] para continuar >>";
  getchar();
}

// ------------------------------------------------------------------------- //