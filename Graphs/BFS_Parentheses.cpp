#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isBalanced(string s)
    {
        int cnt = 0;
        for (char x : s)
        {
            if (x == '(')
                cnt++;
            else if (x == ')')
                cnt--;
            if (cnt < 0)
                return 0;
        }
        return cnt == 0;
    }

public:
    map<string, bool> vis;
    vector<string> removeInvalidParentheses(string s)
    {
        queue<string> Q;
        vector<string> ans;
        Q.push(s);
        int found = 0;
        while (!Q.empty())
        {
            string u = Q.front();
            Q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            if (isBalanced(u))
            {
                found = 1;
                ans.push_back(u);
            }
            if (found)
                continue;
            for (int i = 0; i < u.size(); i++)
            {
                if (u[i] == '(' || u[i] == ')')
                {
                    string v = u.substr(0, i) + u.substr(i + 1, u.size());
                    Q.push(v);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> result = s.removeInvalidParentheses("(a)())()");
    for (string cur : result)
        cout << cur << endl;
    return 0;
}