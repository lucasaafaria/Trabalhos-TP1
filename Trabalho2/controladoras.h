#ifndef CONTROLADORAS_H_
#define CONTROLADORAS_H_

// Inclusão de bibliotecas utilizadas na declaração das classes

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"
#include "interfaces.h"

// Declaração de  classes controladoras da camada de apresentação

// ------------------------------------------------------------------------- // 
// Controladora Autenticação:

class CtrlAprAutenticacao:public IAprAutenticacao {
public:
  
  // Métodos da classe

  bool autenticar(Identificador * id);
  void setServidor(ISerAutenticacao * servidor) {
    this->servidor = servidor;
  }

private:

  // Referência para a interface da camada de serviços

  ISerAutenticacao * servidor;
};

// ------------------------------------------------------------------------- //
// Controladora Usuário:

class CtrlAprUsuario:public IAprUsuario {
public:

  // Métodos da classe
   
  void executar(Identificador * id, bool * autenticado);
  void setServidor(ISerUsuario * servidor) {
    this->servidor = servidor;
  }

private:

  // Constantes utilizadas para simbolizar as opções de ações do usuário

  const static int CADASTRAR    = 1;
  const static int EDITAR       = 2;
  const static int DESCADASTRAR = 3;
  const static int LOGOUT       = 4;
  
  // Referência para a interface da camada de serviços
  
  ISerUsuario * servidor;
};

// ------------------------------------------------------ //

#endif // CONTROLADORAS_H_