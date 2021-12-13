#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr) {
  int n = arr.size();
  int k = arr[0];  // k stores the value of maximum element.
  // k = *max_element(arr.begin(), arr.end());
  for (int i = 1; i < n; i++) {
    k = max(k, arr[i]);
  }

  vector<int> count(k + 1, 0);

  for (int i = 0; i < n; i++) {
    count[arr[i]]++;  // stores the frequency of each element
  }

  for (int i = 1; i <= k; i++) {
    count[i] += count[i - 1];
  }

  vector<int> output(n);

  for (int i = n - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
    // OR output[--count[arr[i]]] = arr[i];
  }

  arr = output;
}

int main() {
  vector<int> arr = {1, 3, 2, 3, 4, 1, 6, 4, 3};

  countSort(arr);

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  return 0;
}