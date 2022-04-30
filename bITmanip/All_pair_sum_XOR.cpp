/**
 * @file All_pair_sum_XOR.cpp
 * @author biTLegi0n
 * @brief 
 * @version 0.1
 * @date 2021-07-02
 * 
 * @copyright Copyright (c) 2021
 * 
 In this problem, we have to observe one thing, and that is repeating XORs. Make a matrix where each (i,j) represents arr[i]^arr[j].
 We know that a^b = b^a. Based on this, we see that (1,3) will repeat as (3,1), (2,5) will repeat as (5,2) ie. the matrix will have
 transpose rows and coloumns. Only the diagonal elements are the ones that remains uneffected. So the answer will XOR of 2*diagonal_elements
 2^diagonal elemnts as all_pair_sum, ie if array is [2,4] then we need to find (2+2)^(2+4)^(4+2)^(4+4).
 */
/**
 * ~ is for complement ie ~1 = 0
 * ! is for negation ie, !true = false
 
 */