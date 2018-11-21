#ifndef INTERFACES_H_
#define INTERFACES_H_

#include "../Trabalho1/dominios.h"
#include "../Trabalho1/entidades.h"

class ISerAutenticacao {
public:
  virtual bool autenticar(Identificador id, Senha senha) = 0;
  virtual ~ISerAutenticacao(){}
};

class IAprAutenticacao {
public:
  virtual bool autenticar(Identificador * id) = 0;
  virtual void setServidor(ISerAutenticacao * servidor) = 0;
  virtual ~IAprAutenticacao(){}
};

class ISerUsuario {
  
};

class IAprUsuario {
public:
  virtual void executar(Identificador * id) = 0;
  virtual void setServidor(ISerUsuario * servidor) = 0;
  virtual ~IAprUsuario(){}
};

#endif // INTERFACES_H_