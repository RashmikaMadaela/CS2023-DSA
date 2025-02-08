#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void insertionSort2(int n, vector<int> arr) {
    for (int j=1;j<n;j++) { //getting an element from the main array and correctly place it in the left side
        int temp = arr[j]; //taking an element to be correclty placed in the sorted list
        bool flag=false;
        for (int i=j-1; i>=0; i--) { 
            if (arr[i]>temp){
                arr[i+1]=arr[i];
            } else {
                arr[i+1]=temp; //placing the temp element in the correct place
                flag = true;
                break;
            }
        }
        if (flag==false) {
            arr[0] = temp; //placing the temp element in the correct place
        } 
        for (int i:arr) {
            cout<<i<<" ";
        }
        cout<<endl;
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

    insertionSort2(n, arr);

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
