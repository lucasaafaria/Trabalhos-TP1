#include "dominios.h"
#include "entidades.h"
#include "testes_ent.h"

// Definições de constantes e métodos dos Testes de Unidade (TU)
// referentes às entidades.

//Definições de constantes da classe TUUsuario.
const int TUUsuario::SUCESSO;
const int TUUsuario::FALHA;
const std::string TUUsuario::NOME          = "Lucas Faria";
const std::string TUUsuario::IDENTIFICADOR = "abcde";
const std::string TUUsuario::SENHA         = "Ab!1Cd#2";

// Definições de métodos da classe TUUsuario.

// Inicializa os objetos auxiliares e cria um ponteiro para o 
// objeto a ser testado.
void TUUsuario::setUp() {
  nome.setNome(NOME);
  identificador.setIdentificador(IDENTIFICADOR);
  senha.setSenha(SENHA);
  usuario = new Usuario(nome, identificador, senha);
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUUsuario::tearDown() {
  delete usuario;
}

// Testa se os métodos de manipulação do objeto de teste funcionam corretamente.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUUsuario::testarCenarioSucesso() {
  try {
    nome_teste          = usuario->getNome();
    identificador_teste = usuario->getIdentificador();
    senha_teste         = usuario->getSenha();

    if (nome_teste.getNome() != NOME)
      estado = FALHA;

    if (identificador_teste.getIdentificador() != IDENTIFICADOR)
      estado = FALHA;

    if (senha_teste.getSenha() != SENHA)
      estado = FALHA;
  }
  catch(invalid_argument excecao) {
    estado = FALHA;
  }
}

// Rotina do teste.
int TUUsuario::run() {
  setUp();
  testarCenarioSucesso();
  tearDown();
  return estado;
}

//Definições de constantes da classe TUAcomodacao.
const int TUAcomodacao::SUCESSO;
const int TUAcomodacao::FALHA;
const std::string TUAcomodacao::IDENTIFICADOR   = "abcde";
const std::string TUAcomodacao::TIPOACOMOD      = "Apartamento";
const int         TUAcomodacao::CAPACIDADE      = 4;
const std::string TUAcomodacao::DATAINICIO      = "02/out/2018";
const std::string TUAcomodacao::DATATERMINO     = "07/dez/2018";
const std::string TUAcomodacao::CIDADE          = "Brasilia";
const std::string TUAcomodacao::ESTADO          = "DF";
const float       TUAcomodacao::DIARIA          = 12;

// Definições de métodos da classe TUAcomodacao.
// Inicializa os objetos auxiliares e cria o um ponteiro para o 
// objeto a ser testado.
void TUAcomodacao::setUp() {
  identificador.setIdentificador(IDENTIFICADOR);
  tipo_acomod.setTipoAcomod(TIPOACOMOD);
  capacidade.setCapacidade(CAPACIDADE);
  data_inicio.setData(DATAINICIO);
  data_termino.setData(DATATERMINO);
  cidade.setNome(CIDADE);
  estado.setEstado(ESTADO);
  diaria.setDiaria(DIARIA);
  acomodacao = new Acomodacao(identificador, tipo_acomod, capacidade, data_inicio, data_termino, cidade, estado, diaria);
  resultado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUAcomodacao::tearDown() {
  delete acomodacao;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUAcomodacao::testarCenarioSucesso() {
  try {
    identificador_teste = acomodacao->getIdentificador();
    tipo_acomod_teste   = acomodacao->getTipoAcomod();
    capacidade_teste    = acomodacao->getCapacidade();
    data_inicio_teste   = acomodacao->getDataInicio();
    data_termino_teste  = acomodacao->getDataTermino();
    cidade_teste        = acomodacao->getCidade();
    estado_teste        = acomodacao->getEstado();
    diaria_teste        = acomodacao->getDiaria();

    if (identificador_teste.getIdentificador() != IDENTIFICADOR)
      resultado = FALHA;

    if (tipo_acomod_teste.getTipoAcomod() != TIPOACOMOD)
      resultado = FALHA;

    if (capacidade_teste.getCapacidade() != CAPACIDADE)
      resultado = FALHA;

    if (data_inicio_teste.getData() != DATAINICIO)
      resultado = FALHA;

    if (data_termino_teste.getData() != DATATERMINO)
      resultado = FALHA;

    if (cidade_teste.getNome() != CIDADE)
      resultado = FALHA;

    if (estado_teste.getEstado() != ESTADO)
      resultado = FALHA;

    if (diaria_teste.getDiaria() != DIARIA)
      resultado = FALHA;
  }
  catch(invalid_argument excecao) {
    resultado = FALHA;
  }
}

// Rotina do teste.
int TUAcomodacao::run() {
  setUp();
  testarCenarioSucesso();
  tearDown();
  return resultado;
}

//Definições de constantes da classe TUCartaoCredito.
const int TUCartaoCredito::SUCESSO;
const int TUCartaoCredito::FALHA;
const std::string TUCartaoCredito::NUMEROCARTAO  = "4001761912449111";
const std::string TUCartaoCredito::VALIDADE      = "12/12";

// Definições de métodos da classe TUCartaoCredito.
// Inicializa os objetos auxiliares e cria o um ponteiro para o 
// objeto a ser testado.
void TUCartaoCredito::setUp() {
  numero_cartao.setNumeroCartao(NUMEROCARTAO);
  validade.setValidade(VALIDADE);
  cartao_credito = new CartaoCredito(numero_cartao, validade);
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUCartaoCredito::tearDown() {
  delete cartao_credito;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUCartaoCredito::testarCenarioSucesso() {
  try {
    numero_cartao_teste = cartao_credito->getNumeroCartao();
    validade_teste = cartao_credito->getValidade();

    if (numero_cartao_teste.getNumeroCartao() != NUMEROCARTAO)
      estado = FALHA;

    if (validade_teste.getValidade() != VALIDADE)
      estado = FALHA;
  }
  catch(invalid_argument excecao) {
    estado = FALHA;
  }
}

// Rotina do teste.
int TUCartaoCredito::run() {
  setUp();
  testarCenarioSucesso();
  tearDown();
  return estado;
}

//Definições de constantes da classe TUContaCorrente.
const int TUContaCorrente::SUCESSO;
const int TUContaCorrente::FALHA;
const std::string TUContaCorrente::NUMEROCONTA  = "123456";
const std::string TUContaCorrente::AGENCIA      = "12345";
const std::string TUContaCorrente::BANCO        = "123";

// Definições de métodos da classe TUContaCorrente.
// Inicializa os objetos auxiliares e cria o um ponteiro para o 
// objeto a ser testado.
void TUContaCorrente::setUp() {
  numero_conta.setNumeroConta(NUMEROCONTA);
  agencia.setAgencia(AGENCIA);
  banco.setBanco(BANCO);
  conta_corrente = new ContaCorrente(numero_conta, agencia, banco);
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUContaCorrente::tearDown() {
  delete conta_corrente;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUContaCorrente::testarCenarioSucesso() {
  try {
    numero_conta_teste  = conta_corrente->getNumeroConta();
    agencia_teste       = conta_corrente->getAgencia();
    banco_teste         = conta_corrente->getBanco();

    if (numero_conta_teste.getNumeroConta() != NUMEROCONTA)
      estado = FALHA;

    if (agencia_teste.getAgencia() != AGENCIA)
      estado = FALHA;

    if (banco_teste.getBanco() != BANCO)
      estado = FALHA;
  }
  catch(invalid_argument excecao) {
    estado = FALHA;
  }
}

// Rotina do teste.
int TUContaCorrente::run() {
  setUp();
  testarCenarioSucesso();
  tearDown();
  return estado;
}