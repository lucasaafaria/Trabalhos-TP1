#ifndef CONTROLADORAS_H_
#define CONTROLADORAS_H_

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"
#include "interfaces.h"

// Declaração de controladoras da camada de apresentação

// ------------------------------------------------------ // 
// Controladora Autenticação:

class CtrlAprAutenticacao:public IAprAutenticacao {
public:

  // 
  bool autenticar(Identificador * id);
  void setServidor(ISerAutenticacao * servidor) {
    this->servidor = servidor;
  }

private:
  ISerAutenticacao * servidor;
};

// ------------------------------------------------------ //
// Controladora Usuário:

class CtrlAprUsuario:public IAprUsuario {
public:
  void executar(Identificador * id, bool * autenticado);
  void setServidor(ISerUsuario * servidor) {
    this->servidor = servidor;
  }

private:
  const static int CADASTRAR    = 1;
  const static int EDITAR       = 2;
  const static int DESCADASTRAR = 3;
  const static int LOGOUT       = 4;
  
  ISerUsuario * servidor;
};

// ------------------------------------------------------ //

#endif // CONTROLADORAS_H_