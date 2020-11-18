#ifndef __HW4_H__
#define __HW4_H__

#include "recursive.h"

int sum(list_t list);
    /* 
    // EFFECTS: returns the sum of each element in list
    //          zero if the list is empty.
    */ 

int product(list_t list);
    /* 
    // EFFECTS: returns the product of each element in list
    //          one if the list is empty.
    */

int accumulate(list_t list, int (*fn)(int, int), int identity);
    /*
    // REQUIRES: fn must be associative.
    // EFFECTS: return identity if list is empty
    //          return fn(list_first(list), 
    //                    accumulate(list_rest(list),
    //                               fn, identity) otherwise.
    //
    // For example, if you have the following function:
    //
    //           int add(int x, int y);
    //
    // Then the following invocation returns the sum of all elements:
    //
    //           accumulate(list, add, 0);
    //
    // The "identity" argument is typically the value for which 
    // fn(X, identity) == X, for any X.
    */ 

list_t reverse(list_t list);
    /*
    // EFFECTS: returns the reverse of list
    //
    // For example: the reverse of ( 3 2 1 ) is ( 1 2 3 )
    */

list_t append(list_t first, list_t second);
    /*
    // EFFECTS: returns the list (first second)
    */ 

list_t filter_odd(list_t list);
    /*
    // EFFECTS: returns a new list containing only the elements of the
    //          original list which are odd in value, 
    //          in the order in which they appeared in list.
    //
    // For example, if you applied filter_odd to the list ( 4 1 3 0 )
    // you would get the list ( 1 3 )
    */ 

list_t filter_even(list_t list);
    /*
    // EFFECTS: returns a new list containing only the elements of the
    //          original list which are even in value, 
    //          in the order in which they appeared in list.
    //
    // For example, if you applied filter_odd to the list ( 4 1 3 0 )
    // you would get the list ( 4 0 )
    */

list_t filter(list_t list, bool (*fn)(int));
    /*
    // EFFECTS: returns a list containing precisely the elements of list
    //          for which the predicate fn() evaluates to true, in the
    //          order in which  they appeared in list.
    */

list_t rotate(list_t list, unsigned int n);
    /*
    // EFFECTS: returns a list equal to the original list with the 
    //          first element moved to the end of the list n times.
    //
    // For example, rotate(( 1, 2, 3, 4, 5), 2) yields ( 3, 4, 5, 1, 2 )
    */

list_t insert_list(list_t first, list_t second, unsigned int n);
    /*
    // REQUIRES: n <= the number of elements in first
    // EFFECTS: returns a list comprising the first n elements of
    //          "first", followed by all elements of "second",
    //           followed by any remaining elements of "first".
    //
    //     For example: insert (( 1 2 3 ), ( 4 5 6 ), 2)
    //            is  ( 1 2 4 5 6 3 ).
    */

list_t chop(list_t l, unsigned int n);
    /*
    // REQUIRES l has at least n elements
    // EFFECTS: returns the list equal to l without its last n
    //          elements
    */

int fib(int n);
    /*
    // REQUIRES: n >= 0
    // EFFECTS: computes the Nth Fibonacci number
    //          fib(0) = 0
    //          fib(1) = 1
    //          fib(n) = fib(n-1) + fib(n-2) for (n>1).
    // This must be recursive but need not be tail recursive
    */

int fib_tail(int n);
    /*
    // REQUIRES: n >= 0
    // EFFECTS: computes the Nth Fibonacci number
    //          fib(0) = 0
    //          fib(1) = 1
    //          fib(n) = fib(n-1) + fib(n-2) for (n>1).
    // MUST be tail recursive
    // Hint: instead of starting at n and workind down, start at
    // 0 and 1 and *upwards*.
    */


#endif /* __HW4_H__ */
