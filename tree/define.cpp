#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int value)
  {
    data = value;
    left = nullptr;
    right = nullptr;
  }
};
void printTree(Node *root)
{
  if (root == nullptr)
    return;
  cout << root->data << " ";
  printTree(root->left);
  printTree(root->right);
}
int sumTree(Node *root)
{
  if (root == nullptr)
    return 0;
  return root->data + sumTree(root->left) + sumTree(root->right);
}
int sizeTree(Node *root)
{
  if (root == nullptr)
    return 0;
  return 1 + sizeTree(root->left) + sizeTree(root->right);
}
int maxTree(Node *root)
{
  if (root == nullptr)
    return INT_MIN; // Return minimum integer value if tree is empty

  return max(root->data, max(maxTree(root->left), maxTree(root->right)));
}
int noOfLevels(Node *root)
{
  if (root == nullptr)
    return 0;
  return 1 + max(noOfLevels(root->left), noOfLevels(root->right));
}
int maxDiameter(Node *root, int &diameter)
{
  if (root == nullptr)
    return 0;

  int leftHeight = maxDiameter(root->left, diameter);
  int rightHeight = maxDiameter(root->right, diameter);

  diameter = max(diameter, leftHeight + rightHeight);

  return 1 + max(leftHeight, rightHeight);
}
void preorder(Node *root)
{
  if (root == nullptr)
    return;
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}
void inorder(Node *root)
{
  if (root == nullptr)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
void postorder(Node *root)
{
  if (root == nullptr)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}
void levelOrder(Node *root)// 
{
  if (root == nullptr)
    return;

  cout << root->data << " ";
  levelOrder(root->left);
  levelOrder(root->right);
}
int main()
{
  Node *a = new Node(1);
  Node *b = new Node(2);
  Node *c = new Node(3);
  Node *d = new Node(4);
  Node *e = new Node(5);
  Node *f = new Node(6);
  Node *g = new Node(7);
  Node *h = new Node(8);
  Node *i = new Node(9);
  Node *j = new Node(10);
  Node *k = new Node(11);

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = g;
  d->left = h;
  g->left = k;
  e->left = i;
  e->right = j;

  printTree(a);
  cout << endl;
  sumTree(a);
  cout << "Sum of all nodes: " << sumTree(a) << endl;
  cout << "Size of tree: " << sizeTree(a) << endl;
  cout << "Max value in tree: " << maxTree(a) << endl;
  cout << "Number of levels in tree: " << noOfLevels(a) << endl;
  cout << "Diameter of tree: ";
  int diameter = 0;
  maxDiameter(a, diameter);
  cout << diameter << endl;
  cout << "Preorder traversal: ";
  preorder(a);
  cout << endl;
  cout << "Inorder traversal: ";
  inorder(a);
  cout << endl;
  cout << "Postorder traversal: ";
  postorder(a);
  cout << endl;
  return 0;
}