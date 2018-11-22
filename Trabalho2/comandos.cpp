#include "comandos.h"

#include <iostream>
#include <cstdio>

using namespace std;

// Método por meio do qual é solicitada a execução do comando.

void CmdCadastrar::executar(ISerUsuario * servidor, Identificador * id, bool * autenticado) {
  bool          resultado;
  string        entrada;
  Nome          nome;
  Identificador identificador;
  Senha         senha;
  Usuario *     usuario;

  // Código de interação com o usuário.
  cout << "Olá! Vamos prosseguir ao seu cadastramento:" << endl << endl;
  
  while(true){
    try{
      getchar();
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
      cout << "Dados com formato incorreto" << endl;
    }
  }

  // Solicitar serviço.

  usuario   = new Usuario(nome, identificador, senha);
  resultado = servidor->cadastrar(*usuario);

  if(resultado == true){
    cout << "Usuário cadastrado com sucesso!" << endl;
    id->setIdentificador(identificador.getIdentificador());
    (*autenticado) = true;
  } else{
    cout << "Falha no cadastramento!" << endl;
  }
}

// Método por meio do qual é solicitada a execução do comando.

void CmdEditar::executar(ISerUsuario * servidor, Identificador * id, bool * autenticado) {
  bool          resultado;
  string        entrada;
  Nome          nome;
  Identificador identificador;
  Senha         senha;
  Usuario *     usuario;

  // Código de interação com o usuário.
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
      cout << endl << "Dados em formato incorreto!" << endl;
    }
  }

  // Solicitar serviço.

  usuario   = new Usuario(nome, identificador, senha);
  resultado = servidor->editar(id, *usuario);

  if(resultado == true){
    cout << "Dados editados com sucesso!" << endl;
    id->setIdentificador(identificador.getIdentificador());
    (*autenticado) = true;
  } else{
    cout << "Falha ao tentar editar os dados!" << endl;
  }
}

// Método por meio do qual é solicitada a execução do comando.

void CmdDescadastrar::executar(ISerUsuario * servidor, Identificador * id, bool * autenticado){
  bool  resultado;
  int   opcao;

  // Código de interação com o usuário.
  cout << "Olá! Você realmente deseja descadastrar-se do sistema?" << endl;
  cout << "\t1 - Sim" << endl;
  cout << "\t2 - Não" << endl;
  cout << "Sua escolha: ";
  cin >> opcao;

  if(opcao == 2)
    return;

  // Solicitar serviço.

  resultado = servidor->descadastrar(id);

  if(resultado == true) {
    cout << "Usuario descadastrado com sucesso!" << endl;
    (*autenticado) = false;
  } else {
    cout << "Falha no descadastramento!" << endl;
  }
  
}