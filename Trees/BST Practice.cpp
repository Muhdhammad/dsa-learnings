#include <iostream>
#include <stack>
using namespace std;

#include <iostream>
using namespace std;

struct BstNode {
  int data;
  BstNode *left;
  BstNode *right;
};

BstNode *insert(BstNode *root, int value) {
  if (root == NULL) {
    BstNode *temp = new BstNode;
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
  }

  if (value > root->data) {
    root->right = insert(root->right, value);
  }

  else if (value < root->data) {
    root->left = insert(root->left, value);
  }

  return root;
}

void sortDescending(BstNode *root) {
  stack<BstNode *> st;
  BstNode *current = root;

  while (current != nullptr || !st.empty()) {
    while (current != nullptr) {
      st.push(current);
      current = current->right;
    }
    current = st.top();
    st.pop();
    std::cout << current->data << " ";
    current = current->left;
  }
}

void inorder_traversal(BstNode *root) {
  if (root == NULL) {
    return;
  }
  inorder_traversal(root->left);
  cout << root->data << " ";
  inorder_traversal(root->right);
}

void reverse_inorder(BstNode *root) {
  if (root == NULL) {
    return;
  }
  reverse_inorder(root->right);
  cout << root->data << " ";
  reverse_inorder(root->left);
}

bool isSameTree(BstNode *p, BstNode *q) {
  if (p == NULL && q == NULL) {
    return true;
  }
  if (p == NULL || q == NULL) {
    return false;
  }
  if (p->data != q->data) {
    return false;
  }
  return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
}

int main() {
  BstNode *root = NULL;
  BstNode *p = NULL;
  BstNode *q = NULL;

  root = insert(root, 5);
  insert(root, 10);
  insert(root, 4);
  insert(root, 3);
  insert(root, 7);
  insert(root, 20);

  p = insert(p, 5);
  insert(p, 10);
  insert(p, 4);
  insert(p, 3);
  insert(p, 7);
  insert(p, 20);

  q = insert(q, 5);
  insert(q, 10);
  insert(q, 4);
  insert(q, 3);
  insert(q, 7);
  insert(q, 20);

  bool a = isSameTree(p, q);
  cout << a;

  // inorder_traversal(root);

  reverse_inorder(q);
  cout << endl;
  sortDescending(q);
}