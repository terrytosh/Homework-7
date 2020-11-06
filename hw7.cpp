#include "hw4.h"
#include <iostream>
#include <sstream>

void readInput(list_t &list);
list_t hashTestOne(list_t list);
list_t differenceOfTwoList(list_t list_1, list_t list_2);

int main() {
  //hash test input
  list_t input = list_make();
  std::cout << "New hash input: ";
  readInput(input);
  list_print(input);

  std::cout << "\n";

  //old hash input
  list_t output = list_make();
  std::cout << "Old hash output: ";
  readInput(output);
  list_print(output);

  std::cout << "\n";

  //testing hashTestOne
  list_t newHash = hashTestOne(input);
  list_print(newHash);

  std::cout << "\n";

  return 0;
}

void readInput(list_t &list) {
  std::string input = "";
  int num = 0;
  getline(std::cin, input);
  std::istringstream iss(input);
  while (iss >> num) {
    list = list_make(num, list);
  }
  list = reverse(list);
}

list_t hashTestOne(list_t list) {
  list_t newHashList = list_make();
  int sum = sum_list(list);
  while (!list_isEmpty(list)) {
    int newKey = fib(list_first(list)) + sum;
    newHashList = list_make(newKey, newHashList);
    list = list_rest(list);
  }
  return reverse(newHashList);
}

list_t differenceOfTwoList(list_t list_1, list_t list_2) {
  
}