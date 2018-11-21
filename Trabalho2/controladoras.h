#ifndef CONTROLADORAS_H_
#define CONTROLADORAS_H_

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"
#include "interfaces.h"

class CtrlAprAutenticacao:public IAprAutenticacao {
public:
  bool autenticar(Identificador * id);
  void setServidor(ISerAutenticacao * servidor) {
    this->servidor = servidor;
  }

private:
  ISerAutenticacao * servidor;
};

class CtrlAprUsuario:public IAprUsuario {
public:
  void executar(Identificador * id);
  void setServidor(ISerUsuario * servidor) {
    this->servidor = servidor;
  }

private:
  const static int INCLUIR   = 1;
  const static int REMOVER   = 2;
  const static int PESQUISAR = 3;
  const static int EDITAR    = 4;
  const static int RETORNAR  = 5;
  
  ISerUsuario * servidor;
};

#endif // CONTROLADORAS_H_