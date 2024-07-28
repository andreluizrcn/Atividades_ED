#include "listaSequencial.h"
#include <iostream>

using namespace std;

// a definicao classe ta no .h
listSeq::listSeq() {
  maxLength = 100;
  cur_length = 0;
  dados = new int[maxLength];
}

listSeq::~listSeq() { delete[] dados; }

bool listSeq::empty() const {
  if (cur_length == 0) {
    return true;
  } else {
    return false;
  }
}

bool listSeq::full() const {
  if (cur_length == maxLength) {
    return true;
  } else {
    return false;
  }
}

int listSeq::length() const { return cur_length; }

int listSeq::element(int pos) const {
  int dado;

  if ((pos > cur_length) || (pos <= 0)) {
    return -1;
  }

  dado = dados[pos - 1];
  return dado;
}

int listSeq::position(int dado) const {
  for (int i = 0; i < cur_length; i++) {
    if (dados[i] == dado) {
      return (i + 1);
    }
  }
  return -1;
}

bool listSeq::insert(int pos, int dado) {

  if (full() || (pos > cur_length + 1) || (pos <= 0)) {
    return false;
  }

  for (int i = cur_length; i >= pos; i--) {
    dados[i] = dados[i - 1];
  }

  dados[pos - 1] = dado;
  cur_length++;
  return true;
}

int listSeq::remove(int pos) {
  int dado;
  if ((pos > cur_length) || (pos < 1)) {
    return -1;
  }
  dado = dados[pos - 1];

  for (int i = pos - 1; i < cur_length; i++) {
    dados[i] = dados[i + 1];
  }
  cur_length--;
  return dado;
}
