/**
 * @file CatalanNumbers.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-03-13
 *
 * @copyright Copyright (c) 2022
 *
  @brief    This is just to gice you some information about catalan numbers.
            Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.

            > Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3,
              possible expressions are ((())), ()(()), ()()(), (())(), (()()).
            > Count the number of possible Binary Search Trees with n keys (See this)
            > Count the number of full binary trees (A rooted binary tree is full if every vertex has either two
              children or no children) with n+1 leaves.
            > Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points
              such that no 2 chords intersect.

            The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862
 */
// A dynamic programming based function to find nth
unsigned long int catalanDP(unsigned int n){
  // Table to store results of subproblems
  unsigned long int catalan[n + 1];

  // Initialize first two values in table
  catalan[0] = catalan[1] = 1;

  // Fill entries in catalan[] using recursive formula
  for (int i = 2; i <= n; i++) {
      catalan[i] = 0;
      for (int j = 0; j < i; j++)
          catalan[i] += catalan[j] * catalan[i - j - 1];
  }

  // Return last entry
  return catalan[n];
}