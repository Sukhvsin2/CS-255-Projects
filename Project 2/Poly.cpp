#include "Poly.h"

Poly:: Poly(){
	for(int i=0;i<MAX;i++) terms[i] = 0;
}

ostream& operator<<(ostream &os,const Poly &obj){
	for(int i=0;i<MAX;i++) {
		os<<obj.terms[i]<<" ";	
	}
	return os;
}

istream& operator>>(istream &is,Poly &obj){
	for(int i=0;i<MAX;i++) is>>obj.terms[i];
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
	
}