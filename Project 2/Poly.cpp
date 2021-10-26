#include "Poly.h"

Poly:: Poly(){
	for(int i=0;i<MAX;i++) terms[i] = 0;
}

ostream& operator<<(ostream &os,const Poly &obj){
	for(int i=MAX-1;i>=0;i--) {
		//if(obj.terms[i] != 0){
			if(i > 0) os<<obj.terms[i]<<"x^"<<i<<" + ";
			else os<<obj.terms[i]<<"x";
	//	}
	}
	return os;
}

istream& operator>>(istream& is, Poly& obj){
	int coff, temp, pow;
	for(int j=0;j<MAX;j++) {
		is>>coff>>temp>>pow;
		obj.terms[pow] = coff;
	}
	return is;
}

void Poly:: Reset(){
	for(int i=0;i<MAX;i++){
		terms[i] = 0;
	}
}

double Poly:: Eval(double x){
	double temp = 1;
	for(int i=0;i<x;i++) temp *= x;
	return temp;
}

Poly operator+(const Poly& p1, const Poly& p2){
	Poly result;
	for(int i=0;i<MAX;i++){
		result.terms[i] = p1.terms[i] + p2.terms[i];
	}
	return result;
}

Poly operator*(const Poly& p1, const Poly& p2){
	Poly result;
	for(int i=0;i<MAX;i++){
		result.terms[i] = p1.terms[i] * p2.terms[i];
	}
	return result;
}

void Poly:: operator+=(const Poly& p){
	for(int i=0;i<MAX;i++){
		terms[i] += p.terms[i];
	}
}

void Poly:: Derivative(){
	for(int i=0;i<MAX;i++){
		if (i == 0)this->terms[0] *= 1;
		else this->terms[0] *= i;
	}
}
