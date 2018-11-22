#ifndef COMANDOS_H_
#define COMANDOS_H_

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"
#include "interfaces.h"

class Cmd {
public:
	virtual void executar(ISerUsuario * servidor, Identificador * id, bool * autenticado) = 0;
	virtual ~Cmd(){}
};

class CmdCadastrar:public Cmd {
public:
  void executar(ISerUsuario * servidor, Identificador * id, bool * autenticado);
  ~CmdCadastrar(){}
};

class CmdEditar:public Cmd {
public:
  void executar(ISerUsuario * servidor, Identificador * id, bool * autenticado);
  ~CmdEditar(){}
};

class CmdDescadastrar:public Cmd {
public: 
  void executar(ISerUsuario * servidor, Identificador * id, bool * autenticado);
  ~CmdDescadastrar(){}
};

#endif // COMANDOS_H_