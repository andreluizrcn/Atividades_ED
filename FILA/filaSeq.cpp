#include "filaSeq.h"
#include <iostream>

filaSeq::filaSeq() {
  begin = 0;
  end = -1;
  nElements = 0;
  maxLength = 100;
  dados = new int[maxLength];
}

filaSeq::~filaSeq() { delete[] dados; }

bool filaSeq::empty() {
  if (nElements == 0) {
    return true;
  } else {
    return false;
  }
}

bool filaSeq::full() {
  if (nElements == maxLength) {
    return true;
  } else {
    return false;
  }
}

int filaSeq::length() { return nElements; }

int filaSeq::first() {
  if (empty()) {
    return -1;
  }
  return dados[begin];
}

bool filaSeq::insert(int value) {
  if (full()) {
    return false;
  }

  end = (end + 1) % maxLength;
  dados[end] = value;
  nElements++;
  return true;
}

int filaSeq::remove() {
  if (empty()) {
    return -1;
  }
  int rest = first();
  begin = (begin + 1) % maxLength;
  nElements--;
  return rest;
}
