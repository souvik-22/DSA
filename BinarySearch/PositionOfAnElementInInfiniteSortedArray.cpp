#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int target, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target < arr[mid])
            end = mid - 1;
        else if (target > arr[mid])
            start = mid + 1;
        else
            return mid;
    }
    return -1;
}

int ans(int arr[], int target)
{
    int start = 0;
    int end = 1;

    while (arr[end] < target)
    {
        int newStart = end + 1;
        // double the box value
        // end = previous end + sizeofbox * 2
        end = end + (end - start + 1) * 2;
        start = newStart;
    }

    return binarySearch(arr, target, start, end);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 23, 45, 78, 90};
    int target = 45;
    int res = ans(arr, target);
    if (res == -1)
        cout << "Not found!" << endl;
    else
        cout << "Found at index: " << res << endl;

    return 0;
}