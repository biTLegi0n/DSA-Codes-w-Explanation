/**
 * @brief Basic Points
 * 
 * ->    We create a 2D vector containing "n" elements each having the value "vector<int> (m, 0)".
      "vector<int> (m, 0)" means a vector having "m" elements each of value "0". Here these elements are vectors.
    
      vector<vector<int>> vec( n , vector<int> (m, 0));

 -> tO CHECK if ith bit is set or not, we just do & with (1<<i) because that would be equal to 2^i. ie having only 1 set bit. 
 * ~ is for complement ie ~1 = 0
 * ! is for negation ie, !true = false
 
 */
