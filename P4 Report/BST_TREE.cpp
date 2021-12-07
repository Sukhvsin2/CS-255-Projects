/**
	Name: Sukhvinder Singh
	Class: CS255
	Date: 12/6/21
	Purpose: Relationship b.w nodes and height
	Motive: Functions to demonstrate height and total node in a tree
**/

#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
        Node(){
            left = right = nullptr;
        }
};

class BinaryTree{
    Node *root;
    int level, nodeCounts;
    bool insertNode(int, Node*&);
    void infixNode(Node*);
    void prefixNode(Node*);
    void postfixNode(Node*);
    int maxInt(int, int);
    int treeHeightHelper(Node*);
    Node* searchNode(int, Node*);
    public:
        BinaryTree();
        bool insert(int);
        void infix();
        void prefix();
        void postfix();
        void search(int);
        void counts();
        int treeHeight();
};

BinaryTree::BinaryTree(){
    root = nullptr;
}

bool BinaryTree::insertNode(int data, Node *&root){
    if(root == nullptr){
        Node *newNode = new Node();
        newNode->data = data;
        root = newNode;
		nodeCounts++;
        return true;
	}else{
        if(data < root->data) insertNode(data, root->left);
        else if(data > root->data) insertNode(data, root->right);
		else return false;
    }
}
void BinaryTree::infixNode(Node *root){
    if(root == nullptr) return;
	infixNode(root->left);
    cout<<root->data<<" ";
	infixNode(root->right);
};
void BinaryTree::prefixNode(Node *root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    prefixNode(root->left);
	prefixNode(root->right);
};
void BinaryTree::postfixNode(Node *root){
    if(root == nullptr) return;
    postfixNode(root->left);
	postfixNode(root->right);
    cout<<root->data<<" ";
};
Node* BinaryTree::searchNode(int data, Node *root){
    if(root == nullptr) return nullptr;
    if(root->data == data){
        return root;
    }else{
        if(data < root->data) searchNode(data, root->left);
        else searchNode(data, root->right);
    }
}
int BinaryTree::maxInt(int a, int b){
		return a > b ? a : b;
}
int BinaryTree::treeHeightHelper(Node* root){
	if(root == nullptr) return -1;
	else{
		return maxInt(treeHeightHelper(root->left), treeHeightHelper(root->right));
	}
}

bool BinaryTree::insert(int data){
    return insertNode(data, root);
}
void BinaryTree::infix(){
    infixNode(root);
}
void BinaryTree::prefix(){
    prefixNode(root);
}
void BinaryTree::postfix(){
    postfixNode(root);
}
void BinaryTree::search(int data){
    Node *temp = searchNode(data, root);
    if(temp) cout<<"Found it: "<<temp<<endl;
    else cout<<"Not in the Tree!"<<endl;
}
int BinaryTree::treeHeight(){
	return treeHeightHelper(root);
}
void BinaryTree::counts(){
	cout<<"Node Counts: "<<nodeCounts<<endl;
}

int main(){
    BinaryTree B;
    B.insert(50);
    B.insert(40);
    B.insert(45);
    B.insert(60);
    B.insert(55);

    B.infix();
    cout<<endl;
    B.prefix();
    cout<<endl;
    B.postfix();
    cout<<endl;
	B.counts();
	cout<<"level: "<<B.treeHeight();

    return 0;
}
