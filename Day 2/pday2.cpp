#include <iostream>
#include <algorithm>
using namespace std;

bool Tripletofzerosum(int arr[], int n) {
    sort(arr, arr + n);  

    for (int i = 0; i < n - 2; ++i) {
        int l = i + 1;
        int r = n - 1;
        int t = -arr[i]; 

        while (l < r) {
            int sum = arr[l] + arr[r];
            if (sum == t) {
                return true;
            } else if (sum < t) {
                ++l;  
            } else {
                --r;  
            }
        }
    }

    return false;  
}

int main() {
    int n;
    cout << "Enter how many elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (Tripletofzerosum(arr, n)) {
        cout << "Output: 1"<<endl;
    } else {
        cout << "Output: 0"<<endl;
    }

    return 0;
}
