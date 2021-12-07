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

/**
	Name: Copy
	Return: None
	Outgoing: coping data from paramter object to calling object
	Incoming: object in parameters
	Purpose: Deep Copy of data from paramter object to calling
**/
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


/**
	Name: Add Terms
	Return: None
	Outgoing: Decending order List
	Incoming: c as in Coefficent and d as in Degree of coefficent
	Purpose: Inserting Data in decending order
**/
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

/**
	Name: POW
	Return: double value
	Outgoing: value according to degree
	Incoming: Number as num and Power as p
	Purpose: Multiply num according to power on it
**/
double pow(int num, int p){
	double result = 1;
	for(int i=0;i<p;i++){
		result *= num;
	}
	return p;
}

/**
	Name: Evaluate
	Return: double value
	Outgoing: result after putting value of x in the equation
	Incoming: x as in value of x variable for the equation
	Purpose: Caluculating result after putting value of x in the equation
**/
double Poly::Eval(double x){
	double result = 0;
	Node *temp = head;
	while(temp != nullptr){
		cout<<temp->coeff<<" ";
		result += temp->coeff * pow(x, temp->degree);
		temp = temp->next;
	}
    return result;
}

/**
	Name: Reset
	Return: None
	Outgoing: None
	Incoming: Calling object by this variable
	Purpose: Reseting the whole linkedlist by deleteing all elements and head set to null again
**/
void Poly::Reset(){
	Node* temp;
	while(head != nullptr){
		temp = head;
		head = head->next;
		delete temp;
	}
	head = nullptr;
	
}


/**
	Name: Derivative
	Return: none
	Outgoing: Modified list
	Incoming: list by this operator
	Purpose: Caluculating derivative of linkedlist
**/
void Poly::Derivative(){
	Node *temp = head;
	while(temp != nullptr){
		temp->coeff *= temp->degree;
		temp->degree--;
		temp = temp->next;
	}
}

/**
	Name: >>
	Return: input stream
	Outgoing: value in the object p in decending order 
	Incoming: is as in input object and p as in calling object
	Purpose: Inputing the value from the file
**/
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


/**
	Name: <<
	Return: output stream
	Outgoing: none
	Incoming: os as in output stream object and p as in the calling object for disaplay
	Purpose: Displaying objects/list's data on the screen
**/
ostream& operator<<(ostream& os, const Poly& p){
	Node *temp = p.head;
	while(temp != nullptr){
    	if(temp->degree != 0){
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


/**
	Name: +
	Return: New Polynomial equation 
	Outgoing: New polynomial equation after adding
	Incoming: p1,p2 as 2 lists for addition
	Purpose: Adding 2 polynomial equations after adding them together
**/
Poly operator+(const Poly& p1, const Poly& p2){
	Poly result;
	Node *temp1 = p1.head;
	Node *temp2 = p2.head;
	while(temp1!=nullptr || temp2!=nullptr){
		if(temp1 != nullptr){
			result.AddTerm(temp1->coeff, temp1->degree);
			temp1 = temp1->next;	
		}else if(temp2 != nullptr){
			result.AddTerm(temp2->coeff, temp2->degree);
			temp2 = temp2->next;	
		}
	}
	
	return result;
}



