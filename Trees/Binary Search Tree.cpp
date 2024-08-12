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

void inorder_traversal(BstNode *root) {
  if (root == NULL) {
    return;
  }
  inorder_traversal(root->left);
  cout << root->data << " ";
  inorder_traversal(root->right);
}

void preorder(BstNode *root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(BstNode *root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

BstNode *tofind(BstNode *root, int key) {

  if (root == NULL) {
    return NULL;
  }

  else if (key > root->data) {
    return tofind(root->right, key);
  }

  else if (key < root->data) {
    return tofind(root->left, key);
  }

  else {
    return root;
  }
}

BstNode *findmin(BstNode *root) {
  if (root == NULL) {
    return NULL;
  }
  if (root->left) {
    return findmin(root->left);
  } else
    return root;
}

// min find iteratively
int minvalue(BstNode *root) {
  int minv = root->data;
  while (root->left != NULL) {
    minv = root->left->data;
    root = root->left;
  }
  return minv;
}

void invertBst(BstNode *root) {

  if (root == NULL) {
    return;
  }
  // first we invert left subtree
  invertBst(root->left);
  // second we invert right subtree
  invertBst(root->right);
  // swap
  swap(root->left, root->right);
}

// Inorder successor
BstNode *successor(BstNode *root, int key) {

  BstNode *successor = NULL;
  while (root != NULL) {
    if (key >= root->data) {
      root = root->right;
    }

    else {
      successor = root;
      root = root->left;
    }
  }
  return successor;
}

// for inorder predecessor just convert right to left
BstNode *predecessor(BstNode *root, int key) {
  BstNode *predecessor = NULL;

  while (root != NULL) {
    if (key <= root->data) {
      root = root->left;
    }

    else {
      predecessor = root;
      root = root->right;
    }
  }
  return predecessor;
}

BstNode *deleteNode(BstNode *root, int key) {
  if (root == NULL) {
    return NULL;
  }

  if (key < root->data) {
    root->left = deleteNode(root->left, key);
  }

  else if (key > root->data) {
    root->right = deleteNode(root->right, key);
  }

  else {
    if (root->left == NULL) {
      return root->right;
    } else if (root->right == NULL) {
      return root->left;
    }
    root->data = minvalue(root->right);
    root->right = deleteNode(root->right, root->data);
  }
  return root;
}

int main() {
  BstNode *root = NULL;
  root = insert(root, 5);
  insert(root, 10);
  insert(root, 4);
  insert(root, 3);
  insert(root, 7);
  insert(root, 20);

  BstNode *min = findmin(root);
  cout << min->data;

  cout << endl;
  inorder_traversal(root);
  cout << endl;

  // invertBst(root);
  // inorder_traversal(root);

  BstNode *search = tofind(root, 10);
  if (search != NULL) {
    cout << "key found: " << search->data << endl;
  } else {
    cout << "key not found" << endl;
  }

  int key = 4;
  BstNode *suc = successor(root, key);
  if (suc == NULL) {
    cout << "No successor found" << endl;
  }
  cout << "successor of " << key << " is " << suc->data << endl;

  BstNode *pre = predecessor(root, key);
  if (pre == NULL) {
    cout << "No predecessor found" << endl;
  }
  cout << "predecessor of " << key << " is " << pre->data << endl;

  // deletion(root, 5);
  deleteNode(root, 20);
  inorder_traversal(root);
}