#include "filaSeq.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  filaSeq fila;
  int value, choice;

  do {
    std::cout << "Type (1) to insert a number into the queue, (2) to remove a "
                 "number from the queue, (3) to show the queue, (0) to exit: "
              << std::endl;
    std::cin >> choice;

    switch (choice) {
    case 1:
      std::cout << "Type the number you want to add to the queue: "
                << std::endl;
      std::cin >> value;
      if (fila.insert(value)) {
        std::cout << "Number added to the queue." << std::endl;
      } else {
        std::cout << "Failed to add the number, the queue is full."
                  << std::endl;
      }
      break;
    case 2:
      value = fila.remove();
      if (value == -1) {
        std::cout << "Failed to remove a number, the queue is empty."
                  << std::endl;
      } else {
        std::cout << "Removed number: " << value << std::endl;
      }
      break;
    case 3:
      std::cout << "Queue contents: ";
      for (int i = 0; i < fila.length(); i++) {
        cout << fila.first() << " ";
        fila.insert(fila.remove());
      }
      std::cout << std::endl;
      break;
    case 0:
      std::cout << "Exiting..." << std::endl;
      break;
    default:
      std::cout << "Invalid choice." << std::endl;
      break;
    }
  } while (choice != 0);

  return 0;
}
