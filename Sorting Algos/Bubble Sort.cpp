#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int t = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = t;
      }
    }
  }
}

int main() {
  int size;
  cout << "Enter size of an array: " << endl;
  cin >> size;
  int arr[size];

  for (int i = 0; i < size; i++) {
    int ele;
    cout << "Enter element to insert in array:" << endl;
    cin >> ele;
    arr[i] = ele;
  }

  bubbleSort(arr, size);

  for (int i : arr) {
    cout << i << "\t";
  }
}