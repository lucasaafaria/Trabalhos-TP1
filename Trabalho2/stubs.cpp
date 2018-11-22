#include "stubs.h"

using namespace std;

//Definições de constantes.

const string StubSerAutenticacao::TRIGGER_FALHA_ID     = "abcdf";
const string StubSerAutenticacao::TRIGGER_ERRO_SISTEMA = "edcba";
const string StubSerAutenticacao::TRIGGER_FALHA_SENHA  = "1!aB2@cE";

// Definições de método da classe stub do controlador da lógica de negócio de autenticação.

bool StubSerAutenticacao::autenticar(const Identificador &id, const Senha &senha) {
  bool resultado;

  // Apresentar dados recebidos.
  system("clear || cls");
  cout << endl << "StubSerAutenticacao::autenticar"     << endl;
  cout << "Identificador  = " << id.getIdentificador()  << endl;
  cout << "Senha          = " << senha.getSenha()       << endl;

   // Diferentes comportamentos dependendo do valor da matrícula.

  if(id.getIdentificador() == TRIGGER_FALHA_ID)
    resultado = false;

  else if(id.getIdentificador() == TRIGGER_ERRO_SISTEMA)
    throw runtime_error("Erro de sistema");

  else if(senha.getSenha() == TRIGGER_FALHA_SENHA)
    resultado = false;

  else
    resultado = true;

  return resultado;
}

const string StubSerUsuario::TRIGGER_FALHA_CADASTRO     = "lucas";
const string StubSerUsuario::TRIGGER_FALHA_EDICAO       = "12!@abCE";
const string StubSerUsuario::TRIGGER_FALHA_DESCADASTRO  = "abcdf";
const string StubSerUsuario::TRIGGER_ERRO_SISTEMA       = "edcba";

bool StubSerUsuario::cadastrar(const Usuario &usuario){
  bool          resultado;
  Nome          nome          = usuario.getNome();
  Identificador identificador = usuario.getIdentificador();
  Senha         senha         = usuario.getSenha();

  // Apresentar dados recebidos.
  system("clear || cls");
  cout << "StubSerUsuario::cadastrar" << endl ;
  cout << "Nome          = " << nome.getNome()                   << endl;
  cout << "Identificador = " << identificador.getIdentificador() << endl;
  cout << "Senha         = " << senha.getSenha()                 << endl;

  // Diferentes comportamentos dependendo do valor da matrícula.

  if(nome.getNome() == TRIGGER_FALHA_CADASTRO)
    resultado = false;

  else if(identificador.getIdentificador() == TRIGGER_ERRO_SISTEMA)
    throw runtime_error("Erro de sistema");

  else
    resultado = true;

  return resultado;
}

bool StubSerUsuario::editar(const Identificador * id, const Usuario &usuario){
  bool          resultado;
  Nome          nome          = usuario.getNome();
  Identificador identificador = usuario.getIdentificador();
  Senha         senha         = usuario.getSenha();

  // Apresentar dados recebidos.
  system("clear || cls");
  cout << "StubSerUsuario::editar" << endl;
  cout << "Identificador Antigo = " << id->getIdentificador()     << endl;
  cout << "Novo Nome            = " << nome.getNome()                   << endl;
  cout << "Novo Identificador   = " << identificador.getIdentificador() << endl;
  cout << "Nova Senha           = " << senha.getSenha()                 << endl;

  // Diferentes comportamentos dependendo do valor da matrícula.

  if(senha.getSenha() == TRIGGER_FALHA_EDICAO)
    resultado = false;

  else if(identificador.getIdentificador() == TRIGGER_ERRO_SISTEMA)
    throw runtime_error("Erro de sistema");

  else
    resultado = true;

  return resultado;
}

bool StubSerUsuario::descadastrar(const Identificador * id){
  bool resultado;

  // Apresentar dados recebidos.
  system("clear || cls");
  cout << "StubSerUsuario::descadastrar" << endl ;
  cout << "Identificador = " << id->getIdentificador() << endl;

  // Diferentes comportamentos dependendo do valor da matrícula.

  if(id->getIdentificador() == TRIGGER_FALHA_DESCADASTRO)
    resultado = false;

  else if(id->getIdentificador() == TRIGGER_ERRO_SISTEMA)
    throw runtime_error("Erro de sistema");

  else
    resultado = true;

  return resultado;
}