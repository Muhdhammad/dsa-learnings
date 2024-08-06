#include <iostream>
using namespace std;

int stack[100], n = 100, top = -1;
void push(int val) {
  if (top >= n - 1)
    cout << "Stack Overflow" << endl;
  else {
    top++;
    stack[top] = val;
  }
}
void pop() {
  if (top <= -1)
    cout << "Stack Underflow" << endl;
  else {
    cout << "The popped element is " << stack[top] << endl;
    top--;
  }
}
void display() {
  if (top >= 0) {
    cout << "Stack elements are:";
    for (int i = top; i >= 0; i--)
      cout << stack[i] << " ";
    cout << endl;
  } else
    cout << "Stack is empty";
}

int main() {
  int choice = 0;
  cout << "Stack with array:" << endl;
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