#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int totalcount = 0; // global variable

void insert(Node *&head, int value) {
    Node *ptr = new Node;
    ptr->data = value;

    if (head == NULL) {
        head = ptr;
        ptr->next = NULL;
        totalcount++;
        return;
    }

    Node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = ptr;
    ptr->next = NULL;
    cout << "Node inserted" << endl;
    totalcount++;
}

void traverse(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->data << "\t";
        curr = curr->next;
    }
    cout << "Total count of nodes: " << totalcount << endl;
}

Node *reverseLL(Node *head) {
    Node *dummy = NULL;
    while (head != NULL) {
        Node *next = head->next;
        head->next = dummy;
        dummy = head;
        head = next;
    }
    return dummy;
}

struct Node *lastNode(Node *head) {
    struct Node *curr = head;
    while (curr != NULL && curr->next != NULL) {
        curr = curr->next;
    }
    return curr;
}

Node *partition(Node *first, Node *last) {

    struct Node *pivot = first;
    struct Node *curr = first;
    int temp = 0;
    while (curr != NULL && curr != last) {
        if (curr->data < last->data) {
            pivot = first;

            temp = first->data;
            first->data = curr->data;
            curr->data = temp;

            first = first->next;
        }

        curr = curr->next;
    }

    // Change last node value to current node
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    return pivot;
}

void quick_sort(struct Node *first, struct Node *last) {
    if (first == last) {
        return;
    }
    struct Node *pivot = partition(first, last);

    if (pivot != NULL && pivot->next != NULL) {
        quick_sort(pivot->next, last);
    }

    if (pivot != NULL && first != pivot) {
        quick_sort(first, pivot);
    }
}

void deleteNode(Node *&head, int key) {
    Node *curr = head;
    Node *prev = nullptr;

    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->data == key) {
        Node *temp = head;
        head = head->next;
        delete temp;
        totalcount--;
        return;
    }

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Element not found to delete" << endl;
        return;
    }

    prev->next = curr->next;
    delete curr;
    totalcount--;
}

int main() {
    Node *head = NULL;
    insert(head, 10);
    insert(head, 8);
    insert(head, 2);
    insert(head, 77);

    traverse(head);
    head = reverseLL(head);
    cout << endl;
    traverse(head);

    quick_sort(head, lastNode(head));
    traverse(head);
    deleteNode(head, 77);
    deleteNode(head, 2);
    traverse(head);
}