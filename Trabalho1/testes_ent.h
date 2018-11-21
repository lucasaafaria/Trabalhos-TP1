#ifndef TESTES_ENT_H_
#define TESTES_ENT_H_

#include "dominios.h"
#include "entidades.h"

// Declaração dos Testes de Unidade (TU) de cada entidade

// Classe responsável por testar o funcionamento da entidade Usuario
class TUUsuario {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes que definem os valores a serem testados.
  const static std::string NOME;
  const static std::string IDENTIFICADOR;
  const static std::string SENHA;

  // Referência para o objeto a ser testado.
  Usuario * usuario;

  // Objetos auxiliares para o teste.
  Nome nome, nome_teste;
  Identificador identificador, identificador_teste;
  Senha senha, senha_teste;

  // Estado do teste.
  int estado;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
};

// Classe responsável por testar o funcionamento da entidade Acomodacao
class TUAcomodacao {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes que definem os valores a serem testados.
  const static std::string IDENTIFICADOR;
  const static std::string TIPOACOMOD;
  const static int         CAPACIDADE;
  const static std::string DATAINICIO;
  const static std::string DATATERMINO;
  const static std::string CIDADE;
  const static std::string ESTADO;
  const static float       DIARIA; 

  // Referência para o objeto a ser testado.
  Acomodacao * acomodacao;

  // Objetos auxiliares para o teste.
  Identificador identificador, identificador_teste;
  TipoAcomod tipo_acomod, tipo_acomod_teste;
  Capacidade capacidade, capacidade_teste;
  Data data_inicio, data_inicio_teste;
  Data data_termino, data_termino_teste;
  Nome cidade, cidade_teste;
  Estado estado, estado_teste;
  Diaria diaria, diaria_teste;

  // Resultado do teste.
  int resultado;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
};

// Classe responsável por testar o funcionamento da entidade CartaoCredito
class TUCartaoCredito {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes que definem os valores a serem testados.
  const static std::string NUMEROCARTAO;
  const static std::string VALIDADE;

  // Referência para o objeto a ser testado.
  CartaoCredito * cartao_credito;

  // Objetos auxiliares para o teste.
  NumeroCartao numero_cartao, numero_cartao_teste;
  Validade validade, validade_teste;

  // Estado do teste.
  int estado;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
};

// Classe responsável por testar o funcionamento da entidade ContaCorrente
class TUContaCorrente {
public:
  // Definições de constantes para reportar resultado do teste.
  const static int SUCESSO = 0;
  const static int FALHA = -1;

  int run();

private:
  // Constantes que definem os valores a serem testados.
  const static std::string NUMEROCONTA;
  const static std::string AGENCIA;
  const static std::string BANCO;

  // Referência para o objeto a ser testado.
  ContaCorrente * conta_corrente;

  // Objetos auxiliares para o teste.
  NumeroConta numero_conta, numero_conta_teste;
  Agencia agencia, agencia_teste;
  Banco banco, banco_teste;

  // Estado do teste.
  int estado;

  // Declarações de métodos.
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
};

#endif // TESTES_ENT_H_