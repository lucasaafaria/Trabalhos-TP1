#ifndef STUBS_H_
#define STUBS_H_

// Bibliotecas utilizadas para a declaração das classes stubs

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

  // Declarações de constantes a serem usadas como gatilhos para notificações de erros.

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

  // Declarações de constantes a serem usadas como gatilhos para notificações de erros.

  const static string TRIGGER_FALHA_CADASTRO;
  const static string TRIGGER_FALHA_EDICAO;
  const static string TRIGGER_FALHA_DESCADASTRO;
  const static string TRIGGER_ERRO_SISTEMA;

  bool cadastrar(const Usuario&);
  bool editar(const Identificador*, const Usuario&);
  bool descadastrar(const Identificador*);
};

// ---------------------------------------------------------------------------------- //

#endif // STUBS_H_