#include <iostream>
using namespace std;

int binarySearch(int array[], int n, int key) {

  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == key)
      return mid;

    if (array[mid] < key)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
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
  int result = binarySearch(arr, size, key);

  if (result == -1) {
    cout << "key not found" << endl;
  } else {
    cout << "key found " << result << endl;
  }
}
