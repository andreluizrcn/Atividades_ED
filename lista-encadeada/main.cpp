#include "lista_encadeada.h"
#include <cstdio>
#include <iostream>

int main(int argc, char *argv[]) {
  No node;
  Lista list;
  int list_size, num, pos;
  int choice;

  std::cout << "type the list size (int value, ex:3):" << std::endl;
  std::cin >> list_size;
  std::cout << "type the values inside the list: " << std::endl;
  for (int i = 0; i < list_size; i++) {
    std::cin >> num;
    list.insere(i + 1, num);
  }

  std::cout << "the initial list typed: " << std::endl;
  for (int i = 1; i <= list.length(); i++) {
    std::cout << list.elemento(i) << " ";
  }
  std::cout << std::endl;

  std::cout << "(1)insert numbers (2)remove numbers (0)exit" << std::endl;
  std::cin >> choice;

  if (choice == 0) {
    return 0;
  }

  switch (choice) {
  case 1:
    std::cout << "type the position to insert a node: " << std::endl;
    std::cin >> pos;
    std::cout << "the the value of the new node: " << std::endl;
    std::cin >> num;
    if (list.insere(pos, num)) {
      std::cout << "number was successfuly inserted" << std::endl;
    } else {
      std::cout << "number failed to insert number" << std::endl;
    }
    break;

  case 2:
    std::cout << "type the position to remove a node:" << std::endl;
    std::cin >> pos;
    num = list.remove(pos);
    if (num != -1) {
      std::cout << "node removed: " << num << std::endl;
    } else {
      std::cout << "failed to remove node" << std::endl;
    }
    break;
  default:
    std::cout << "failed the compute the operation" << std::endl;
    break;
  }

  std::cout << "final list: " << std::endl;
  for (int i = 1; i <= list.length(); i++) {
    std::cout << list.elemento(i) << " ";
  }
  std::cout << std::endl;
  std::cout << "the updated list size is: " << list.length() << " "
            << std::endl;
  return 0;
}
