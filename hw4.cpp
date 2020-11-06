/*
----Psuedocode----
sum():
Determine base case, so if the list is empty return
the sum. If the list is not empty, add the value
of the first element in the list to sum and then
recursively call sumHelper(list minus first element, sum).

product():
Determine base case, so if the list is empty return
the product. If the list is not empty, multiply the value
of the first element in the list to product and then
recursively call productHelper(list minus first element, product).

accumulate():
Determine base case, so once the list is empty return the base.
Else, recursively return accumulate function with the list minus the 
first element, fn, and fn(base, list_first(l)) which effectively adds the
base value to the current element.

reverse():
Once the list is empty, return the output_list. Else, set
output_list equal to a new list with list_first(list) being the
first element followed by the elements in output_list. Recursively call
reverseHelper(list_rest(first), output_list) until list is empty.

append():
If the first list is not empty, set output_list equal to
a new list with list_first(first) as the intial element, followed
by the rest of the contents in output_list. Recursively call 
appendHelper(list_rest(first), second, output_list) until the
first list contains no elements.
Then, if the second list is not empty, set output_list equal to
a new list with list_first(second) as the intial element, followed
by the rest of the contents in output_list. Recursively call 
appendHelper(first, list_rest(second), output_list) until the
second list contains no elements. Once both list are empty,
return reverse(output_list).

filter_odd():
Base case - if the list is empty, return reverse(output_list)
Else, the list is not empty, if the value at list_first(list)
% 2 != 0, set output_list equal to a new list with list_first(list)
as the inital element followed by the contents in output_list. Recursively
return oddHelper(list_rest(list), output_list) until list has no elements.

filter_even():
Base case - if the list is empty, return reverse(output_list)
Else, the list is not empty, if the value at list_first(list)
% 2 == 0, set output_list equal to a new list with list_first(list)
as the inital element followed by the contents in output_list. Recursively
return evenHelper(list_rest(list), output_list) until list has no elements.

filter():
Base case - if the list is empty, return reverse(output_list)
Else, the list is not empty, if the value at fn(list_first(list))
evaluates to true, set output_list equal to a new list with list_first(list)
as the inital element followed by the contents in output_list. Recursively
return filterHelper(list_rest(list), fn, output_list) until list has no elements.

rotate():
Base case - if n == 0, return list. Else, set list equal to a new 
list with list_first(list) as the initial value followed by the 
reverse of the rest of the contents in list, then reverse the new list
just made. Decrement n. Recursively return rotate(list, n) until base
case conditions met.

insert_list():
If n =! 0 then set output_list equal to list_first(first) as
the first element followed by the rest of the elements in
output_list. Decrement n. Recursively return insertHelper.
If the second list is not empty && n == 0, then set output_list
equal to the first element in the second list, followed by the
rest of the elements in output_list. Recursively return insertHelper.
Else if the first list is not empty && n == 0, set output_list equal
to the first element in first, followed by the rest of the elements
in output_list. Recursively return insertHelper(). Then return 
reverse(output_list).

chop():
Base case - if n == 0 return the list.
Else, set the list equal to the reverse(list_rest(reverse(l))).
list_rest(reverse(l)) will reverse the given list, then remove
the first element, effectively removing the "last" element. Then,
reversing the list again, gives us the list in the correct orientation.
Decrement n. Recursively return chop().

fib():
Base case - if n == 0, return 0.
Base case - if n == 1, return 1.
Else, return the sum of fib(n-1)
and fib(n-2).

fib_tail():
Base case - if n == 0, return 0.
if n == 1, return j. Else, recursively 
call fibHelper(n-1, j, i+j).
*/
#include <iostream>
#include "recursive.h"
#include "hw4.h"

using namespace std;

static int sumHelper(list_t list, int sum) {
  if (list_isEmpty(list)) {
    return sum;
  }
  sum += list_first(list);
  return sumHelper(list_rest(list), sum);
}

static int productHelper(list_t list, int product) {
  if (list_isEmpty(list)) {
    return product;
  }
  product *= list_first(list);
  return productHelper(list_rest(list), product);
}

static list_t reverseHelper(list_t list, list_t output_list) {
  if (list_isEmpty(list)) {
    return output_list;
  }
  output_list = list_make(list_first(list), output_list);
  return reverseHelper(list_rest(list), output_list);
}

static list_t appendHelper(list_t first, list_t second, list_t output_list) {
  if (!list_isEmpty(first)) {
    output_list = list_make(list_first(first), output_list);
    return appendHelper(list_rest(first), second, output_list);
  } else if (!list_isEmpty(second)) {
      output_list = list_make(list_first(second), output_list);
      return appendHelper(first, list_rest(second), output_list);
  }
  return reverse(output_list);
}

static list_t oddHelper(list_t list, list_t output_list) {
  if (list_isEmpty(list)) {
    return reverse(output_list);
  }
  if (list_first(list) % 2 != 0) {
    output_list = list_make(list_first(list), output_list);
  }
  return oddHelper(list_rest(list), output_list);
}

static list_t evenHelper(list_t list, list_t output_list) {
  if (list_isEmpty(list)) {
    return reverse(output_list);
  }
  if (list_first(list) % 2 == 0) {
    output_list = list_make(list_first(list), output_list);
  }
  return evenHelper(list_rest(list), output_list);
}

static list_t filterHelper(list_t list, bool (*fn)(int), list_t output_list) {
  if (list_isEmpty(list)) {
    return reverse(output_list);
  }
  if (fn(list_first(list))) {
    output_list = list_make(list_first(list), output_list);
  }
  return filterHelper(list_rest(list), fn, output_list);
}

static list_t insertHelper(list_t first, list_t second, list_t output_list, unsigned int n) {
  if (n != 0) {
    output_list = list_make(list_first(first), output_list);
    n--;
    return insertHelper(list_rest(first), second, output_list, n);
  } else if (!list_isEmpty(second) && n == 0) {
      output_list = list_make(list_first(second), output_list);
      return insertHelper(first, list_rest(second), output_list, n);
  } else if(!list_isEmpty(first) && n == 0) {
    output_list = list_make(list_first(first), output_list);
    return insertHelper(list_rest(first), second, output_list, n);
  }
  return reverse(output_list);
}

int fibHelper(int n, int i = 0, int j = 1) { 
  if (n == 0) {
    return 0;
  } 
  if (n == 1) {
    return j; 
  }
  return fibHelper(n - 1, j, i + j); 
}

int accumulate(list_t l, int (*fn)(int, int), int base) {
  if (list_isEmpty(l)) {
    return base;
  } else {
    return accumulate(list_rest(l), fn, fn(base, list_first(l)));
  }
}

int sum_list(list_t list) {
  return sumHelper(list, 0);
}

int product(list_t list){
  return productHelper(list, 1);
}

list_t reverse(list_t list) {
  list_t output_list = list_make();
  return reverseHelper(list, output_list);
}

list_t append(list_t first, list_t second) {
  list_t output_list = list_make();
  return appendHelper(first, second, output_list);
}

list_t filter_odd(list_t list) {
  list_t output_list = list_make();
  return oddHelper(list, output_list);
}

list_t filter_even(list_t list) {
  list_t output_list = list_make();
  return evenHelper(list, output_list);
}

list_t filter(list_t list, bool (*fn)(int)) {
  list_t output_list = list_make();
  return filterHelper(list, fn, output_list);
}

list_t rotate(list_t list, unsigned int n) {
  if(n == 0) {
    return list;
  }
  list = reverse(list_make(list_first(list), reverse(list_rest(list))));
  n--;
  return rotate(list, n);
}

list_t insert_list(list_t first, list_t second, unsigned int n) {
  list_t output_list = list_make();
  return insertHelper(first, second, output_list, n);
}

list_t chop(list_t l, unsigned int n) {
  if (n == 0) {
    return l;
  }
  l = reverse(list_rest(reverse(l)));
  n--;
  return chop(l, n);
}

int fib(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fib(n-1) + fib(n-2);
}

int fib_tail(int n) {
  return fibHelper(n, 0);
}