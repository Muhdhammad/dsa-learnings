#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

void insert(Node *&head, int value) {
  Node *ptr = new Node;
  ptr->data = value;

  if (head == nullptr) {
    head = ptr;
    ptr->next = head;
    return;
  }

  Node *curr = head;
  while (curr->next != head) {
    curr = curr->next;
  }

  curr->next = ptr;
  ptr->next = head;
  cout << "Node inserted" << endl;
}

void tofind(Node *head, int key) {
  Node *curr = head;
  bool found = false;
  if (curr == NULL) {
    cout << "list is empty";
    return;
  }

  do {
    if (curr->data == key) {
      cout << "key found" << endl;
      found = true;
      break;
    }
    curr = curr->next;
  } while (curr != head);

  if (found == false) {
    cout << "key not found" << endl;
  }
}

void deleteNode(Node *&head, int key) {
  if (head == nullptr) {
    cout << "List is empty" << endl;
    return;
  }

  Node *curr = head;
  Node *prev = nullptr;

  // Find the node to be deleted and its previous node
  do {
    if (curr->data == key) {
      break;
    }
    prev = curr;
    curr = curr->next;
  } while (curr != head);

  // If key not found
  if (curr == head && curr->data != key) {
    cout << "Element not found to delete" << endl;
    return;
  }

  // If the key is found at the head of the list
  if (curr == head) {
    Node *temp = head;
    // If there is only one node in the list
    if (temp->next == head) {
      head = nullptr;
    } else {
      // Find the last node to update its next pointer
      Node *last = head;
      while (last->next != head) {
        last = last->next;
      }
      head = head->next;
      last->next = head;
    }
    delete temp;
  } else {
    // If the key is found in the middle or end of the list
    prev->next = curr->next;
    delete curr;
  }
}

void traverse(Node *head) {
  Node *curr = head;
  if (head != NULL) {
    do {
      cout << curr->data << "\t";
      curr = curr->next;
    } while (curr != head);
  }
}

int main() {
  Node *head = NULL;
  insert(head, 10);
  insert(head, 8);
  insert(head, 2);
  insert(head, 77);

  traverse(head);
  tofind(head, 2);

  deleteNode(head, 10);
  traverse(head);
}