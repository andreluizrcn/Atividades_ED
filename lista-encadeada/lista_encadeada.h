#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

class No {
private:
  int conteudo;
  No *proximo; // ponteiro que liga pra poxima cabeca

public:
  No();
  ~No();

  int getConteudo() const;
  void setConteudo(int conteudo);

  No *getProx() const;
  void setProx(No *proximo);
};

class Lista {
private:
  No *cabeca;
  int tamanho;
  int tamAtual;

public:
  Lista();
  ~Lista();
  bool vazia();
  int cheia() const;
  int length();
  int elemento(int pos);
  int posicao(int dado);
  bool insere(int pos, int dado);
  bool insereInicioLista(int valor);
  bool insereMeioLista(int pos, int dado);
  bool insereFimLista(int dado);
  int remove(int pos);
  int removeInicioLista();
  int removeNaLista(int pos);
};

#endif
