#ifndef DOMINIOS_H_
#define DOMINIOS_H_

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// Declarações de classes que compõem os domínios do sistema

// Classe responsável por validar e guardar um número de agência bancária
class Agencia {
public:
  void setAgencia(string agencia);
  string getAgencia() const {
    return agencia;
  }

private:
  // Constante que indica limite usado na validação
  const static int TAMANHO = 5;

  string agencia;

  void validar(const string &agencia);
};

// Classe responsável por validar e guardar um número indicativo de banco
class Banco {
public:
  void setBanco(string banco);
  string getBanco() const {
    return banco;
  }

private:
  // Constante que indica limite usado na validação
  const static int TAMANHO = 3;

  string banco;

  void validar(const string &banco);
};

// Classe responsável por validar e guardar uma capacidade de acomodação
class Capacidade {
public:
  void setCapacidade(int capacidade);
  int getCapacidade() const {
    return capacidade;
  }

private:
  // Constantes que indicam limites usados na validação
  const static int VALOR_MIN = 1;
  const static int VALOR_MAX = 9;

  int capacidade;

  void validar(const int &capacidade);
};

// Classe responsável por validar e guardar o preço da diária de uma acomodação
class Diaria {
public:
  void setDiaria(float diaria);
  float getDiaria() const {
    return diaria;
  }

private:
  // Constantes que indicam limites usados na validação
  constexpr static float PRECO_MIN = 1.00;
  constexpr static float PRECO_MAX = 10000.00;

  float diaria;

  void validar(const float &diaria);
};

// Classe responsável por validar e guardar uma data
class Data {
public:
  void setData(string data);
  string getData() const {
    return data;
  }

private:
  // Constantes auxiliares usadas na validação
  const static int VALIDO   = 1;
  const static int INVALIDO = 0;
  // Constantes que indicam limites usados na validação
  const static int TAMANHO  = 11;
  const static int NUM_MESES  = 12;
  const static int ANO_MIN  = 2000;
  const static int ANO_MAX  = 2099;
  const static int DIA_MIN  = 1;
  // Constantes que indicam a posição inicial de cada campo na string
  const static int POS_DIA  = 0;
  const static int POS_MES  = 3;
  const static int POS_ANO  = 7;
  const static int BARRA_1  = 2;
  const static int BARRA_2  = 6;
  //Constantes que indicam o tamanho de cada campo na string
  const static int TAM_DIA  = 2;
  const static int TAM_MES  = 3;
  const static int TAM_ANO  = 4;
  const static std::vector<string> MESES;
  
  string data;

  // Funções auxiliares na validação de data
  int ehbissexto(const int &ano);
  int checaBarras(const string &data);
  int checaFormato(const string &dia, const string &mes, const string &ano);
  int numMes(const string &mes);

  void validar(const string &data);
};

// Classe responsável por validar e guardar uma data de validade
class Validade {
public:
  void setValidade(string validade);
  string getValidade() const {
    return validade;
  }

private:
  // Constantes auxiliares usadas na validação
  const static int VALIDO   = 1;
  const static int INVALIDO = 0;
  // Constantes que indicam limites usados na validação
  const static int TAMANHO  = 5;
  const static int ANO_MIN  = 00;
  const static int ANO_MAX  = 99;
  const static int MES_MIN  = 1;
  const static int MES_MAX  = 12;
  // Constantes que indicam a posição inicial de cada campo na string
  const static int POS_MES  = 0;
  const static int POS_ANO  = 3;
  const static int BARRA    = 2;
  //Constantes que indicam o tamanho de cada campo na string
  const static int TAM_MES  = 2;
  const static int TAM_ANO  = 2;
  
  string validade;

  // Funções auxiliares na validação da data de validade
  int checaBarra(const string &validade);
  int checaFormato(const string &mes, const string &ano);

  void validar(const string &validade);
};

// Classe responsável por validar e guardar a sigla de um estado brasileiro
class Estado {
public:
  void setEstado(string estado);
  string getEstado() const {
    return estado;
  }

private:
  // Constantes auxiliares usadas na validação
  const static int VALIDO     = 1;
  const static int INVALIDO   = 0;
  // Constantes que indicam limites usados na validação
  const static int TAMANHO    = 2; 
  const static int NUM_ESTADOS  = 27;
  const static std::vector<string> ESTADOS;

  string estado;

  // Decisão de projeto: são aceitas como entrada letras minúsculas,
  // mas a string é salva em instâncias desta classe em formato
  // maiúsculo. Essa conversão é feita pela função abaixo.
  void formatar(string * estado);

  void validar(const string &estado);
};

// Classe responsável por validar e guardar um identificador (letras minúsculas)
class Identificador {
public:
  void setIdentificador(string identificador);
  string getIdentificador() const {
    return identificador;
  }

private:
  // Constante que indica limite usado na validação
  const static int TAMANHO = 5;

  string identificador;

  // Decisão de projeto: são aceitas como entrada letras maiúsculas,
  // mas a string é salva em instâncias desta classe em formato
  // minúsculo. Essa conversão é feita pela função abaixo.
  void formatar(string * identificador);

  void validar(const string &identificador);
};

// Classe responsável por validar e guardar um nome
class Nome {
public:
  void setNome(string nome);
  string getNome() const {
    return nome;
  }

private:
  // Constantes auxiliares usadas na validação
  const static int VALIDO     = 1;
  const static int INVALIDO   = 0;
  // Constantes que indicam limites usados na validação
  const static int TAMANHO_MAX  = 15;
  const static int TAMANHO_MIN  = 1;

  string nome;

  void validar(const string &nome);
};

// Classe responsável por validar e guardar um número de cartão de crédito
class NumeroCartao {
public:
  void setNumeroCartao(string numero_cartao);
  string getNumeroCartao() const {
    return numero_cartao;
  }

private:
  // Constante que indica limite usado na validação
  const static int TAMANHO  = 16;

  string numero_cartao;

  // Algoritmo de Luhn: checa se o número de cartão é válido
  int checkLuhn(string numero_cartao);

  void validar(const string &numero_cartao);
};

// Classe responsável por validar e guardar um número de conta corrente
class NumeroConta {
public:
  void setNumeroConta(string numero_conta);
  string getNumeroConta() const {
    return numero_conta;
  }

private:
  // Constante que indica limite usado na validação
  const static int TAMANHO = 6;

  string numero_conta;

  void validar(const string &numero_conta);
};

// Classe responsável por validar e guardar uma senha
class Senha {
public:
  void setSenha(string senha);
  string getSenha() const {
    return senha;
  }

private:
  // Constantes auxiliares usadas na validação
  const static int VALIDO     = 1;
  const static int INVALIDO   = 0;
  // Constantes que indicam limites usados na validação
  const static int TAMANHO    = 8;
  const static int NUM_SIMBOLOS = 5;
  // Constante que indica os valores de símbolos válidos para a senha
  const static std::vector<char> SIMBOLO;

  string senha;

  // Função auxiliar na validação. Indica se o caratere recebido é um símbolo
  int issymbol(char caractere);
  void validar(const string &senha);
};

// Classe responsável por validar e guardar um tipo de acomodação
class TipoAcomod {
public:
  void setTipoAcomod(string tipo_acomod);
  string getTipoAcomod() const {
    return tipo_acomod;
  }

private:
  // Constantes auxiliares usadas na validação
  const static int VALIDO   = 1;
  const static int INVALIDO = 0;
  // Delimitação dos tipos de acomodação válidos
  const static int NUM_TIPOS  = 3;
  const static std::vector<string> TIPOS;

  string tipo_acomod;

  void validar(const string &tipo_acomod);
};

#endif // DOMINIOS_H_