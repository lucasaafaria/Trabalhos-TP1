#ifndef ENTIDADES_H_
#define ENTIDADES_H_

#include "dominios.h"

using namespace std;

// Declarações de classes que compõem as entidades do sistema

// Classe responsável por validar e armazenar os dados de um usuário do sistema
class Usuario {
public:
  // Método construtor
  Usuario(Nome &nome, Identificador &identificador, Senha &senha);

  // Métodos set e get para cada dominio da entidade Usuario

  void setNome(const Nome &nome) {
      this->nome = nome;
  }

  Nome getNome() const {
      return nome;
  }

  void setIdentificador(const Identificador &identificador) {
      this->identificador = identificador;
  }

  Identificador getIdentificador() const {
      return identificador;
  }

  void setSenha(const Senha &senha) {
      this->senha = senha;
  }

  Senha getSenha() const {
      return senha;
  }

private:

  Nome nome;
  Identificador identificador;
  Senha senha;
};

// Classe responsável por validar e armazenar os dados de reserva de acomodação
class Acomodacao {
public:
  // Método construtor
  Acomodacao(Identificador &identificador, TipoAcomod &tipo_acomod,
             Capacidade &capacidade, Data &data_inicio,
             Data &data_termino, Nome &cidade, 
             Estado &estado, Diaria &diaria);

  // Métodos set e get para cada dominio da entidade Acomodacao

  void setIdentificador(const Identificador &identificador) {
      this->identificador = identificador;
  }

  Identificador getIdentificador() const {
      return identificador;
  }

  void setTipoAcomod(const TipoAcomod &tipo_acomod) {
      this->tipo_acomod = tipo_acomod;
  }

  TipoAcomod getTipoAcomod() const {
      return tipo_acomod;
  }

  void setCapacidade(const Capacidade &capacidade) {
      this->capacidade = capacidade;
  }

  Capacidade getCapacidade() const {
      return capacidade;
  }

  void setDataInicio(const Data &data_inicio) {
      this->data_inicio = data_inicio;
  }

  Data getDataInicio() const {
      return data_inicio;
  }

  void setDataTermino(const Data &data_termino) {
      this->data_termino = data_termino;
  }

  Data getDataTermino() const {
      return data_termino;
  }

  void setCidade(const Nome &cidade) {
      this->cidade = cidade;
  }

  Nome getCidade() const {
      return cidade;
  }

  void setEstado(const Estado &estado) {
      this->estado = estado;
  }

  Estado getEstado() const {
      return estado;
  }

  void setDiaria(const Diaria &diaria) {
      this->diaria = diaria;
  }

  Diaria getDiaria() const {
      return diaria;
  }

private:

  Identificador identificador;
  TipoAcomod tipo_acomod;
  Capacidade capacidade;
  Data data_inicio;
  Data data_termino;
  Nome cidade;
  Estado estado;
  Diaria diaria;
};

// Classe responsável por validar e armazenar os dados de cartão de crédito
class CartaoCredito {
public:
  // Método construtor
  CartaoCredito(NumeroCartao &numero_cartao, Validade &validade);

  // Métodos set e get para cada dominio da entidade CartaoCredito

  void setNumeroCartao(const NumeroCartao &numero_cartao) {
      this->numero_cartao = numero_cartao;
  }

  NumeroCartao getNumeroCartao() const {
      return numero_cartao;
  }

  void setValidade(const Validade &validade) {
      this->validade = validade;
  }

  Validade getValidade() const {
      return validade;
  }

private:

  NumeroCartao numero_cartao;
  Validade validade;

};

// Classe responsável por validar e armazenar os dados de uma conta corrente
class ContaCorrente {
public:
  // Método construtor
  ContaCorrente(NumeroConta &numero_conta, Agencia &agencia, Banco &banco);

  // Métodos set e get para cada dominio da entidade ContaCorrente

  void setNumeroConta(const NumeroConta &numero_conta) {
      this->numero_conta = numero_conta;
  }

  NumeroConta getNumeroConta() const {
      return numero_conta;
  }

  void setAgencia(const Agencia &agencia) {
      this->agencia = agencia;
  }

  Agencia getAgencia() const {
      return agencia;
  }

  void setBanco(const Banco &banco) {
      this->banco = banco;
  }

  Banco getBanco() const {
      return banco;
  }

private:

    NumeroConta numero_conta;
    Agencia agencia;
    Banco banco;
};

#endif // ENTIDADES_H_