#ifndef TESTES_DOM_H_
#define TESTES_DOM_H_

#include <vector>

#include "dominios.h"

using namespace std;

// Declarações dos Testes de Unidade (TU) de cada domínio

// Classe responsável por testar o funcionamento do domínio Agencia
class TUAgencia {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes para definir os valores a serem testados.
  const static int NUM_TESTES_FALHA;
  const static string VALOR_VALIDO;
  const static std::vector<string> VALOR_INVALIDO;
  
  // Referência para o objeto a ser testado.    
  Agencia * agencia;

  // Estado do teste.
  int estado;

  // Declarações de métodos.    
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();
};


// Classe responsável por testar o funcionamento do domínio Banco
class TUBanco {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes para definir os valores a serem testados.
  const static int NUM_TESTES_FALHA;
  const static string VALOR_VALIDO;
  const static std::vector<string> VALOR_INVALIDO;
  
  // Referência para o objeto a ser testado.
  Banco * banco;

  // Estado do teste.
  int estado;

  // Declarações de métodos.    
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();
};

// Classe responsável por testar o funcionamento do domínio Capacidade
class TUCapacidade {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes para definir os valores a serem testados.
  const static int NUM_TESTES_FALHA;
  const static int VALOR_VALIDO;
  const static std::vector<int> VALOR_INVALIDO;
  
  // Referência para o objeto a ser testado.
  Capacidade * capacidade;

  // Estado do teste.
  int estado;

  // Declarações de métodos.    
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();
};

// Classe responsável por testar o funcionamento do domínio Diária
class TUDiaria {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes para definir os valores a serem testados.
  const static int NUM_TESTES_FALHA;
  const static float VALOR_VALIDO;
  const static std::vector<float> VALOR_INVALIDO;
  
  // Referência para o objeto a ser testado.
  Diaria * diaria;

  // Estado do teste.
  int estado;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();
};

// Classe responsável por testar o funcionamento do domínio Data
class TUData {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes para definir os valores a serem testados.
  const static int NUM_TESTES_FALHA;
  const static int NUM_TESTES_SUCESSO;
  const static std::vector<string> VALOR_VALIDO;
  const static std::vector<string> VALOR_INVALIDO;
  
  // Referência para o objeto a ser testado.
  Data * data;

  // Estado do teste.
  int estado;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();
};

// Classe responsável por testar o funcionamento do domínio Validade
class TUValidade {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes para definir os valores a serem testados.
  const static int NUM_TESTES_FALHA;
  const static int NUM_TESTES_SUCESSO;
  const static std::vector<string> VALOR_VALIDO;
  const static std::vector<string> VALOR_INVALIDO;
  
  // Referência para o objeto a ser testado.
  Validade * validade;

  // Estado do teste.
  int estado;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();
};

// Classe responsável por testar o funcionamento do domínio Estado;
class TUEstado {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes para definir os valores a serem testados.
  const static int NUM_TESTES_SUCESSO;
  const static int NUM_TESTES_FALHA;
  const static std::vector<std::string> VALOR_VALIDO;
  const static std::vector<std::string> VALOR_INVALIDO;
  
  // Referência para o objeto a ser testado.
  Estado * estado;

  // Estado do teste.
  int estado_teste;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();
};

// Classe responsável por testar o funcionamento do domínio Identificador
class TUIdentificador {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes para definir os valores a serem testados.
  const static int NUM_TESTES_SUCESSO;
  const static int NUM_TESTES_FALHA;
  const static std::vector<string> VALOR_VALIDO;
  const static std::vector<string> VALOR_INVALIDO;
  
  // Referência para o objeto a ser testado.
  Identificador * identificador;

  // Estado do teste.
  int estado;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();
};

// Classe responsável por testar o funcionamento do domínio Nome
class TUNome {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes para definir os valores a serem testados.
  const static int NUM_TESTES_SUCESSO;
  const static int NUM_TESTES_FALHA;
  const static std::vector<string> VALOR_VALIDO;
  const static std::vector<string> VALOR_INVALIDO;

  // Referência para o objeto a ser testado.
  Nome * nome;

  // Estado do teste.
  int estado;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();
};

// Classe responsável por testar o funcionamento do domínio NumeroCartao
class TUNumeroCartao {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes para definir os valores a serem testados.
  const static string VALOR_VALIDO;
  const static string VALOR_INVALIDO;

  // Referência para o objeto a ser testado.
  NumeroCartao * numero_cartao;

  // Estado do teste.
  int estado;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();
};

// Classe responsável por testar o funcionamento do domínio NumeroConta
class TUNumeroConta {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes para definir os valores a serem testados.
  const static int NUM_TESTES_FALHA;
  const static string VALOR_VALIDO;
  const static std::vector<string> VALOR_INVALIDO;

  // Referência para o objeto a ser testado.
  NumeroConta * numero_conta;

  // Estado do teste.
  int estado;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();
};

// Classe responsável por testar o funcionamento do domínio Senha
class TUSenha {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes para definir os valores a serem testados.
  const static int NUM_TESTES_FALHA;
  const static string VALOR_VALIDO;
  const static std::vector<string> VALOR_INVALIDO;

  // Referência para o objeto a ser testado.
  Senha * senha;

  // Estado do teste.
  int estado;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();
};

// Classe responsável por testar o funcionamento do domínio TipoAcomod
class TUTipoAcomod {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes para definir os valores a serem testados.
  const static int NUM_TESTES_SUCESSO;
  const static std::vector<string> VALOR_VALIDO;
  const static string VALOR_INVALIDO;

  // Referência para o objeto a ser testado.
  TipoAcomod * tipo_acomod;

  // Estado do teste.
  int estado;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();
};

#endif // TESTES_DOM_H_