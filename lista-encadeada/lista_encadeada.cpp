#include "lista_encadeada.h"
#include <cstddef>
#include <iostream>

No::No() : proximo(nullptr) {}
No::~No() {}
No *No::getProx() const { return proximo; }
void No::setProx(No *proximo) { this->proximo = proximo; }
int No::getConteudo() const { return conteudo; }
void No::setConteudo(int conteudo) { this->conteudo = conteudo; }

Lista::~Lista() {
  No *atual = cabeca;
  while (atual != nullptr) {
    No *proximo = atual->getProx();
    delete atual;
    atual = proximo;
  }
}

Lista::Lista() {
  cabeca = nullptr;
  tamanho = 0;
}

int Lista::length() {
  return tamanho;
} // tava dando colicao de declaracao, mudei tamanho pra length

bool Lista::vazia() {
  if (tamAtual == 0) {
    return true;
  } else {
    return false;
  }
}

int Lista::elemento(int pos) {
  No *aux = cabeca;
  int count = 1;
  if (vazia())
    return -1;
  if ((pos < 1) || (pos > tamanho))
    return -1;
  while (count < pos) {
    aux = aux->getProx();
    count++;
  }
  int dado = aux->getConteudo();
  return dado;
}

int Lista::posicao(int dado) {
  int count = 1;
  No *aux;
  if (vazia())
    return 0;
  aux = cabeca;
  while (aux != nullptr) {
    if (aux->getConteudo() == dado)
      return count;
    aux = aux->getProx();
    count++;
  }
  dado = aux->getConteudo();
  return dado;
}

bool Lista::insere(int pos, int dado) {
  if (vazia() && (pos != 1)) {
    return false;
  }
  if (pos == 1) {
    return insereInicioLista(dado);
  } else if (pos == tamanho + 1) {
    return insereFimLista(dado);
  } else {
    return insereMeioLista(pos, dado);
  }
}

bool Lista::insereInicioLista(int valor) {
  No *novoNo = new No();
  novoNo->setConteudo(valor);
  novoNo->setProx(cabeca);
  cabeca = novoNo;
  tamanho++;
  return true;
}

bool Lista::insereMeioLista(int pos, int dado) {
  int count = 1;
  No *novoNo = new No();
  novoNo->setConteudo(dado);
  //
  No *aux = cabeca;
  while ((count < pos - 1) && (aux != nullptr)) {
    aux = aux->getProx();
    count++;
  }
  if (aux == nullptr)
    return false;

  novoNo->setProx(aux->getProx());
  aux->setProx(novoNo);
  tamanho++;
  return true;
}

bool Lista::insereFimLista(int dado) {
  No *novoNo = new No();
  novoNo->setConteudo(dado);
  No *aux = cabeca;
  while (aux->getProx() != nullptr) {
    aux = aux->getProx();
  }
  novoNo->setProx(nullptr);
  aux->setProx(novoNo);
  this->tamanho++;
  return true;
}

int Lista::remove(int pos) {
  if (vazia())
    return -1;
  if (pos == 1) {
    return removeInicioLista();
  } else {
    return removeNaLista(pos);
  }
}

int Lista::removeInicioLista() {
  No *p = cabeca;
  int dado = p->getConteudo();
  cabeca = p->getProx();
  tamanho--;
  delete p;
  p = nullptr;
  return dado;
}

int Lista::removeNaLista(int pos) {
  No *atual = nullptr, *antecessor = nullptr;
  int dado = -1, count = 1;

  atual = cabeca;
  while ((count < pos) && (atual != nullptr)) {
    antecessor = atual;
    atual = atual->getProx();
    count++;
  }
  if (atual == nullptr) {
    return -1;
  }

  dado = atual->getConteudo();
  antecessor->setProx(atual->getProx());
  tamanho--;
  atual = nullptr;
  delete atual;
  return dado;
}
