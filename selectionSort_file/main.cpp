#include <chrono>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

void selectionSort(std::vector<int> &A) {
  int size = A.size();

  for (int i = 0; i < size - 1; i++) {
    int i_min = i;

    for (int j = i + 1; j < size; j++) {
      if (A[j] < A[i_min]) {
        i_min = j;
      }
    }
    if (A[i] != A[i_min]) {
      int temp = A[i];
      A[i] = A[i_min];
      A[i_min] = temp;
    }
  }
}

// para rodar o codigo, faça make e depois ./sort

int main() {

  fs::path inputPath = "../instancias-num/num.1000.1.in";
  fs::path outputPath = "sortedInstances.txt";

  std::ifstream inputFile(inputPath);
  if (!inputFile.is_open()) {
    std::cerr << "you couldn't open the input file" << inputPath << std::endl;
    return 1;
  }

  std::vector<int> data;
  std::string line;
  while (std::getline(inputFile, line)) {
    std::stringstream ss(line);
    int number;
    while (ss >> number) {
      data.push_back(number);
    }
  }

  inputFile.close();

  selectionSort(data);

  std::ofstream outputFile(outputPath);
  if (!outputFile.is_open()) {
    std::cerr << "you couldn't open the outputfile" << outputPath << std::endl;
    return 1;
  }

  for (const int &num : data) {
    outputFile << num << std::endl;
  }

  outputFile.close();

  return 0;
}
