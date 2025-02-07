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
    
    //sorting (repeatedly comparing adjacent elements in a list and swapping them if they are in the wrong order)
    for (int i=0;i<len;i++) {
        for (int j=0; j<len-(i+1);j++)
            if (arr[j]>arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
        }
    }

    //printing the output
    for (int i:arr) {
        cout<<i<<" ";
    }
}