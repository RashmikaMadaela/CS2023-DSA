#include <iostream>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int> quickSort(vector<int> arr) {
    if (arr.size() <= 1) return arr;  
    
    int pivot = arr[0];
    vector<int> leftarr, rightarr;
    int N = arr.size();

    for (int i = 1; i < N; i++) {  
        if (arr[i] < pivot) {
            leftarr.push_back(arr[i]);
        } else {
            rightarr.push_back(arr[i]);
        }
    }

    
    vector<int> sortedLeft = quickSort(leftarr);
    vector<int> sortedRight = quickSort(rightarr);


    sortedLeft.push_back(pivot);
    sortedLeft.insert(sortedLeft.end(), sortedRight.begin(), sortedRight.end());

    return sortedLeft;  
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
    int len = arr.size();

    // Sorting the array
    vector<int> sortedArr = quickSort(arr);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
         
    // Output the sorted array
    for (int j : sortedArr) {
        cout << j << " ";
    }

    return 0;
}