#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Key found at index: " << i << endl;
            break;
        }
        cout << "Key not found" << endl;
    }
}

int main() {
    int size;
    int key;
    cout << "Enter size of an array: " << endl;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++) {
        int ele;
        cout << "Enter element to insert in array:" << endl;
        cin >> ele;
        arr[i] = ele;
    }
    cout << "Enter key to find" << endl;
    cin >> key;
    linearSearch(arr, size, key);
}
