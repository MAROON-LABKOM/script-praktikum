/*
  Praktikum Struktur Data
  Laboratorium Komputer
  Universitas Pakuan
  2022
*/

#include <iostream>

struct Node
{
  int value;
  Node *left;
  Node *right;

  Node(int value)
  {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

// Preorder traversal
void preorderTraversal(struct Node *node)
{
  if (node == NULL)
    return;

  std::cout << node->value << "->";
  preorderTraversal(node->left);
  preorderTraversal(node->right);
}

// Postorder traversal
void postorderTraversal(struct Node *node)
{
  if (node == NULL)
    return;

  postorderTraversal(node->left);
  postorderTraversal(node->right);
  std::cout << node->value << "->";
}

// Inorder traversal
void inorderTraversal(struct Node *node)
{
  if (node == NULL)
    return;

  inorderTraversal(node->left);
  std::cout << node->value << "->";
  inorderTraversal(node->right);
}

// Referensi: https://stackoverflow.com/a/51730733/5561144
void print(const std::string &prefix, const Node *node, bool isLeft)
{
  if (node != NULL)
  {
    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");

    std::cout << node->value << std::endl;

    auto ikon = isLeft ? "│   " : "    ";
    print(prefix + ikon, node->left, true);
    print(prefix + ikon, node->right, false);
  }
}

// Referensi: https://www.programiz.com/dsa/tree-traversal
int main()
{
  Node *root = new Node(1);
  root->left = new Node(12);
  root->right = new Node(9);
  root->left->left = new Node(5);
  root->left->right = new Node(6);

  print("", root, false);

  std::cout << "Inorder traversal: ";
  inorderTraversal(root);

  std::cout << "\nPreorder traversal: ";
  preorderTraversal(root);

  std::cout << "\nPostorder traversal: ";
  postorderTraversal(root);
}
