#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/insertionsort1/copy-from/155639347

vector<string> split_string(string);

void printArray(int n, vector<int> arr)
{
    for(int i = 0; i < n; i++)
    {
        if(i != 0)
        {
            cout<<" ";
        }
        cout<<arr[i];
    }
    cout<<endl;
}
void insertionSort1(int n, vector<int> arr) {

   int value = arr[n-1];
   int hole = n-1;

   while(hole > 0 && arr[hole-1] > value)
   {
      arr[hole] = arr[hole-1];
      hole = hole - 1;

      printArray(n, arr);
   }

   arr[hole] = value;
   printArray(n, arr);

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort1(n, arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
