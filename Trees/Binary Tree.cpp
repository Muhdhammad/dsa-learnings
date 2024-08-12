#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *CreateNode(int data) {
  Node *newNode = new Node();
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node *InsertNode(Node *root, int data) {
  if (root == NULL) {
    root = CreateNode(data);
    return root;
  }

  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();

    if (temp->left == NULL) {
      temp->left = CreateNode(data);
      return root;
    } else {
      q.push(temp->left);
    }

    if (temp->right == NULL) {
      temp->right = CreateNode(data);
      return root;
    } else {
      q.push(temp->right);
    }
  }
  return root;
}

void inorder(Node *temp) {
  if (temp == NULL)
    return;

  inorder(temp->left);
  cout << temp->data << ' ';
  inorder(temp->right);
}

void levelorder(Node *root) {
  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();
    cout << curr->data << " ";

    if (curr->left != NULL) {
      q.push(curr->left);
    }
    if (curr->right != NULL) {
      q.push(curr->right);
    }
  }
}

int main() {
  Node *root = NULL;

  root = InsertNode(root, 10);
  InsertNode(root, 11);
  InsertNode(root, 7);
  InsertNode(root, 9);
  InsertNode(root, 15);
  InsertNode(root, 8);

  cout << "Inorder traversal after insertion: ";
  inorder(root);
  cout << endl;

  cout << "levelorder traversal:" << endl;
  levelorder(root);
  cout << endl;

  return 0;
}
