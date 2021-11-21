#include "Poly.h"
// ***********************************************
// Shell code provided by Dr. Janet T. Jenkins
// You should comment each method and add
// header comments below these comments
// ***********************************************

Node::Node():coeff(0), degree(0){}
Node::Node(int c, int d):coeff(c), degree(d), next(nullptr){}
Node::Node(int c, int d, Node* n):coeff(c), degree(d), next(n){}
	
	
Poly::Poly():head(nullptr){

}

void Poly::Copy(const Poly& p){
	Node *temp = p.head;
	while(temp != nullptr && &p != this){
		this->AddTerm(temp->coeff, temp->degree);
		temp = temp->next;
	}
}

Poly::Poly(const Poly& p){
	Copy(p);
}
Poly& Poly::operator= (const Poly& p){
	if (this == &p)
		return *this;
	if (head != nullptr)
		Reset();
	Copy(p);
	return *this;
	
}
Poly::~Poly(){
	Reset();
}
void Poly::AddTerm(int c, int d){
	Node *newNode = new Node(c, d, nullptr);
	
	if(this->head == nullptr)this->head = newNode;
	else if(this->head->degree != d && this->head->degree < d){
		head = new Node(c, d, head);
	}else{
		Node *temp = head, *prev = temp;
		while(temp != nullptr && d < temp->degree){
			prev = temp;
			temp = temp->next;
		}
		if(d != prev->degree){
			newNode->next = prev->next;
			prev->next = newNode;
		}
	}
}
double Poly::Eval(double x){
    return 0;
}


void Poly::Reset(){
	Node* temp = head;
	while(head != nullptr){
		temp = head;
		delete temp;
		head = head->next;
	}
	delete head;
	
}

void Poly::Derivative(){

}

istream& operator>>(istream& is, Poly& p){
	char temp;
	int coff = 0, deg = coff;
	is>>temp;
	while(temp != '>'){
		is>>coff;
		is>>temp;
		is>>temp;
		is>>deg;
		p.AddTerm(coff,deg);
		is>>temp;
	}
	return is;
}
ostream& operator<<(ostream& os, const Poly& p){
	Node *temp = p.head;
	while(temp != nullptr){
    	if(temp->degree != 0 && temp->degree != 1){
    		os<<temp->coeff;
    		os<<"x^";
    		cout<<temp->degree;
    		if(temp->next != nullptr) os<<"+";
		}else{
			os<<temp->coeff;
		}
    	temp = temp->next;
	}
	return os;
}
Poly operator+(const Poly& p1, const Poly& p2){
	Poly result;
	
	return result;
}



