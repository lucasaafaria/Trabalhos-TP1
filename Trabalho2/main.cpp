#include <iostream>
#include <stdexcept>

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"
#include "interfaces.h"
#include "controladoras.h"
#include "stubs.h"

#define LOGIN     1
#define CADASTRAR 2
#define SAIR      3

using namespace std;

int main() {
  int escolha;
  bool resultado      = false;
  bool autenticado    = false;
  Identificador * id  = new Identificador();

  CtrlAprAutenticacao * ctrlAutenticacao  = new CtrlAprAutenticacao();
  CtrlAprUsuario      * ctrlUsuario       = new CtrlAprUsuario();
  
  StubSerAutenticacao * stubAutenticacao  = new StubSerAutenticacao();
  StubSerUsuario      * stubUsuario       = new StubSerUsuario();

  ctrlAutenticacao->setServidor(stubAutenticacao);
  ctrlUsuario->setServidor(stubUsuario);

  while(true) {
    cout << "Bem vindo ao sistema! O que você deseja fazer?" << endl;
    cout << "\t1 - Login"     << endl;
    cout << "\t2 - Cadastrar" << endl;
    cout << "\t3 - Sair"      << endl << endl;
    cout << "Sua escolha: "; 
    cin >> escolha;

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
          cout << "Escolha uma opção válida!" << endl;
        break;
    }

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