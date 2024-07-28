#include "listaSequencial.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  listSeq list;
  int array_size, num, pos;
  char choice;

  std::cout << "type the amount of number that will compose the array length "
               "(max length = 100): "
            << std::endl;
  std::cin >> array_size;

  std::cout << "type the numbers that will be inside the array: " << std::endl;
  for (int i = 0; i < array_size; i++) {
    cin >> num;
    list.insert(i + 1, num);
  }

  std::cout << "inicial array: " << std::endl;
  for (int i = 1; i <= list.length(); i++) {
    std::cout << list.element(i) << " ";
  }
  std::cout << std::endl;

  while (true) {
    std::cout << "Choose the operation: (i) insert, (r) remove, (x) exit: "
              << std::endl;
    std::cin >> choice;

    if (choice == 'x') {
      break;
    }

    switch (choice) {
    case 'i':
      std::cout << "type the position of the insertion: " << std::endl;
      std::cin >> pos;
      std::cout << "type the number you want to insert: " << std::endl;
      std::cin >> num;
      // list.insert(pos, num);
      if (list.insert(pos, num)) {
        std::cout << "insertion of number was successful." << std::endl;
      } else {
        std::cout
            << "Fail when inserting number. Verify position or if list is full"
            << std::endl;
      }
      break;

    case 'r':
      cout << "type the position of number to remove: " << std::endl;
      cin >> pos;
      num = list.remove(pos);
      if (num != -1) {
        std::cout << "removed number: " << num << std::endl;
      } else {
        std::cout << "failed to remove a number, check position again"
                  << std::endl;
      }
      break;

    default:
      cout << "invalid choice. try again." << std::endl;
      break;
    }
  }

  cout << "final array:" << endl;
  for (int i = 1; i <= list.length(); i++) {
    cout << list.element(i) << " ";
  }
  cout << endl;

  cout << "final array length: " << list.length() << endl;

  return 0;
}
