#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void printFunction (vector<int> arr) {   //This is a function to print the array
    for (int j:arr){
        cout<<j<<" ";
    }
}

void insertionSort1(int n, vector<int> arr) {
    int k = arr[n-1]; //getiing the last element of the array to a seperate variable
    for (int i=n-2; i>=0; i--){
        if (k<arr[i]){
            arr[i+1]= arr[i] ; //shifting
            if (i==0) {
                printFunction(arr);
                cout<<"\n";
                arr[i]=k; //insertion : if we had to check the whole array
                printFunction(arr);
                break;
            }
        } else {
            arr[i+1]=k; //insertion
            printFunction(arr);
            break;
            
        }
        printFunction(arr);
        cout<<"\n";
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort1(n, arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
 