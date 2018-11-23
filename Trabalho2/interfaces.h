#ifndef INTERFACES_H_
#define INTERFACES_H_

// Bibliotecas utilizadas na declaração de interfaces

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"

// Todas as interfaces são classes abstratas puras, implementadas pelas 
// classes controladoras.

// ------------------------------------------------------------------------- //
// Declaração das interfaces do módulo de Autenticação
//
// Interface da Camada de Serviços:

class ISerAutenticacao {
public:

  // Métodos virtuais puros

  virtual bool autenticar(const Identificador &id, const Senha &senha) = 0;
  virtual ~ISerAutenticacao(){}
};

// Interface da Camada de Apresentação:

class IAprAutenticacao {
public:

  // Métodos virtuais puros

  virtual bool autenticar(Identificador * id) = 0;
  virtual void setServidor(ISerAutenticacao * servidor) = 0;
  virtual ~IAprAutenticacao(){}
};

// ------------------------------------------------------------------------- //
// Declaração das interfaces do módulo de Usuário
//
// Interface da Camada de Serviços:

class ISerUsuario {
public:

  // Métodos virtuais puros

  virtual bool cadastrar(const Usuario&) = 0;
  virtual bool editar(const Identificador*, const Usuario&) = 0;
  virtual bool descadastrar(const Identificador*) = 0;
  virtual ~ISerUsuario(){}
};

// Interface da Camada de Apresentação:

class IAprUsuario {
public:

  // Métodos virtuais puros

  virtual void executar(Identificador * id, bool * autenticado) = 0;
  virtual void setServidor(ISerUsuario * servidor) = 0;
  virtual ~IAprUsuario(){}
};

// ------------------------------------------------------------------------- //

#endif // INTERFACES_H_