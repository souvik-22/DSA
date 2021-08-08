/*
IMPORTANT : CALCULATE POWER (X^Y) % P where, P = 10^9+7

Count number of binary strings of length N having only 0’s and 1’s

Given an integer N, the task is to count the number of binary strings of 
length N having only 0’s and 1’s. 
Note: Since the count can be very large, return the answer modulo 10^9+7.

Examples:  

Input: 2 
Output: 4 
Explanation: The numbers are 00, 01, 11, 10. Hence the count is 4.

Input: 3 
Output: 8 
Explanation: The numbers are 000, 001, 011, 010, 111, 101, 110, 100. 
Hence the count is 8. 

Approach: The problem can be easily solved by using Permutation and 
Combination. At each position of the string there can only be two 
possibilities, i.e., 0 or 1. Therefore, the total number of permutation 
of 0 and 1 in a string of length N is given by 2*2*2*…(N times), i.e., 2^N. 
The answer can be very large, hence modulo by 10^9+7 is returned.

*/

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)

// Iterative Function to calculate (x^y)%p in O(log y)
ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1) //(y % 2 == 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Function to count the number of binary
// strings of length N having only 0's and 1's
ll findCount(ll N)
{
    int count = power(2, N, mod);
    return count;
}

// Driver code
int main()
{
    ll N = 25;

    cout << findCount(N);

    return 0;
}
