#ifndef COMANDOS_H_
#define COMANDOS_H_

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"
#include "interfaces.h"

class CmdIncluir {
public:
  void executar(ISerUsuario * servidor);
};

class CmdExcluir {
public:
  void executar(ISerUsuario * servidor);
};

class CmdPesquisar {
public:
  void executar(ISerUsuario * servidor);
};

class CmdEditar {
public:
  void executar(ISerUsuario * servidor);
};

#endif // COMANDOS_H_