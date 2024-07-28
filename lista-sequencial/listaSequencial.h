#ifndef LISTASEQUENCIAL_H
#define LISTASEQUENCIAL_H

class listSeq {
private:
  int *dados;
  int cur_length;
  int maxLength;

public:
  listSeq();
  ~listSeq();
  bool empty() const;
  bool full() const;
  int length() const;
  int element(int) const;
  int position(int) const;
  bool insert(int, int);
  int remove(int);
};

#endif
