#include <bits/stdc++.h>
using namespace std;

int biggestarea(vector<int>& arr) {
    int l = 0;
    int r = arr.size() - 1;
    int storage;
    storage=0;
    while (l < r) {
        int width = r - l;
        int h = min(arr[l], arr[r]);
        int area = width * h;
        storage = max(storage, area);
        
        if (arr[l] < arr[r]) {
            l++;
        } else {
            r--;
        }
    }
    return storage;
}

int main() {
    vector<int> arr;
    cout<<"Enter numbers (enter a non-integer to stop):" << endl;
    int num;
    while (cin>>num) {
        arr.push_back(num);
    }
    cout << biggestarea(arr) << endl;  
    return 0;
}

