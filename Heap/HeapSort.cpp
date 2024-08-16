#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
  int largest = i;
  // get child
  int lc = (2 * i) + 1;
  int rc = (2 * i) + 2;

  if (lc < n && arr[lc] > arr[largest]) {
    largest = lc;
  }

  if (rc < n && arr[rc] > arr[largest]) {
    largest = rc;
  }

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  for (int i = (n / 2) - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  // extrct elements form last to add in array
  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main() {
  int arr[] = {7, 11, 12, 5, 6, 80, 54, 15, 1, 51, 66, 22};
  int n = sizeof(arr) / sizeof(int);

  heapSort(arr, n);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}