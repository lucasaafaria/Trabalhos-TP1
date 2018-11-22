#ifndef STUBS_H_
#define STUBS_H_

#include "interfaces.h"

#include <stdexcept>
#include <iostream>
#include <typeinfo>

using namespace std;

// Declaração de classes stubs das interfaces da camada de serviços

// ---------------------------------------------------------------------------------- //
// Stub da interface ISerAutenticacao.

class StubSerAutenticacao:public ISerAutenticacao {

public:

  // Definições de valores a serem usados como gatilhos para notificações de erros.

  const static string TRIGGER_FALHA_ID;
  const static string TRIGGER_ERRO_SISTEMA;
  const static string TRIGGER_FALHA_SENHA;

  // Declaração de método previsto na interface.

  bool autenticar(const Identificador&, const Senha&);
};

// ---------------------------------------------------------------------------------- //
// Stub da interface ISerUsuario.

class StubSerUsuario:public ISerUsuario {

public:

  // Definições de valores a serem usados como gatilhos para notificações de erros.

  const static int TRIGGER_FALHA        = 67890;
  const static int TRIGGER_ERRO_SISTEMA = 78901;

  bool cadastrar(const Usuario&);
  bool editar(const Identificador*, const Usuario&);
  bool descadastrar(const Identificador*);
};

// ---------------------------------------------------------------------------------- //

#endif // STUBS_H_