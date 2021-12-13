/*
Using stringstream class or sscanf()
stringstream() : This is an easy way to convert strings of digits into ints,
floats or doubles.
Following is a sample program using a stringstream to convert string to int.

https://www.geeksforgeeks.org/converting-strings-numbers-cc/?ref=leftbar-rightbar
*/

// A program to demonstrate the use of stringstream
#include <bits/stdc++.h>

#include <iostream>
#include <sstream>
using namespace std;

int main() {
  string s = "12345";

  // object from the class stringstream
  stringstream geek(s);

  // The object has the value 12345 and stream
  // it to the integer x
  int x = 0;
  geek >> x;

  // Now the variable x holds the value 12345
  cout << "Value of x : " << x << endl;

  string str1 = "45";
  string str2 = "3.14159";
  string str3 = "31337 geek";

  int myint1 = stoi(str1);
  int myint2 = stoi(str2);
  int myint3 = stoi(str3);

  cout << "stoi(\"" << str1 << "\") is " << myint1 << '\n';
  cout << "stoi(\"" << str2 << "\") is " << myint2 << '\n';
  cout << "stoi(\"" << str3 << "\") is " << myint3 << '\n';

  const char *str11 = "42";
  const char *str22 = "3.14159";
  const char *str33 = "31337 geek";

  int num1 = atoi(str11);
  int num2 = atoi(str22);
  int num3 = atoi(str33);

  cout << "atoi(\"" << str11 << "\") is " << num1 << '\n';
  cout << "atoi(\"" << str22 << "\") is " << num2 << '\n';
  cout << "atoi(\"" << str33 << "\") is " << num3 << '\n';

  return 0;
}
