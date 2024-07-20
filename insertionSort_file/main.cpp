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

void insertionSort(vector<int> &A) {
  int n = A.size();
  int pivo;

  for (int i = 1; i < n; i++) {
    pivo = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > pivo) {
      A[j + 1] = A[j];
      j = j - 1;
    }
    A[j + 1] = pivo;
  }
}

// para rodar o codigo, faça make e depois ./sort

int main() {

  fs::path inputPath =
      "../instancias-num/num.1000.1.in"; // so mudar o nome da instancia
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

  auto start = chrono::high_resolution_clock::now();
  insertionSort(data);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> duration = end - start;
  // insertionSort(data);

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
