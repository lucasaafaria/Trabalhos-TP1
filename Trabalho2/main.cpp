#include <iostream>
#include <cstdio>
#include <stdexcept>

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"
#include "interfaces.h"
#include "controladoras.h"
#include "stubs.h"

// Macros utilizados no menu de interação com o usuário

#define LOGIN     1
#define CADASTRAR 2
#define SAIR      3

using namespace std;

int main() {
  // Variáveis utilizadas na lógica do progama
  int escolha;
  bool resultado      = false;
  bool autenticado    = false;

  // Guarda o identificador do usuário logado
  Identificador * id  = new Identificador();

  // Instâncias das controladoras da camada de apresentação
  CtrlAprAutenticacao * ctrlAutenticacao  = new CtrlAprAutenticacao();
  CtrlAprUsuario      * ctrlUsuario       = new CtrlAprUsuario();
  
  // Instâncias das stubs da camada de serviços
  StubSerAutenticacao * stubAutenticacao  = new StubSerAutenticacao();
  StubSerUsuario      * stubUsuario       = new StubSerUsuario();

  // Estabelecimento de ligações entre controladoras e respectivas stubs
  ctrlAutenticacao->setServidor(stubAutenticacao);
  ctrlUsuario->setServidor(stubUsuario);


  while(true) {

    // Interação com o usuário
    system("clear || cls");
    if(autenticado == true)
      cout << "ID do usuário logado: " << id->getIdentificador() << endl << endl;
    else
      cout << "Não há usuários logados no momento!" << endl << endl;

    cout << "Bem vindo ao sistema! O que você deseja fazer?" << endl;
    cout << "\t1 - Login"     << endl;
    cout << "\t2 - Cadastrar" << endl;
    cout << "\t3 - Sair"      << endl << endl;
    cout << "Sua escolha: "; 
    cin >> escolha;
    getchar();

    switch(escolha) {
      case LOGIN:
        try {
          resultado = ctrlAutenticacao->autenticar(id);
          if(resultado == true)
            autenticado = true;
        } catch(const runtime_error &exp) {
          cout << "Erro de Sistema." << endl;
        }
        break;

      case CADASTRAR:
        try {
          ctrlUsuario->executar(id, &autenticado);
        } catch(const runtime_error &exp) {
          cout << "Erro de Sistema." << endl;
        }
        break;
      
      default:
        if(escolha != SAIR)
          cout << endl << "Escolha uma opção válida!" << endl << endl;
        break;
    }

    // Caso o usuário se cadastre ou se autentique, ele será apresentado às
    // ações que poderá realizar
    
    if(autenticado == true){
      try {
        ctrlUsuario->executar(id, &autenticado);
      } catch(const runtime_error &exp) {
        cout << "Erro de Sistema." << endl; 
      }
    }

    if(escolha == SAIR)
      return 0;
  
  }
  
  delete ctrlAutenticacao;
  delete ctrlUsuario;
  delete stubAutenticacao;
  delete stubUsuario;
  delete id;

  return 0;
}