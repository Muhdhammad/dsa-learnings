#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
  for (int j = 0; j < size - 1; j++) {
    int min_index = j;
    for (int i = j + 1; i < size; i++) {
      if (arr[i] < arr[min_index]) {
        min_index = i;
      }
    }
    int t = arr[j];
    arr[j] = arr[min_index];
    arr[min_index] = t;
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

  selectionSort(arr, size);

  for (int i : arr) {
    cout << i << "\t";
  }
}
