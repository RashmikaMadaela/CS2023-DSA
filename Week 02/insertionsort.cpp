#include <iostream>
#include <stdio.h>
#include <vector>


using namespace std;

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

    int len = arr.size();
    
    //sorting (take each element in a list, compare it to the elements already sorted, and insert it into the correct position within the sorted part of the list)
    for (int i = 1; i < len; i++) {
        int temp = arr[i];
        int j = i - 1;

        // Shift elements to the right to create space for temp
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;  // Insert temp in the correct position
    }

    //printing the output
    for (int i:arr) {
        cout<<i<<" ";
    }
}