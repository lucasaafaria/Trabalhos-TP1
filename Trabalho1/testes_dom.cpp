#include "dominios.h"
#include "testes_dom.h"

// Definições de constantes e métodos relativos aos Testes de Unidade (TU)
// dos domínios.

// Definições de constantes da classe TUAgencia.
const int TUAgencia::SUCESSO;
const int TUAgencia::FALHA;
const int TUAgencia::NUM_TESTES_FALHA               = 5;
const std::string TUAgencia::VALOR_VALIDO           = "12345";
const std::vector<string> TUAgencia::VALOR_INVALIDO = {"123456", "!2345", "ABCDE", "", "01"};

// Definições de métodos da classe TUAgencia.

// Cria um ponteiro para o objeto a ser testado e inicializa o estado do teste
void TUAgencia::setUp() {
  agencia = new Agencia;
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUAgencia::tearDown() {
  delete agencia;
}


// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUAgencia::testarCenarioSucesso() {
  try {
    agencia->setAgencia(VALOR_VALIDO);
    if (agencia->getAgencia() != VALOR_VALIDO)
      estado = FALHA;
  }
  catch(invalid_argument excecao) {
    estado = FALHA;
  }
}

// Testa a validação, o método set e o método get para entradas inválidas.
// Lança exceção para todos os casos se o teste for bem sucedido
void TUAgencia::testarCenarioFalha() {
  for (int i = 0; i < NUM_TESTES_FALHA; ++i) {
    try {
      agencia->setAgencia(VALOR_INVALIDO[i]);
      estado = FALHA;
    }
    catch(invalid_argument excecao) {
      continue;
    }
  }
}

// Rotina de testes
int TUAgencia::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}


//Definições de constantes da classe TUBanco.
const int TUBanco::SUCESSO;
const int TUBanco::FALHA;
const int TUBanco::NUM_TESTES_FALHA                 = 5;
const std::string TUBanco::VALOR_VALIDO             = "123";
const std::vector<string> TUBanco::VALOR_INVALIDO   = {"1234", "!23", "ABC", "", "1"};

// Definições de métodos da classe TUBanco.

// Cria um ponteiro para o objeto a ser testado e inicializa o estado do teste.
void TUBanco::setUp() {
  banco = new Banco;
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste.
void TUBanco::tearDown() {
  delete banco;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUBanco::testarCenarioSucesso() {
  try {
    banco->setBanco(VALOR_VALIDO);
    if (banco->getBanco() != VALOR_VALIDO)
      estado = FALHA;
  }
  catch(invalid_argument excecao) {
    estado = FALHA;
  }
}

// Testa a validação, o método set e o método get para entradas inválidas.
// Lança exceção para todos os casos se o teste for bem sucedido.
void TUBanco::testarCenarioFalha() {
  for (int i = 0; i < NUM_TESTES_FALHA; ++i) {
    try {
      banco->setBanco(VALOR_INVALIDO[i]);
      estado = FALHA;
    }
    catch(invalid_argument excecao) {
      continue;
    }
  }
}

// Rotina de testes
int TUBanco::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

//Definições de constantes da classe TUCapacidade.
const int TUCapacidade::SUCESSO;
const int TUCapacidade::FALHA;
const int TUCapacidade::NUM_TESTES_FALHA            = 5;
const int TUCapacidade::VALOR_VALIDO                = 4;
const std::vector<int> TUCapacidade::VALOR_INVALIDO = {0, -1, 'A', 1000, 10};

// Definições de métodos da classe TUCapacidade.

// Cria um ponteiro para o objeto a ser testado e inicializa o estado do teste
void TUCapacidade::setUp() {
  capacidade = new Capacidade;
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUCapacidade::tearDown() {
  delete capacidade;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUCapacidade::testarCenarioSucesso() {
  try {
    capacidade->setCapacidade(VALOR_VALIDO);
    if (capacidade->getCapacidade() != VALOR_VALIDO)
      estado = FALHA;
  }
  catch(invalid_argument excecao) {
    estado = FALHA;
  }
}

// Testa a validação, o método set e o método get para entradas inválidas.
// Lança exceção para todos os casos se o teste for bem sucedido
void TUCapacidade::testarCenarioFalha() {
  for (int i = 0; i < NUM_TESTES_FALHA; ++i) {
    try {
      capacidade->setCapacidade(VALOR_INVALIDO[i]);
      estado = FALHA;
    }
    catch(invalid_argument excecao) {
      continue;
    }
  }
}

// Rotina de testes
int TUCapacidade::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

//Definições de constantes da classe TUDiaria.
const int TUDiaria::SUCESSO;
const int TUDiaria::FALHA;
const int TUDiaria::NUM_TESTES_FALHA                = 4;
const float TUDiaria::VALOR_VALIDO                  = 1500.55;
const std::vector<float> TUDiaria::VALOR_INVALIDO   = {0, -1, 10000.1, 100000};

// Definições de métodos da classe TUDiaria.

// Cria um ponteiro para o objeto a ser testado e inicializa o estado do teste
void TUDiaria::setUp() {
  diaria = new Diaria;
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUDiaria::tearDown() {
  delete diaria;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUDiaria::testarCenarioSucesso() {
  try {
    diaria->setDiaria(VALOR_VALIDO);
    if (diaria->getDiaria() != VALOR_VALIDO)
      estado = FALHA;
  }
  catch(invalid_argument excecao) {
    estado = FALHA;
  }
}

// Testa a validação, o método set e o método get para entradas inválidas.
// Lança exceção para todos os casos se o teste for bem sucedido
void TUDiaria::testarCenarioFalha() {
  for (int i = 0; i < NUM_TESTES_FALHA; ++i) {
    try {
      diaria->setDiaria(VALOR_INVALIDO[i]);
      estado = FALHA;
    }
    catch(invalid_argument excecao) {
      continue;
    }
  }
}

// Rotina de testes
int TUDiaria::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

//Definições de constantes da classe TUData.
const int TUData::SUCESSO;
const int TUData::FALHA;
const int TUData::NUM_TESTES_SUCESSO                = 3;
const int TUData::NUM_TESTES_FALHA                  = 5;
const std::vector<string> TUData::VALOR_VALIDO      = {"25/nov/2000", "29/fev/2016", "31/dez/2099"};
const std::vector<string> TUData::VALOR_INVALIDO    = {"25/nov/1998", "25|nov|2000", "29/fev/2018", "", "31/nov/2012"};

// Definições de métodos da classe TUData.

// Cria um ponteiro para o objeto a ser testado e inicializa o estado do teste
void TUData::setUp() {
  data = new Data;
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUData::tearDown() {
  delete data;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUData::testarCenarioSucesso() {
  for (int i = 0; i < NUM_TESTES_SUCESSO; ++i) {
    try {
      data->setData(VALOR_VALIDO[i]);
      if (data->getData() != VALOR_VALIDO[i]) {
        estado = FALHA;
      }
    }
    catch(invalid_argument excecao) {
      estado = FALHA;
    }
  }
}

// Testa a validação, o método set e o método get para entradas inválidas.
// Lança exceção para todos os casos se o teste for bem sucedido
void TUData::testarCenarioFalha() {
  for (int i = 0; i < NUM_TESTES_FALHA; ++i) {
    try {
      data->setData(VALOR_INVALIDO[i]);
      estado = FALHA;
    }
    catch(invalid_argument excecao) {
      continue;
    }
  }
}

// Rotina de testes
int TUData::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

//Definições de constantes da classe TUValidade.
const int TUValidade::SUCESSO;
const int TUValidade::FALHA;
const int TUValidade::NUM_TESTES_SUCESSO                = 3;
const int TUValidade::NUM_TESTES_FALHA                  = 5;
const std::vector<string> TUValidade::VALOR_VALIDO      = {"01/00", "05/50", "12/99"};
const std::vector<string> TUValidade::VALOR_INVALIDO    = {"00/00", "01|00", "001/00", "", "13/99"};

// Definições de métodos da classe TUValidade.

// Cria um ponteiro para o objeto a ser testado e inicializa o estado do teste
void TUValidade::setUp() {
  validade = new Validade;
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUValidade::tearDown() {
  delete validade;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUValidade::testarCenarioSucesso() {
  for (int i = 0; i < NUM_TESTES_SUCESSO; ++i) {
    try {
      validade->setValidade(VALOR_VALIDO[i]);
      if (validade->getValidade() != VALOR_VALIDO[i]) {
        estado = FALHA;
      }
    }
    catch(invalid_argument excecao) {
      estado = FALHA;
    }
  }
}

// Testa a validação, o método set e o método get para entradas inválidas.
// Lança exceção para todos os casos se o teste for bem sucedido
void TUValidade::testarCenarioFalha() {
  for (int i = 0; i < NUM_TESTES_FALHA; ++i) {
    try {
      validade->setValidade(VALOR_INVALIDO[i]);
      estado = FALHA;
    }
    catch(invalid_argument excecao) {
      continue;
    }
  }
}

// Rotina de testes
int TUValidade::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

//Definições de constantes da classe TUEstado.
const int TUEstado::SUCESSO;
const int TUEstado::FALHA;
const int TUEstado::NUM_TESTES_SUCESSO                  = 3;
const int TUEstado::NUM_TESTES_FALHA                    = 5;
const std::vector<std::string> TUEstado::VALOR_VALIDO   = {"DF", "df", "dF"};
const std::vector<std::string> TUEstado::VALOR_INVALIDO = {"DF1", "12", "WX", "", "A"};

// Definições de métodos da classe TUEstado.

// Cria um ponteiro para o objeto a ser testado e inicializa o estado do teste
void TUEstado::setUp() {
  estado = new Estado;
  estado_teste = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUEstado::tearDown() {
  delete estado;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUEstado::testarCenarioSucesso() {
  for (int i = 0; i < NUM_TESTES_SUCESSO; ++i) {
    try {
      estado->setEstado(VALOR_VALIDO[i]);
    }
    catch(invalid_argument excecao) {
      estado_teste = FALHA;
    }
  }
}

// Testa a validação, o método set e o método get para entradas inválidas.
// Lança exceção para todos os casos se o teste for bem sucedido
void TUEstado::testarCenarioFalha() {
  for (int i = 0; i < NUM_TESTES_FALHA; ++i) {
    try {
      estado->setEstado(VALOR_INVALIDO[i]);
      estado_teste = FALHA;
    }
    catch(invalid_argument excecao) {
      continue;
    }
  }
}

// Rotina de testes
int TUEstado::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado_teste;
}

//Definições de constantes da classe TUIdentificador.
const int TUIdentificador::SUCESSO;
const int TUIdentificador::FALHA;
const int TUIdentificador::NUM_TESTES_SUCESSO               = 3;
const int TUIdentificador::NUM_TESTES_FALHA                 = 5;
const std::vector<string> TUIdentificador::VALOR_VALIDO   = {"abcde", "abcDE", "ABCDE"};
const std::vector<string> TUIdentificador::VALOR_INVALIDO = {"abcdef", "abcd1", "a@bcd", "", "ab"};

// Definições de métodos da classe TUIdentificador.

// Cria um ponteiro para o objeto a ser testado e inicializa o estado do teste
void TUIdentificador::setUp() {
  identificador = new Identificador;
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUIdentificador::tearDown() {
  delete identificador;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUIdentificador::testarCenarioSucesso() {
  for (int i = 0; i < NUM_TESTES_SUCESSO; ++i) {
    try {
      identificador->setIdentificador(VALOR_VALIDO[i]);
    }
    catch(invalid_argument excecao) {
      estado = FALHA;
    }
  }
}

// Testa a validação, o método set e o método get para entradas inválidas.
// Lança exceção para todos os casos se o teste for bem sucedido
void TUIdentificador::testarCenarioFalha() {
  for (int i = 0; i < NUM_TESTES_FALHA; ++i) {
    try {
      identificador->setIdentificador(VALOR_INVALIDO[i]);
      estado = FALHA;
    }
    catch(invalid_argument excecao) {
      continue;
    }
  }
}

// Rotina de testes
int TUIdentificador::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

//Definições de constantes da classe TUNome.
const int TUNome::SUCESSO;
const int TUNome::FALHA;
const int TUNome::NUM_TESTES_SUCESSO                = 3;
const int TUNome::NUM_TESTES_FALHA                = 5;
const std::vector<string> TUNome::VALOR_VALIDO      = {"Lucas Faria", "Luis.Felipe", "Nome"};
const std::vector<string> TUNome::VALOR_INVALIDO    = {".Lucas", "Lucas  Faria", "Nome muito grande", "", "12345"};

// Definições de métodos da classe TUNome.

// Cria um ponteiro para o objeto a ser testado e inicializa o estado do teste
void TUNome::setUp() {
  nome = new Nome;
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUNome::tearDown() {
  delete nome;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUNome::testarCenarioSucesso() {
  for (int i = 0; i < NUM_TESTES_SUCESSO; ++i) {
    try {
      nome->setNome(VALOR_VALIDO[i]);
      if (nome->getNome() != VALOR_VALIDO[i]) {
        estado = FALHA;
      }
    }
    catch(invalid_argument excecao) {
      estado = FALHA;
    }
  }
}

// Testa a validação, o método set e o método get para entradas inválidas.
// Lança exceção para todos os casos se o teste for bem sucedido
void TUNome::testarCenarioFalha() {
  for (int i = 0; i < NUM_TESTES_FALHA; ++i) {
    try {
      nome->setNome(VALOR_INVALIDO[i]);
      estado = FALHA;
    }
    catch(invalid_argument excecao) {
      continue;
    }
  }
}

// Rotina de testes
int TUNome::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

//Definições de constantes da classe TUNumeroCartao.
const int TUNumeroCartao::SUCESSO;
const int TUNumeroCartao::FALHA;
const std::string TUNumeroCartao::VALOR_VALIDO      = "4001761912449111";
const std::string TUNumeroCartao::VALOR_INVALIDO    = "4001761912449112";

// Definições de métodos da classe TUNumeroCartao.

// Cria um ponteiro para o objeto a ser testado e inicializa o estado do teste
void TUNumeroCartao::setUp() {
  numero_cartao = new NumeroCartao;
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUNumeroCartao::tearDown() {
  delete numero_cartao;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUNumeroCartao::testarCenarioSucesso() {
  try {
    numero_cartao->setNumeroCartao(VALOR_VALIDO);
    if (numero_cartao->getNumeroCartao() != VALOR_VALIDO)
      estado = FALHA;
  }
  catch(invalid_argument excecao) {
    estado = FALHA;
  }
}

// Testa a validação, o método set e o método get para entradas inválidas.
// Lança exceção para todos os casos se o teste for bem sucedido
void TUNumeroCartao::testarCenarioFalha() {
  try {
    numero_cartao->setNumeroCartao(VALOR_INVALIDO);
    estado = FALHA;
  }
  catch(invalid_argument excecao) {
    return;
  }
}

// Rotina de testes
int TUNumeroCartao::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

//Definições de constantes da classe TUNumeroConta.
const int TUNumeroConta::SUCESSO;
const int TUNumeroConta::FALHA;
const int TUNumeroConta::NUM_TESTES_FALHA               = 5;
const std::string TUNumeroConta::VALOR_VALIDO           = "123456";
const std::vector<string> TUNumeroConta::VALOR_INVALIDO = {"1234567", "!23456", "ABCDEF", "", "01"};

// Definições de métodos da classe TUNumeroConta.

// Cria um ponteiro para o objeto a ser testado e inicializa o estado do teste
void TUNumeroConta::setUp() {
  numero_conta = new NumeroConta;
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUNumeroConta::tearDown() {
  delete numero_conta;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUNumeroConta::testarCenarioSucesso() {
  try {
    numero_conta->setNumeroConta(VALOR_VALIDO);
    if (numero_conta->getNumeroConta() != VALOR_VALIDO)
      estado = FALHA;
  }
  catch(invalid_argument excecao) {
    estado = FALHA;
  }
}

// Testa a validação, o método set e o método get para entradas inválidas.
// Lança exceção para todos os casos se o teste for bem sucedido
void TUNumeroConta::testarCenarioFalha() {
  for (int i = 0; i < NUM_TESTES_FALHA; ++i) {
    try {
      numero_conta->setNumeroConta(VALOR_INVALIDO[i]);
      estado = FALHA;
    }
    catch(invalid_argument excecao) {
      continue;
    }
  }
}

// Rotina de testes
int TUNumeroConta::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

//Definições de constantes da classe TUSenha.
const int TUSenha::SUCESSO;
const int TUSenha::FALHA;
const int TUSenha::NUM_TESTES_FALHA                 = 8;
const std::string TUSenha::VALOR_VALIDO             = "Ab!1Cd#2";
const std::vector<string> TUSenha::VALOR_INVALIDO   = {"Ab!1Cd#23", "Ab!1Ab!1", "ABCDEFGH", "",
                                                       "01", "abcdefgh", "!#$%&abc", "12345678"};

// Definições de métodos da classe TUSenha.

// Cria um ponteiro para o objeto a ser testado e inicializa o estado do teste
void TUSenha::setUp() {
  senha = new Senha;
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUSenha::tearDown() {
  delete senha;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUSenha::testarCenarioSucesso() {
  try {
    senha->setSenha(VALOR_VALIDO);
    if (senha->getSenha() != VALOR_VALIDO)
      estado = FALHA;
  }
  catch(invalid_argument excecao) {
    estado = FALHA;
  }
}

// Testa a validação, o método set e o método get para entradas inválidas.
// Lança exceção para todos os casos se o teste for bem sucedido
void TUSenha::testarCenarioFalha() {
  for (int i = 0; i < NUM_TESTES_FALHA; ++i) {
    try {
      senha->setSenha(VALOR_INVALIDO[i]);
      estado = FALHA;
    }
    catch(invalid_argument excecao) {
      continue;
    }
  }
}

// Rotina de testes
int TUSenha::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

//Definições de constantes da classe TUTipoAcomod.
const int TUTipoAcomod::SUCESSO;
const int TUTipoAcomod::FALHA;
const int TUTipoAcomod::NUM_TESTES_SUCESSO              = 3;
const std::vector<string> TUTipoAcomod::VALOR_VALIDO    = {"Apartamento", "Casa", "Flat"};
const std::string TUTipoAcomod::VALOR_INVALIDO          = "Quarto";

// Definições de métodos da classe TUTipoAcomod.

// Cria um ponteiro para o objeto a ser testado e inicializa o estado do teste
void TUTipoAcomod::setUp() {
  tipo_acomod = new TipoAcomod;
  estado = SUCESSO;
}

// Libera o espaço de memória ocupado pelo objeto de teste
void TUTipoAcomod::tearDown() {
  delete tipo_acomod;
}

// Testa a validação, o método set e o método get para entradas válidas.
// Não altera o estado do teste nem lança exceção se o teste for bem sucedido.
void TUTipoAcomod::testarCenarioSucesso() {
  for (int i = 0; i < NUM_TESTES_SUCESSO; ++i) {
    try {
      tipo_acomod->setTipoAcomod(VALOR_VALIDO[i]);
      if (tipo_acomod->getTipoAcomod() != VALOR_VALIDO[i])
        estado = FALHA;
    }
    catch(invalid_argument excecao) {
      estado = FALHA;
    }
  }
}

// Testa a validação, o método set e o método get para entradas inválidas.
// Lança exceção para todos os casos se o teste for bem sucedido
void TUTipoAcomod::testarCenarioFalha() {
  try {
    tipo_acomod->setTipoAcomod(VALOR_INVALIDO);
    estado = FALHA;
  }
  catch(invalid_argument excecao) {
    return;
  }
}

// Rotina de testes
int TUTipoAcomod::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}