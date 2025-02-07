#include <iostream>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;


int main () {
    
    int num;
    vector<int> arr;

    //getting the space seperated inputs as an array
    while (true){
        cin>>num;
        arr.push_back(num);
        if (cin.peek() == '\n') {
        break;
        }
    }

    auto start = high_resolution_clock::now();
    int len = arr.size();
    
    //sorting (works by repeatedly finding the smallest element in an unsorted list and swapping it with the first element of the unsorted part)
    for (int i=0;i<len;i++) {
        int min=arr[i];
        int minIndex=i;
        for (int j=i+1; j<len;j++)
            if (arr[j]<min) {
                min=arr[j];
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=temp;   
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    //printing the output
    for (int i:arr) {
        cout<<i<<" ";
    }

}