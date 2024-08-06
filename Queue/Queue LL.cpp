#include <iostream>
using namespace std;

struct queueNode {
  int item;
  queueNode *next;
};

queueNode *front = NULL;
queueNode *rear = NULL;

void Enqueue(int data) {
  queueNode *temp = new queueNode; // instead of malloc
  temp->item = data;

  if (rear == NULL) {
    front = temp;
    rear = temp;
  }

  else {
    rear->next = temp;
    rear = temp;
  }
}

void Dequeue() {
  queueNode *temp;
  temp = front;

  if (front == NULL) {
    cout << "Underflow" << endl; // Nothing in queue
    return;
  }

  else if (front == rear) {
    front = NULL;
    rear = NULL;
  }

  else {
    front = front->next;
    free(temp);
  }
}

void printQueue() {
  queueNode *curr = front;

  if (curr == NULL) {
    cout << "Queue is empty." << endl;
    return;
  }

  cout << "Queue: ";
  while (curr != NULL) {
    cout << curr->item << " ";
    curr = curr->next;
  }
  cout << endl;
}

int main() {

  int choice;
  int data;

  do {
    cout << "Menu:\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. print\n";
    cout << "4. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter data to enqueue: ";
      cin >> data;
      Enqueue(data);
      break;
    case 2:
      Dequeue();
      break;
    case 3:
      printQueue();
      break;
    case 4:
      cout << "Exiting program.\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
      break;
    }
  } while (choice != 4);
}