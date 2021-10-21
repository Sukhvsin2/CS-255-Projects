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
