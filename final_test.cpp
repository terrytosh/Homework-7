#include "hw4.h"
#include <iostream>
#include <sstream>

void readInput(list_t &list);
list_t hashTestOne(list_t list);
list_t hashTestTwo(list_t list);
list_t differenceOfTwoList(list_t list_1, list_t list_2);
bool isPrime(int num);

int main() {

  //hash test input
  list_t input = list_make();
  std::cout << "New hash input: ";
  readInput(input);

  //old hash output
  list_t output = list_make();
  std::cout << "Old hash output: ";
  readInput(output);

  //testing hashTestOne
  list_t newHash = hashTestOne(input);
  std::cout << "New hash keys: ";
  list_print(newHash);

  std::cout << "\n";

  //testing differenceOfTwoList
  list_t diff = differenceOfTwoList(newHash, output);
  std::cout << "Difference: ";
  list_print(diff);

  std::cout << "\n";

  //hash test 2 input
  list_t input2 = list_make();
  std::cout << "New hash input 2: ";
  readInput(input2);

  //old hash output 2
  list_t output2 = list_make();
  std::cout << "Old hash output 2: ";
  readInput(output2);

  //testing hashTestTwo
  list_t newHash2 = hashTestTwo(input2);
  std::cout << "New hash keys 2: ";
  list_print(newHash2);

  std::cout << "\n";

  //testing differenceOfTwoList
  list_t diff2 = differenceOfTwoList(newHash2, output2);
  std::cout << "Difference 2: ";
  list_print(diff2);

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
  list_t output = list_make();
  while(!list_isEmpty(list_1) && !list_isEmpty(list_2)) {
    int absDiff = abs(list_first(list_1) - list_first(list_2));
    output = list_make(absDiff, output);
    list_1 = list_rest(list_1);
    list_2 = list_rest(list_2);
  }
  return reverse(output);
}

list_t hashTestTwo(list_t list) {
  list_t newHashList = list_make();
  list_t odds = filter_odd(list);
  list_t odds_no_primes = filter_odd(list);
  int odds_product = product(odds);
  while (!list_isEmpty(odds)) {
    if (isPrime(list_first(odds))) {
      odds_no_primes = list_rest(odds_no_primes);
    }
    odds = list_rest(odds);
  }
  int sum_odds = sum_list(odds_no_primes);
  while (!list_isEmpty(list)) {
    if (list_first(list) % 2 != 0) {
      int newKey = odds_product + list_first(list);
      newHashList = list_make(newKey, newHashList);
    }
    else {
      int newKey = sum_odds + list_first(list) + 49;
      newHashList = list_make(newKey, newHashList);
    }
    list = list_rest(list);
  }
  return reverse(newHashList);
}

bool isPrime(int num) {
  bool flag = true;
  if (num == 0 || num == 1) {
    flag = false;
  }
  else {
    for (int i = 2; i <= num / 2; ++i) {
      if (num % i == 0) {
        flag = false;
        break;
      }
    }
  }
  return flag;
}