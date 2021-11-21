#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* ptr;
        Node(int data){
            this->data = data;
        }
};

class LinkedList{
    Node *head;
    public:
        LinkedList(){
            head = nullptr;
        }
        void insert(int data){
            Node* newNode = new Node(data);
            Node* temp = head;
            newNode->ptr = temp;
            head = newNode;
        }
        void append(int d){
            Node *newNode = new Node(d);
            if(head == nullptr){
                head = newNode;
                return;
            }
            Node *temp = head;
            while(temp->ptr != nullptr){
                temp = temp->ptr;
            }
            temp->ptr = newNode;
        }
		Node* find(int key){
			Node* temp = head;
			int counter = 0;
			while(temp != nullptr){
				counter++;
				if(temp->data == key){
					cout<<"\n"<<key<<" Found at: "<<counter;
					return temp;
				}
				temp = temp->ptr;
			}
			cout<<"\nError: No data in the linkedList!"<<endl;
		}

		void deletebeg(){
			Node* temp = head;
			head = head->ptr;
			delete temp;
		}

         void deleteEnd(){
            Node *temp = head, *prev;
            if(head==nullptr || head->ptr==nullptr){
                cout<<"List is Empty";
                delete head;
                head = nullptr;
                return;
            }
            while(temp->ptr!=nullptr){
                prev=temp;
                temp=temp->ptr;
            }
            prev->ptr = nullptr;
            delete temp;
        }

        void insertAt(int pos, int item){
            Node *temp = head, *prev = head;
            int i=0;
            if(temp == nullptr){
                cout<<"Head is Null";
                return;
            }else{
                while(temp != nullptr && i < pos-1){
                    i++;
                    prev = temp;
                    temp = temp->ptr;
                }
                Node *newNode = new Node(item);
                prev->ptr = newNode;
                newNode->ptr = temp;

            }

        }

        void insertOrder(int data){
            Node *curr = head, *prev = curr;
            Node *newNode = new Node(data);
            if(curr != nullptr && data < curr->data){
                if(curr->data == data) return;
                head = newNode;
                newNode->ptr = curr;
            }else{
                while(curr != nullptr && data >= curr->data){
                    if(curr->data == data) return;
                    prev = curr;
                    curr = curr->ptr;
                }
                prev->ptr = newNode;
                newNode->ptr = curr;
            }
        }
        // My Code
		void reverseLinkedList(){
			// 2<-3->4->5->8
			Node *temp = head->ptr, *prev = head, *helper = head;
			while(helper != nullptr){
				temp->ptr = prev;
				
				prev = temp;
				helper = helper->ptr;
				temp = helper;
				cout<<"\n"<<helper->data;
			}
		}
        void print(){
            Node *temp = head;
            while(temp != nullptr){
                cout<<temp->data<<" ";
                temp = temp->ptr;
            }
            cout<<"\n\n";
        }
};

int main(){
    LinkedList l1;
    l1.append(10);
    l1.append(20);
    l1.append(30);
	l1.print();
	cout<<"reverseLinkedList"<<endl;
	l1.reverseLinkedList();
	l1.print();
    return 0;
}
