/*
-------Pseudocode-------
readInput():
Read user input into a list_t list passed by reference

hashTestOne():
Initalize empty list_t newHashList
Initalize sum to sum(list)
while list not empty:
Initalize newKey to fib(current key) + sum
Add newKey to newHashList
Pop list
Return newHashList

hashTestTwo():
Initalize output to empty list
Initalize temp to the odd keys in list
Initalize hashOdd to empty list
Initalize oddProduct to product(temp) and ctr to 0
while temp list is not empty:
  Initalize newKey to oddProduct + curent key value and insert into hashOdd
  Advance to next list key
  Increment ctr
if hashOdd is not empty:
  while ctr > 0 (loop through every value):
    if current value is prime:
      remove it
    rotate hashOdd list forward
    decrement ctr
Initalize sumOdd to 0
if hashOdd isn't empty:
  set sumOdd to sum(hashOdd)
while list is not empty:
  if current key is odd:
    Initalize newKey to oddProduct + key and add to output list
  else if its even:
    Initalize newKey to sumOdd + key and add to output list
  advance list
return output list

differenceOfTwoList():
Initalize output to empty list
while list1 and list1 are not empty:
  Initialize absDiff to adsolute difference of current value 
  of list1 and list2.
  Add absDiff to output list
  Advance list1 and list2
Return output list

isPrime():
Intialize a bool flag to true
if num is 0 or 1:
  set flag to false
else:
  loop from i = 2 to num / 2:
    if num is divisible by i:
      set flag to false
      break from loop
return flag

countCollisions():
Initialize empty unordered_set uSet and output to 0
while list is not empty:
  if current key is not in set:
    add key to set
  else:
    increment output by 1
  advance list to next element
return output
*/
#include "hw4.h"
#include <iostream>
#include <sstream>
#include <unordered_set>

void readInput(list_t &list);
list_t hashTestOne(list_t list);
list_t hashTestTwo(list_t list);
list_t differenceOfTwoList(list_t list_1, list_t list_2);
bool isPrime(int num);
int countCollisions(list_t list);

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

  //testing countCollisions
  int col = countCollisions(newHash);
  int oldCol = countCollisions(output);
  int col2 = countCollisions(newHash2);
  int oldCol2 = countCollisions(output2);
  std::cout << "---Collision Count---" << "\n";
  std::cout << "--Hash #1--" << "\n";
  std::cout << "new_code: " << col << "\n";
  std::cout << "old_code: " << oldCol << "\n";
  std::cout << "--Hash #2--" << "\n";
  std::cout << "new_code: " << col2 << "\n";
  std::cout << "old_code: " << oldCol2 << "\n";
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
  int sumList = sum(list);
  while (!list_isEmpty(list)) {
    int newKey = fib(list_first(list)) + sumList;
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
  list_t output = list_make();
  list_t temp = filter_odd(list);
  list_t hashOdd = list_make();
  int oddProduct = product(temp);
  int ctr = 0;
  while (!list_isEmpty(temp)) {
    int newKey = oddProduct + list_first(temp);
    hashOdd = list_make(newKey, hashOdd);
    temp = list_rest(temp);
    ctr++;
  }
  if (!list_isEmpty(hashOdd)) {
    while (ctr > 0) {
      if (isPrime(list_first(hashOdd))) {
        hashOdd = list_rest(hashOdd);
      }
      hashOdd = rotate(hashOdd, 1);
      ctr--;
    }
  }
  int sumOdd = 0;
  if (!list_isEmpty(hashOdd)) {
    sumOdd = sum(hashOdd);
  }
  while (!list_isEmpty(list)) {
    if (list_first(list) % 2 != 0) {
      int newKey = oddProduct + list_first(list);
      output = list_make(newKey, output);
    }
    else {
      int newKey = sumOdd + list_first(list);
      output = list_make(newKey, output);
    }
    list = list_rest(list);
  }
  return reverse(output);
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

int countCollisions(list_t list) {
  std::unordered_set<int> uSet;
  int output = 0;
  while (!list_isEmpty(list)) {
    if (uSet.find(list_first(list)) == uSet.end()) {
      uSet.insert(list_first(list));
    }
    else {
      output += 1;
    }
    list = list_rest(list);
  }
  return output;
}