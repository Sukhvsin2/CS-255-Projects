#include "Poly.h"
/**
	Name: Poly
	Input: None
	Output: Setting terms to 0
**/
Poly:: Poly(){
	for(int i=0;i<MAX;i++) terms[i] = 0;
}

/**
	Name: <<
	Input: streaming object to print and Poly obj which has data
	Output: None
**/
ostream& operator<<(ostream &os,const Poly &obj){
	for(int i=MAX-1;i>=0;i--) {
		if(obj.terms[i] != 0){
			if(i > 0) os<<obj.terms[i]<<"x^"<<i<<" + ";
			else os<<obj.terms[i]<<"x";
		}
	}
	return os;
}

/**
	Name: >>
	Input: streaming operator for input and poly obj to get the data
	Output: setting the data in terms
**/
istream& operator>>(istream& is, Poly& obj){
	int coff, temp, pow;
	while(!is.eof()) {
		is>>coff;
		is>>temp;
		is>>pow;
		cout<<"check: "<<coff<<temp<<pow<<"  ";
		obj.terms[pow] = coff;
	}
	return is;
}

/**
	Name: Reset
	Input: None
	Output: Resetting terms to 0
**/
void Poly:: Reset(){
	for(int i=0;i<MAX;i++){
		terms[i] = 0;
	}
}

/**
	Name: Eval
	Input: power
	Output: solving the equation by putting x in the equation
**/
double Poly:: Eval(double x){
	double temp = 1;
	for(int i=0;i<x;i++) temp *= x;
	return temp;
}

/**
	Name: +
	Input: 2 poly objects
	Output: result after adding them
**/
Poly operator+(const Poly& p1, const Poly& p2){
	Poly result;
	for(int i=0;i<MAX;i++){
		result.terms[i] = p1.terms[i] + p2.terms[i];
	}
	return result;
}

/**
	Name: *
	Input: 2 poly objects
	Output: result after multipying them
**/
Poly operator*(const Poly& p1, const Poly& p2){
	Poly result;
	for(int i=0;i<MAX;i++){
		result.terms[i] = p1.terms[i] * p2.terms[i];
	}
	return result;
}

/**
	Name: +=
	Input: poly objects
	Output: result after appending thier result into 1
**/
void Poly:: operator+=(const Poly& p){
	for(int i=0;i<MAX;i++){
		terms[i] += p.terms[i];
	}
}

/**
	Name: Derivative
	Input: None
	Output: None but changing the coff by doing it's derivatives
**/
void Poly:: Derivative(){
	for(int i=0;i<MAX;i++){
		if (i == 0)this->terms[0] *= 1;
		else this->terms[0] *= i;
	}
}
