#include<iostream>
#include<Math.h>

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
    bool insertNode(int data, Node *&root){
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
    void inorderNode(Node *root){
        if(root == nullptr) return;
        inorderNode(root->left);
        cout<<root->data<<" ";
        inorderNode(root->right);
    };
    void prefixNode(Node *root){
        if(root == nullptr) return;
        cout<<root->data<<" ";
        inorderNode(root->left);
        inorderNode(root->right);
    };
    void postfixNode(Node *root){
        if(root == nullptr) return;
        inorderNode(root->left);
        inorderNode(root->right);
        cout<<root->data<<" ";
    };
    Node* searchNode(int data, Node *root){
        if(root == nullptr) return nullptr;
        if(root->data == data){
            return root;
        }else{
            if(data < root->data) searchNode(data, root->left);
            else searchNode(data, root->right);
        }

    }
	int maxInt(int a, int b){
			return a > b ? a : b;
	}
	int treeHeightHelper(Node* root){
		if(root == nullptr) return -1;
		else{
			return maxInt(treeHeightHelper(root->left), treeHeightHelper(root->right));
		}
	}
    public:
        BinaryTree(){
            root = nullptr;
            this->level = 0;
        }
        bool insert(int data){
            return insertNode(data, root);
        }
        void inorder(){
            inorderNode(root);
        }
        void prefix(){
            prefixNode(root);
        }
        void postfix(){
            postfixNode(root);
        }
        void search(int data){
            Node *temp = searchNode(data, root);
            if(temp) cout<<"Found it: "<<temp<<endl;
            else cout<<"Not in the Tree!"<<endl;
        }
		int treeHeight(){
			treeHeightHelper(root);
		}
		void counts(){
			cout<<"Node Counts: "<<nodeCounts<<endl;
		}
};

int main(){
    BinaryTree B;
    B.insert(50);
    B.insert(40);
    B.insert(45);
    B.insert(60);
    B.insert(55);
    B.insert(65);
    B.insert(75);


    B.inorder();
    cout<<endl;
    B.prefix();
    cout<<endl;
    B.postfix();
    cout<<endl;
    B.search(1000);
	B.counts();
	cout<<"level: "<<B.treeHeight();

    return 0;
}