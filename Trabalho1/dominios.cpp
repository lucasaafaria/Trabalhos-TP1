#include <cctype>
#include <cstdlib>

#include "dominios.h"

// Definição de métodos e constantes referentes aos domínios

// Métodos da classe Agencia:

// Critérios de validação: tamanho fixo de 5 caracteres, todos devem
// ser dígitos de 0 a 9.
void Agencia::validar(const string &agencia) {
  if (agencia.length() != TAMANHO)
    throw invalid_argument("Argumento inválido");

  for (int i = 0; i < TAMANHO; ++i) {
    if (!isdigit(agencia[i]))
      throw invalid_argument("Argumento inválido");   
  }
}

void Agencia::setAgencia(string agencia) {
  validar(agencia);
  this->agencia = agencia;
}

// Métodos da classe Banco:

// Critérios de validação: tamanho fixo de 3 caracteres, todos devem
// ser dígitos de 0 a 9.
void Banco::validar(const string &banco) {
  if (banco.length() != TAMANHO)
    throw invalid_argument("Argumento inválido");

  for (int i = 0; i < TAMANHO; ++i) {
    if (!isdigit(banco[i]))
      throw invalid_argument("Argumento inválido");   
  }
}

void Banco::setBanco(string banco) {
  validar(banco);
  this->banco = banco;
}

// Métodos da classe Capacidade:

// Critério de validação: deve ser um número inteiro entre 1 e 9.
void Capacidade::validar(const int &capacidade) {
  if (capacidade < VALOR_MIN || capacidade > VALOR_MAX)
    throw invalid_argument("Argumento inválido");
}

void Capacidade::setCapacidade(int capacidade) {
  validar(capacidade);
  this->capacidade = capacidade;
}

// Métodos da classe Diaria:

// Critérios de validação: deve ser um número real entre 1 e 10000.
void Diaria::validar(const float &diaria) {
  if (diaria < PRECO_MIN || diaria > PRECO_MAX)
    throw invalid_argument("Argumento inválido");
}

void Diaria::setDiaria(float diaria) {
  validar(diaria);
  this->diaria = diaria;
}

// Vetor que define os valores válidos para a entrada de mês.
const std::vector<string> Data::MESES = {"jan", "fev", "mar", "abr", "mai", "jun",
                                         "jul", "ago", "set", "out", "nov", "dez"};

// Métodos da classe Data:

// Retorna 1 caso o ano seja bissexto, 0 caso contrário                    
int Data::ehbissexto(const int &ano) {
  return (!(ano%4) && (ano%100) || !(ano%400));
}

// Retorna 1 caso as barras da data estejam na posição correta na string,
// 0 caso contrário.
int Data::checaBarras(const string &data) {
  return data[BARRA_1] == '/' && data[BARRA_2] == '/';
}

// Retorna 1 caso as substrings dia e ano só contenham dígitos e a substring
// mes corresponda a um valor válido. Retorna 0 caso contrário.
int Data::checaFormato(const string &dia, const string &mes, const string &ano) {
  int flag = VALIDO, flag_mes = INVALIDO;

  for (int i = 0; i < TAM_DIA; ++i) {
    if (!isdigit(dia[i]))
      flag = INVALIDO;
  }
  for (int i = 0; i < NUM_MESES; ++i) {
    if (mes == MESES[i])
      flag_mes = VALIDO;
  }
  for (int i = 0; i < TAM_ANO; ++i) {
    if (!isdigit(ano[i]))
      flag = INVALIDO;
  }

  return flag && flag_mes;
}

// Recebe o mês em formato de string, retorna o valor númerico do mês (0 a 11).
int Data::numMes(const string &mes) {
  int num;

  for (int i = 0; i < NUM_MESES; ++i) {
    if (mes == MESES[i]) {
      num = i;
      break;
    }   
  }

  return num;
}

// Critérios de validação: tamanho fixo de 11 caracteres; caracteres
// correspondentes a dia e ano devem ser dígitos de 0 a 9; mes deve ser
// algum dos valores válidos especificados; respeita os limites de dias
// por mês no calendário gregoriano; leva em consideração anos bissextos;
// anos válidos são de 2000 a 2099;
void Data::validar(const string &data) {
  string dia, mes, ano;
  int int_dia, int_mes, int_ano;
  int dias_no_mes[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (data.length() != TAMANHO)
    throw invalid_argument("Argumento inválido");

  dia = data.substr(POS_DIA, TAM_DIA);
  mes = data.substr(POS_MES, TAM_MES);
  ano = data.substr(POS_ANO, TAM_ANO);

  if (!(checaBarras(data) && checaFormato(dia, mes, ano)))
    throw invalid_argument("Argumento inválido");

  // Conversão de string para inteiro
  int_dia = atoi(dia.data());
  int_mes = numMes(mes);
  int_ano = atoi(ano.data());

  if (int_ano < ANO_MIN || int_ano > ANO_MAX)
    throw invalid_argument("Argumento inválido");

  if (ehbissexto(int_ano) && mes == "fev")
    ++dias_no_mes[int_mes];

  if (int_dia > dias_no_mes[int_mes] || int_dia < DIA_MIN)
    throw invalid_argument("Argumento inválido");
}

void Data::setData(string data) {
  validar(data);
  this->data = data;
}

// Métodos da classe Validade:

// Retorna 1 caso a barra da data esteja na posição correta na string,
// 0 caso contrário.
int Validade::checaBarra(const string &validade) {
  return validade[BARRA] == '/';
}

// Retorna 1 caso as substrings mes e ano só contenham dígitos,
// 0 caso contrário.
int Validade::checaFormato(const string &mes, const string &ano) {
  int flag = VALIDO;

  for (int i = 0; i < TAM_MES; ++i) {
    if (!isdigit(mes[i]))
      flag = INVALIDO;
  }
  for (int i = 0; i < TAM_ANO; ++i) {
    if (!isdigit(ano[i]))
      flag = INVALIDO;
  }

  return flag;
}

// Critérios de validação: tamanho fixo de 5 caracteres; caracteres
// correspondentes a mes e ano devem ser dígitos de 0 a 9; mes deve estar
// entre 01 e 12; ano deve estar entre 00 e 99.
void Validade::validar(const string &validade) {
  string mes, ano;
  int int_mes, int_ano;
  
  if (validade.length() != TAMANHO)
    throw invalid_argument("Argumento inválido");

  mes = validade.substr(POS_MES, TAM_MES);
  ano = validade.substr(POS_ANO, TAM_ANO);

  if (!(checaBarra(validade) && checaFormato(mes, ano)))
    throw invalid_argument("Argumento inválido");

  // Conversão de string para inteiro
  int_mes = atoi(mes.data());
  int_ano = atoi(ano.data());

  if (int_ano < ANO_MIN || int_ano > ANO_MAX)
    throw invalid_argument("Argumento inválido");

  if (int_mes < MES_MIN || int_mes > MES_MAX)
    throw invalid_argument("Argumento inválido");
}

void Validade::setValidade(string validade) {
  validar(validade);
  this->validade = validade;
}


// Vetor que define as siglas de estados válidas
const std::vector<string> Estado::ESTADOS = {"AC", "AL", "AP", "AM", "BA", "CE", "DF",
                                             "ES", "GO", "MA", "MT", "MS", "MG", "PA",
                                             "PB", "PR", "PE", "PI", "RJ", "RN", "RS",
                                             "RO", "RR", "SC", "SP", "SE", "TO"};

// Métodos da classe Estado:

// Converte a string recebida para uppercase (maiúscula).                      
void Estado::formatar(string * estado) {
  std::transform(estado->begin(), estado->end(), estado->begin(), ::toupper);
}

// Critérios de validação: tamanho fixo de 2 caracteres; deve corresponder
// a uma das siglas válidas definidas em Estado::ESTADOS.
void Estado::validar(const string &estado) {
  int flag = INVALIDO;
  
  if (estado.length() != TAMANHO)
    throw invalid_argument("Argumento inválido");

  for (int i = 0; i < NUM_ESTADOS; ++i) {
    if (estado == ESTADOS[i])
      flag = VALIDO;
  }

  if (flag == INVALIDO)
    throw invalid_argument("Argumento inválido");
}

void Estado::setEstado(string estado) {
  formatar(&estado);
  validar(estado);
  this->estado = estado;
}

// Métodos da classe Identificador:

// Converte a string recebida para lowercase (minúscula).
void Identificador::formatar(string * identificador) {
  std::transform(identificador->begin(), identificador->end(),
   identificador->begin(), ::tolower);
}

// Critérios de validação: tamanho fixo de 5 caracteres; todos devem
// ser letras.
void Identificador::validar(const string &identificador) {
  if(identificador.length() != TAMANHO)
    throw invalid_argument("Argumento inválido");

  for(int i = 0; i < TAMANHO; ++i) {
    if(!islower(identificador[i]))
      throw invalid_argument("Argumento inválido");   
  }
}

void Identificador::setIdentificador(string identificador) {
  formatar(&identificador);
  validar(identificador);
  this->identificador = identificador;
}

// Métodos da classe Nome:

// Critérios de validação: tamanho mínimo de 1 caractere e máximo de 15;
// pode conter letras, espaços em branco e pontos; ponto é precedido de
// letra; não podem haver 2 espaços seguidos; deve haver ao menos 1 letra.
void Nome::validar(const string &nome) {
  int flag = INVALIDO;

  if (nome.length() < TAMANHO_MIN || nome.length() > TAMANHO_MAX)
    throw invalid_argument("Argumento inválido");

  for (int i = 0; i < nome.length(); ++i) {
    if (isalpha(nome[i]))
      flag = VALIDO;

    else if (nome[i] == ' ' && nome[i+1] == ' ')
      throw invalid_argument("Argumento inválido");

    else if (nome[i] == '.' && !isalpha(nome[i-1]))
      throw invalid_argument("Argumento inválido");

    else if (!isalpha(nome[i]) && nome[i] != '.' && nome[i] != ' ')
      throw invalid_argument("Argumento inválido");
  }

  if (flag == INVALIDO)
    throw invalid_argument("Argumento inválido");
}

void Nome::setNome(string nome) {
  validar(nome);
  this->nome = nome;
}

// Métodos da classe NumeroCartao:

// Algoritmo obtido em <https://en.wikipedia.org/wiki/Luhn_algorithm>
// para validar números de cartão de crédito. Retorna 1 se for válido,
// 0 caso contrário.
int NumeroCartao::checkLuhn(string pPurported) {
  int nSum       = 0;
  int nDigits    = numero_cartao.length();
  int nParity    = (nDigits-1) % 2;
  char cDigit[2] = "\0";

  for (int i = nDigits; i > 0 ; i--){
    cDigit[0]  = pPurported[i-1];
    int nDigit = atoi(cDigit);

    if (nParity == i % 2)
      nDigit = nDigit * 2;

    nSum += nDigit/10;
    nSum += nDigit%10;
  }

  return 0 == nSum % 10;
}

// Critérios de validação: tamanho fixo de 16 caracteres;
// algoritmo de Luhn.
void NumeroCartao::validar(const string &numero_cartao) {
  if (numero_cartao.length() != TAMANHO)
    throw invalid_argument("Argumento inválido");

  if (!checkLuhn(numero_cartao))
    throw invalid_argument("Argumento inválido");
}

void NumeroCartao::setNumeroCartao(string numero_cartao) {
  validar(numero_cartao);
  this->numero_cartao = numero_cartao;
}

// Métodos da classe NumeroConta:

// Critérios de validação: tamanho fixo de 6 caracteres;
// todos devem ser dígitos de 0 a 9;
void NumeroConta::validar(const string &numero_conta) {
  if (numero_conta.length() != TAMANHO)
    throw invalid_argument("Argumento inválido");

  for (int i = 0; i < TAMANHO; ++i) {
    if(!isdigit(numero_conta[i]))
      throw invalid_argument("Argumento inválido");   
  }
}

void NumeroConta::setNumeroConta(string numero_conta) {
  validar(numero_conta);
  this->numero_conta = numero_conta;
}

// Vetor que define os símbolos que podem ser usados na senha.
const std::vector<char> Senha::SIMBOLO = {'!', '#', '$', '%', '&'};

// Métodos da classe Senha:

// Retorna 1 caso o caractere seja um símbolo válido definido
// em Senha::SIMBOLO. Retorna 0 caso contrário.
int Senha::issymbol(char caractere) {
  int flag = INVALIDO;

  for (int i = 0; i < NUM_SIMBOLOS; ++i) {
    if (caractere = SIMBOLO[i])
      flag = VALIDO;
  }

  return flag;
}

// Critérios de validação: tamanho fixo de 8 caracteres;
// pode conter letras maiúsculas e minúsculas, dígitos e símbolos;
// deve conter pelo menos uma letra maiúscula, uma letra minuscula,
// um dígito e um símbolo; não podem haver caracteres repetidos.
void Senha::validar(const string &senha) {
  int upper = INVALIDO, lower = INVALIDO, digit = INVALIDO, symbol = INVALIDO;

  if (senha.length() != TAMANHO)
    throw invalid_argument("Argumento inválido");

  for (int i = 0; i < TAMANHO; ++i) {
    if (isupper(senha[i]))
      upper = VALIDO;
    else if (islower(senha[i]))
      lower = VALIDO;
    else if (isdigit(senha[i]))
      digit = VALIDO;   
    else if (issymbol(senha[i]))
      symbol = VALIDO;
    else
      throw invalid_argument("Argumento inválido");

    for (int j = 0; j < TAMANHO; ++j) {
      if (senha[i] == senha[j] && i != j)
        throw invalid_argument("Argumento inválido");
    }
  }

  if (!(upper && lower && digit && symbol))
    throw invalid_argument("Argumento inválido");
}

void Senha::setSenha(string senha) {
  validar(senha);
  this->senha = senha;
}

// Vetor que define os tipos de acomodação válidos
const std::vector<string> TipoAcomod::TIPOS = {"Apartamento", "Casa", "Flat"};

// Métodos da classe TipoAcomod:

// Critérios de validação: deve corresponder a um tipo válido
// definido em TipoAcomod::TIPOS;
void TipoAcomod::validar(const string &tipo_acomod) {
  int flag = INVALIDO;

  for (int i = 0; i < NUM_TIPOS; ++i) {
    if (tipo_acomod == TIPOS[i])
      flag = VALIDO;
  }

  if (flag == INVALIDO)
    throw invalid_argument("Argumento inválido");
}

void TipoAcomod::setTipoAcomod(string tipo_acomod) {
  validar(tipo_acomod);
  this->tipo_acomod = tipo_acomod;
}