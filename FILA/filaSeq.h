#ifndef FILASEQ_H
#define FILASEQ_H

#include <vector>
class filaSeq {
private:
  int *dados;
  int begin;
  int end;
  int nElements;
  int maxLength;

public:
  filaSeq();
  ~filaSeq();
  bool empty();
  bool full();
  int length();
  int first();
  bool insert(int value);
  int remove();
};

#endif
