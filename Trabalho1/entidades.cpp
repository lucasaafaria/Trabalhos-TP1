#include "entidades.h"

// Definição de método construtor da classe Usuario
Usuario::Usuario(Nome &nome, Identificador &identificador, Senha &senha) {
  this->nome          = nome;
  this->identificador = identificador;
  this->senha         = senha;
}

// Definição de método construtor da classe Acomodacao
Acomodacao::Acomodacao(Identificador &identificador, TipoAcomod &tipo_acomod, Capacidade &capacidade, Data &data_inicio, Data &data_termino, Nome &cidade, Estado &estado, Diaria &diaria) {
  this->identificador = identificador;
  this->tipo_acomod   = tipo_acomod;
  this->capacidade    = capacidade;
  this->data_inicio   = data_inicio;
  this->data_termino  = data_termino;
  this->cidade        = cidade;
  this->estado        = estado;
  this->diaria        = diaria;
}

// Definição de método construtor da classe CartaoCredito
CartaoCredito::CartaoCredito(NumeroCartao &numero_cartao, Validade &validade) {
  this->numero_cartao = numero_cartao;
  this->validade      = validade;
}

// Definição de método construtor da classe ContaCorrente
ContaCorrente::ContaCorrente(NumeroConta &numero_conta, Agencia &agencia, Banco &banco) {
  this->numero_conta  = numero_conta;
  this->agencia       = agencia;
  this->banco         = banco;
}