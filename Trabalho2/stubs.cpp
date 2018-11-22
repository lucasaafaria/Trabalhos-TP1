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

const int StubSerUsuario::TRIGGER_FALHA;
const int StubSerUsuario::TRIGGER_ERRO_SISTEMA;

bool StubSerUsuario::cadastrar(const Usuario &usuario){
  return true;
}

bool StubSerUsuario::editar(const Identificador * id, const Usuario &usuario){
  return true;
}

bool StubSerUsuario::descadastrar(const Identificador * id){
  return true;
}