#include <iostream>
using namespace std;

#define size 10

struct Node {
  int data;
  Node *next;
};

struct Node
    *arr[size]; //  this is an array of pointers, each index is pointing to node

void all_indexes_null() {
  for (int i = 0; i < size; i++) {
    arr[i] = NULL;
  }
}

void insert_hashing(int value) {
  Node *newNode = new Node;
  newNode->data = value;
  newNode->next = NULL;
  int key = value % size;

  if (arr[key] == NULL) {
    arr[key] = newNode;
  }

  else {
    Node *curr = arr[key];

    while (curr->next != NULL) {
      curr = curr->next;
    }

    curr->next = newNode;
  }
}

void print() {
  for (int i = 0; i < size; i++) {
    Node *temp = arr[i];
    cout << "arr[" << i << "]->";
    while (temp != NULL) {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "-" << endl;
  }
}

int main() {

  all_indexes_null();

  insert_hashing(7);
  insert_hashing(0);
  insert_hashing(3);
  insert_hashing(10);
  insert_hashing(4);
  insert_hashing(5);

  print();

  return 0;
}