#include <iostream>
using namespace std;

void maxHeap(int arr[], int n, int i) {
  int parent = (i - 1) / 2;
  while (parent >= 0 && arr[i] > arr[parent]) {
    swap(arr[i], arr[parent]);
    i = parent;
    maxHeap(arr, n, i);
  }
}

void minHeap(int arr[], int n, int i) {
  int parent = (i - 1) / 2;
  while (parent >= 0 && arr[i] < arr[parent]) {
    swap(arr[i], arr[parent]);
    i = parent;
    minHeap(arr, n, i);
  }
}

// insert in a min heap
void minInsert(int arr[], int &n, int value) {
  n = n + 1;
  arr[n - 1] = value;
  minHeap(arr, n, n - 1);
}

// insert in a max heap
void maxInsert(int arr[], int &n, int value) {
  n = n + 1;
  arr[n - 1] = value;
  maxHeap(arr, n, n - 1);
}

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

void deletion(int arr[], int &n) {

  if (n <= 0) {
    cout << "heap is empty";
    return;
  }
  arr[0] = arr[n - 1];
  n = n - 1;
  heapify(arr, n, 0);
}

int main() {
  int Heap[100]; // Assuming a maximum size for the heap
  int n = 0;     // Current size of the heap

  maxInsert(Heap, n, 10);
  maxInsert(Heap, n, 66);
  maxInsert(Heap, n, 2);
  maxInsert(Heap, n, 15);
  maxInsert(Heap, n, 82);
  maxInsert(Heap, n, 19);
  maxInsert(Heap, n, 35);
  maxInsert(Heap, n, 3);
  maxInsert(Heap, n, 7);
  maxInsert(Heap, n, 777);

  deletion(Heap, n);

  cout << "Max heap array: " << endl;
  for (int i = 0; i < n; i++) {
    cout << Heap[i] << " ";
  }

  return 0;
}