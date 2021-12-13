/*

Given a string, convert the string to palindrome without any
modifications like adding a character, removing a character,
replacing a character etc.
Examples:

Input : "mdaam"
Output : "madam" or "amdma"

Input : "abb"
Output : "bab"

Input : "geeksforgeeks"
Output : "No Palindrome"

*/
// CPP program to rearrange a string to
// make palindrome.
#include <bits/stdc++.h>
using namespace std;

string getPalindrome(string str) {
  // Store counts of characters
  unordered_map<char, int> hmap;
  for (int i = 0; i < str.length(); i++) hmap[str[i]]++;

  /* find the number of odd elements.
      Takes O(n) */
  int oddCount = 0;
  char oddChar;
  for (auto x : hmap) {
    if (x.second % 2 != 0) {
      oddCount++;
      oddChar = x.first;
    }
  }

  /* odd_cnt = 1 only if the length of
      str is odd */
  if (oddCount > 1 || oddCount == 1 && str.length() % 2 == 0)
    return "NO PALINDROME";

  /* Generate first halh of palindrome */
  string firstHalf = "", secondHalf = "";
  // for (auto x : hmap)
  //     cout << x.first << " " << x.second << endl;
  for (auto x : hmap) {
    // Build a string of floor(count/2)
    // occurrences of current character
    // cout << x.first << " " << x.second << endl;
    string s(x.second / 2, x.first);

    // Attach the built string to end of
    // and begin of second half
    firstHalf = firstHalf + s;
    secondHalf = s + secondHalf;
  }

  // Insert odd character if there
  // is any
  return (oddCount == 1) ? (firstHalf + oddChar + secondHalf)
                         : (firstHalf + secondHalf);
}

int main() {
  string s = "aabab";
  cout << getPalindrome(s);
  return 0;
}
