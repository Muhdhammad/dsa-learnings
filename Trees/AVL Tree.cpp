#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  int height;
};

int getheight(Node *root) {
  if (root == NULL) {
    return 0;
  }
  return root->height;
}

int balancingFactor(Node *root) {
  return getheight(root->left) - getheight(root->right);
}

// for LL tree
Node *rightRotate(Node *root) {
  Node *child = root->left;
  Node *rightChild = child->right;

  // Now rotations
  child->right = root;
  root->left = rightChild;

  // Now update height of both root and child
  root->height = 1 + max(getheight(root->left), getheight(root->right));
  child->height = 1 + max(getheight(child->left), getheight(child->right));

  return child;
}

// for RR tree
Node *leftRotate(Node *root) {
  Node *child = root->right;
  Node *leftChild = child->left;

  // Now rotations
  child->left = root;
  root->right = leftChild;

  // Now update height of both root and child
  root->height = 1 + max(getheight(root->left), getheight(root->right));
  child->height = 1 + max(getheight(child->left), getheight(child->right));

  return child;
}

// Standard BST insertion
Node *insert(Node *root, int key) {
  if (root == NULL) {
    Node *temp = new Node; // temp is just a new node
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
  }

  if (key < root->data) {
    root->left = insert(root->left, key);
  } else if (key > root->data) {
    root->right = insert(root->right, key);
  } else {
    return root;
  }

  // update height
  root->height = 1 + max(getheight(root->left), getheight(root->right));

  // check balancing factor
  int balance = balancingFactor(root);

  // LL
  if (balance > 1 && key < root->left->data) {
    return rightRotate(root);
  }

  // RR
  else if (balance < -1 && key > root->right->data) {
    return leftRotate(root);
  }

  // LR
  else if (balance > 1 && key > root->left->data) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // RL
  else if (balance < -1 && key < root->right->data) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  // No unbalancing
  else {
    return root;
  }
}

void preorder(Node *root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void postorder(Node *root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
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

  root = insert(root, 100);
  root = insert(root, 170);
  root = insert(root, 150);
  root = insert(root, 55);
  root = insert(root, 98);
  root = insert(root, 65);
  root = insert(root, 70);
  root = insert(root, 120);
  root = insert(root, 11);
  root = insert(root, 59);
  root = insert(root, 86);
  root = insert(root, 75);

  cout << "preorder traversal:" << endl;
  preorder(root);
  cout << endl;

  cout << "inorder traversal:" << endl;
  inorder(root);
  cout << endl;

  cout << "postorder traversal:" << endl;
  postorder(root);
  cout << endl;

  cout << "levelorder traversal:" << endl;
  levelorder(root);
  cout << endl;
}