#ifndef COMANDOS_H_
#define COMANDOS_H_

// Relação de bibliotecas utilizadas na declaração das classes de comandos

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"
#include "interfaces.h"

// As classes de comando são responsáveis por solicitar serviços específicos do módulo de
// Serviços de Usuário.

// ---------------------------------------------------------------------------------------- //
// Classe Abstrata Pura Cmd:

class Cmd {
public:

  // Declaração de métodos virtuais puros

	virtual void executar(ISerUsuario * servidor, Identificador * id, bool * autenticado) = 0;
	virtual ~Cmd(){}
};

// ---------------------------------------------------------------------------------------- //
// Classe CmdCadastrar, herdada de Cmd:

class CmdCadastrar:public Cmd {
public:

  // Métodos da classe

  void executar(ISerUsuario * servidor, Identificador * id, bool * autenticado);
  ~CmdCadastrar(){}
};

// ---------------------------------------------------------------------------------------- //
// Classe CmdEditar, herdada de Cmd:

class CmdEditar:public Cmd {
public:
  
  // Métodos da classe

  void executar(ISerUsuario * servidor, Identificador * id, bool * autenticado);
  ~CmdEditar(){}
};

// ---------------------------------------------------------------------------------------- //
// Classe CmdDescadastrar, herdada de Cmd:

class CmdDescadastrar:public Cmd {
public:

  // Métodos da classe

  void executar(ISerUsuario * servidor, Identificador * id, bool * autenticado);
  ~CmdDescadastrar(){}
};

// ---------------------------------------------------------------------------------------- //

#endif // COMANDOS_H_