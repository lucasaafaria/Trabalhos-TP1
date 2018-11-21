#include <iostream>

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"
#include "interfaces.h"
#include "controladoras.h"

using namespace std;

int main() {
  int escolha;
  bool escolha_invalida = true;

  cout << "Bem vindo ao sistema! O que você deseja fazer?";

  while(escolha_invalida) {
    cout << "\n\t1 - Login\n\n>> ";
    cin >> escolha;

    switch(escolha) {
      case 1:
        {
          escolha_invalida = false;
          CtrlAprAutenticacao * ctrl = new CtrlAprAutenticacao();
          Identificador * id = new Identificador();

          bool resultado = ctrl->autenticar(id);
          
          delete ctrl;
          delete id;
        }
        break;
      
      default:
        cout << "Escolha uma opção válida!" << endl;
        break;
    }
  }

  return 0;
}
