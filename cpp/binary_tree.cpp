//
// Created by sun on 16-9-23.
//
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cassert>
using namespace std;
struct Node {
  char id;
  Node *left = NULL;
  Node *right = NULL;
  Node(char i) : id(i) {};
};

Node *recTreeFromPreAndIn(string pre, string mid) {
  if (pre.size() == 0)return NULL;
  Node *node = new Node(pre[0]);
  if (pre.size() == 1) return node;
  int pos = mid.find(pre[0]);
  node->left = recTreeFromPreAndIn(pre.substr(1, pos), mid.substr(0, pos));
  const unsigned long right_len = mid.length() - pos - 1;
  node->right = recTreeFromPreAndIn(pre.substr(pos + 1, right_len), mid.substr(pos + 1, right_len));
  return node;
}
Node *recTreeFromPostAndIn(string post, string mid) {
  if (post.size() == 0)return NULL;
  Node *node = new Node(post[post.size() - 1]);
  if (post.size() == 1) return node;
  int pos = mid.find(post[post.size() - 1]);
  node->left = recTreeFromPostAndIn(post.substr(0, pos), mid.substr(0, pos));
  const unsigned long right_len = mid.length() - pos - 1;
  node->right = recTreeFromPostAndIn(post.substr(pos, right_len), mid.substr(pos + 1, right_len));
  return node;
}

void traverseTree(Node *root, int order, string &res){
  if(root==NULL)return;
  if(order<0)
    res.push_back(root->id);
  traverseTree(root->left, order, res);
  if(order==0)
    res.push_back(root->id);
  traverseTree(root->right, order, res);
  if(order>0)
    res.push_back(root->id);
}
string  traverse          Tree(Node *root, int order){
  string  res;
  traverseTree(root, order, res);
  return  res;
}

int main() {
  Node *root = recTreeFromPreAndIn("ABCDEFG", "CBDAFEG");
  Node *root2 = recTreeFromPostAndIn("CDBFGEA", "CBDAFEG");
  cout<< traverse          Tree(root, -1)<<endl;
  cout<< traverse          Tree(root, 0)<<endl;
  cout<< traverse          Tree(root, 1)<<endl;
  cout << root;
}