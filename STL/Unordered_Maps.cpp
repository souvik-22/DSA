/*
Difference between maps and unordered maps
1. inbuilt implementation
2. Time complexity
3. valid keys datatype
*/

#include <bits/stdc++.h>
using namespace std;

void print(unordered_map<int, string> &m)
{
    cout << m.size() << endl;
    for (auto &pr : m) // time complexity for accessing is also O(1)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}

int main()
{
    unordered_map<int, string> m;
    m[1] = "abc"; // time complexity for insertion is O(1)
    m[5] = "cdc";
    m[3] = "acd";
    m[6] = "a";
    m[5] = "cde";

    // 'find' returns an iterator
    auto it = m.find(7); // O(1)
    // if (it == m.end())  // if no key is found then it will return m.end()
    //     cout << "No value";
    // else
    //     cout << (*it).first << " " << (*it).second << endl;
    if (it != m.end())
        m.erase(it);
    //m.erase(3); // O(1)
    print(m);
}