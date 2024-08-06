#include <iostream>
using namespace std;

struct StackNode {
  int data;
  StackNode *next;
};

struct StackNode *top = NULL;

void push(int key) {
  StackNode *temp = new StackNode;
  temp->data = key;
  temp->next = top;
  top = temp;
}

int pop() {
  if (top == NULL) {
    return -1;
  }

  int value = top->data;
  StackNode *temp = top;
  top = top->next;
  free(temp);
  return value;
}

void display() {
  StackNode *temp = top;
  if (temp == NULL) {
    cout << "Stack is empty" << endl;
    return;
  }
  while (temp != NULL) {
    cout << temp->data << "\t";
    temp = temp->next;
  }
}

int main() {
  int choice = 0;
  cout << "Stack with linked list:" << endl;
  while (choice != 4) {

    cout << "1.push" << endl;
    cout << "2.pop" << endl;
    cout << "3.display" << endl;
    cout << "4.exit" << endl;

    cin >> choice;
    switch (choice) {
    case 1: {
      int key;
      cout << "Enter key to push in stack" << endl;
      cin >> key;
      push(key);
      break;
    }
    case 2: {
      pop();
      break;
    }
    case 3: {
      display();
      break;
    }
    case 4: {
      break;
    }
    default: {
      cout << "Please choose from 1-4" << endl;
    }
    };
  }
}