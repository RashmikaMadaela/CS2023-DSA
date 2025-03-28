#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void quickSort(vector<int>& arr) {
    if (arr.empty()) return;

    stack<pair<int, int>> s;
    s.push({0, arr.size() - 1});

    while (!s.empty()) {
        int left = s.top().first;
        int right = s.top().second;
        s.pop();

        if (left >= right) continue;

        int pivot = arr[right];  // Choosing the last element as pivot
        int partitionIndex = left;  

        for (int i = left; i < right; i++) {
            if (arr[i] < pivot) {
                swap(arr[i], arr[partitionIndex]);
                partitionIndex++;
            }
        }
        swap(arr[partitionIndex], arr[right]);  // Place pivot in correct position

        // Push subarrays into the stack for further sorting
        s.push({left, partitionIndex - 1});
        s.push({partitionIndex + 1, right});
    }
}

int main() {
    int num;
    vector<int> arr;

    // Getting space-separated inputs as an array
    while (cin >> num) {
        arr.push_back(num);
        if (cin.peek() == '\n') {
            break;
        }
    }
    auto start = high_resolution_clock::now();
    quickSort(arr);  // Sorting the array iteratively

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    // Output the sorted array
    for (int j : arr) {
        cout << j << " ";
    }

    return 0;
}