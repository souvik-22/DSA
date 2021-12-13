#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int> &a) {
    int n = a.size();
    int sum = a[0];
    int ans = INT_MAX;
    int i = 0, j = 0;
    do {
        if (sum >= target) {
            ans = min(ans, j - i + 1);
            sum -= a[i];
            i++;
        } else {
            j++;
            if (j < n) sum += a[j];
        }
    } while (j < n && i < n);

    if (ans == INT_MAX) return 0;

    return ans;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (minSubArrayLen(target, a))
        cout << "No Subarray exist";
    else
        cout << "Size: " << minSubArrayLen(target, a);
}