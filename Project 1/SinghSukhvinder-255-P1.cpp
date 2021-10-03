#include<iostream>
#include<cstdlib>
#include"Fraction.h"

using namespace std;

void options(){
	cout<<"Options: "<<endl;
	cout<<"0. Exit"<<endl;
	cout<<"1. +"<<endl;
	cout<<"2. -"<<endl;
	cout<<"3. *"<<endl;
	cout<<"4. /"<<endl;
	cout<<"5. isExact: =="<<endl;
	cout<<"6. =="<<endl;
	cout<<"7. <"<<endl;
	cout<<"8. >"<<endl;
	cout<<"9. <="<<endl;
	cout<<"10. >="<<endl;
	cout<<"11. !="<<endl;
	cout<<"12. ++"<<endl;
	cout<<"13. --"<<endl;
}

void operations(int o, Fraction &f1, Fraction &f2){
	switch(o){
		case 0: 
			break;
		case 1:
			cout<<"case +: "<<f1+f2;
			break;

		case 2:
			cout<<"case -: "<<f1-f2;
			break;
			
		case 3:
			cout<<"case *: "<<f1*f2;
			break;
			
		case 4:
			cout<<"case /: "<<f1/f2;
			break;
		
		case 5:
			cout<<"Case isExact: "<<(isExact(f1,f2) == 1 ? "True" : "False");
			break;
		
		case 6:
			cout<<"Case ==: "<<((f1==f2) == 1 ? "True" : "False");
			break;
		
		case 7:
			cout<<"Case >: "<<((f1>f2) == 1 ? "True" : "False");
			break;
			
		case 8:
			cout<<"Case <: "<<((f1<f2) == 1 ? "True" : "False");
			break;
			
		case 9:
			cout<<"Case <=: "<<((f1<=f2) == 1 ? "True" : "False");
			break;
		
		case 10:
			cout<<"Case >=: "<<((f1>=f2) == 1 ? "True" : "False");
			break;
			
		case 11:
			cout<<"Case !=: "<<((f1!=f2) == 1 ? "True" : "False");
			break;
			
		case 12:
			f1++;
			cout<<"Case ++: "<<f1;
			break;
			
		case 13:
			f1--;
			cout<<"Case --: "<<f1;
			break;
			
		default:
			cout<<o<<endl;
			cout<<"Error: Choose atleast one operation : +, -, *, /...!";
			break;
	}
}

void randFraction(Fraction &f1){
	f1.SetNum(rand() % 100 + 1);
	f1.SetDen(rand() % 100 + 1);
}

void fractionCalculator(int &ex, char &sel, Fraction &f1, Fraction &f2, int &o){
	cout<<"***** Fraction Calculator *****"<<endl;
	options();
	
	while(ex){
		cout<<"You wanna select a random fraction? Y or N: ";
		cin>>sel;
		if(sel == 'y' || sel == 'Y'){
			randFraction(f1);
			cout<<"Random Fraction: "<<f1.GetNum()<<"/"<<f1.GetDen()<<endl;
		}else{
			cout<<"Enter your First Fraction: ";
			cin>>f1;
		}
		cout<<"Choose Option: ";
		cin>>o;
		if(o != 12 && o != 13 && o != 0){
			cout<<"Enter your Second Fraction: ";
			cin>>f2;
		}
		operations(o, f1, f2);
		cout<<endl<<"Want to calculate more?: Y/y or N/n: ";
		cin>>ex;
		if(ex == 'N' || ex == 'n') ex = 0;
	}
}

void programEnd(){
	switch(rand()%3 + 1){
		case 1:		
			cout<<endl<<"Learning is Fun!!!"<<endl;
			break;
		case 2:
			cout<<endl<<"Thank you!"<<endl;
			break;
		case 3:
			cout<<endl<<"Have a Great Day!"<<endl;
	}
}

int main(){
	Fraction f1, f2;
	int o, ex=1;
	char sel;
	fractionCalculator(ex, sel, f1, f2, o);
	programEnd();
}
