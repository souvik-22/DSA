#include <bits/stdc++.h>
using namespace std;

void print(map<int, string> &m)
{
    cout << m.size() << endl;
    for (auto &pr : m) // time complexity for accessing is also O(log(n))
    {
        cout << pr.first << " " << pr.second << endl;
    }
}

int main()
{
    map<int, string> m;
    m[1] = "abc"; // time complexity for insertion is O(log(n))
    m[5] = "cdc";
    m[3] = "acd";
    m[6] = "a";
    m[5] = "cde"; // keys are unique in maps, 'cdc' will be replaced by 'cde'

    // 'find' returns an iterator
    auto it = m.find(7); // O(log(n))
    // if (it == m.end())  // if no key is found then it will return m.end()
    //     cout << "No value";
    // else
    //     cout << (*it).first << " " << (*it).second << endl;

    if (it != m.end())
        m.erase(it);
    //m.erase(3); // O(log(n))

    //m.clear();

    print(m);

    // m.insert({4, "afg"});
    //m[7]; // O(log(n)) // by default value is 0(zero) in case of int and empty string("") in case of string

    // map<int, string>::iterator it;
    // for (it = m.begin(); it != m.end(); ++it)
    // {
    //     cout << (*it).first << " " << (*it).second << endl;
    // }
    // for (auto &pr : m)
    // {
    //     cout << pr.first << " " << pr.second << endl;
    // }
}