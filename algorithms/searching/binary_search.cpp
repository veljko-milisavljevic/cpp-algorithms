// Recursive binary search in a sorted array.
//
// Input:  n, then n integers (any order, they are sorted first), then the value to find.
// Output: the 0-based index of the value in the sorted array, or -1 if it is absent.
//
// Time: O(log n) per search (O(n log n) for the initial sort), memory: O(log n) stack.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& a, int target, int left, int right)
{
    if (left > right) return -1;

    int mid = left + (right - left) / 2; // avoids overflow of (left + right)
    if (a[mid] == target) return mid;
    if (a[mid] > target) return binarySearch(a, target, left, mid - 1);
    return binarySearch(a, target, mid + 1, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    int target;
    cin >> target;

    sort(a.begin(), a.end());
    cout << binarySearch(a, target, 0, n - 1) << '\n';
    return 0;
}
