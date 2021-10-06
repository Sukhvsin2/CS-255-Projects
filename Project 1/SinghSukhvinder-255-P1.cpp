/**
	Name: Sukhvinder Singh
	Purpose: Fraction Calculator which can perform various operations just like a Normal Calculator but for fractions.
		At the program start it'll give you all the options which you can perform on any fraction after selecting.
		System will give you option to choose fraction randomly or could input at runtime, after that you could 
		enter value or get result according to whatever operation you choose. 
	Date: 10/5/21
	
**/

#include<iostream>
// For random number rand()
#include<cstdlib>
// For Including fraction class and methods
#include"Fraction.h"

using namespace std;

/**
	Name: Options
	Return: None
	Outgoing: None
	Incoming: None
	Purpose: Printing/Displaying Options of the calculator
**/
void options();
/**
	Name: Operations
	Return Value: None
	Incoming Parameters: O for option that user chooses, f1 as in first fraction object which 
		is passed by reference to use the memory efficiently, f2 as in second fraction object which
		is passed by reference to use the memory efficiently.
	Outgoing Parameters: f1 & f2 because whatever operation 
		performed on those objects it going to affect the real objects in the main body as they are passed by reference.
	Purpose: This function is used to perform actions/operations choose by the user and call function from the Fraction 
		Class which is imported at the top of the file.
**/
void operations(int, Fraction&, Fraction&);
/**
	Name: RandFraction
	Return: None
	Income Parameters: Object of Fraction by reference, which going to be generated and 
		set the value of Numerator and Denominator. And it would does affect that object 
		in main body also because of passing it by reference. 
	Outgoing Parameters: Setting new Num & Den for an object generated randomly.
	Purpose: By this function system is creating a random fraction to perform 
		operations on it, which would be only called if user chooses Yes or y 
		to generate a fraction randomly or it will not call
**/
void randFraction(Fraction&);

/**
	Name: FractionCalculator
	Return: None
	Incoming: loop controller named ex, sel for selcting options and random variable, objects as f1,f2, 
		o for choosing options in the list
	Outgoing: Just changing in those passed by reference variables acc. to conditions.
	Purpose: It controls the flow of calcultor by choosing options and making decisons which function to 
		call at what time.
**/

void fractionCalculator(char&, char&, Fraction&, Fraction&, int&);
/**
	Name: ProgramEnd
	Return: None
	Incoming: None
	Outgoing: None
	Purpose: Just display 3 types of messages choosed according to the random number at runtime.
**/
void programEnd();

int main(){
	// Object initialized
	Fraction f1, f2;
	int o;
	char sel, ex;
	// Calculator function called
	fractionCalculator(ex, sel, f1, f2, o);
	// Program end function called at end
	programEnd();
	
	return 0;
}


void options(){
	cout<<"***** Fraction Calculator *****"<<endl;
	cout<<"Operations: "<<endl;
	cout<<"0. Exit"<<endl;
	cout<<"1. +"<<endl;
	cout<<"2. -"<<endl;
	cout<<"3. *"<<endl;
	cout<<"4. /"<<endl;
	cout<<"5. isExact: =="<<endl;
	cout<<"6. =="<<endl;
	cout<<"7. >"<<endl;
	cout<<"8. <"<<endl;
	cout<<"9. <="<<endl;
	cout<<"10. >="<<endl;
	cout<<"11. !="<<endl;
	cout<<"12. ++"<<endl;
	cout<<"13. --"<<endl;
}


void operations(int o, Fraction &f1, Fraction &f2){
	Fraction temp;
	switch(o){
		case 0: 
			break;
		case 1:
			temp = f1+f2;
			temp.reduce();
			cout<<"case +: "<<f1+f2;
			break;
		case 2:
			temp = f1-f2;
			temp.reduce();
			cout<<"case -: "<<f1-f2;
			break;
			
		case 3:
			temp = f1*f2;
			temp.reduce();
			cout<<"case *: "<<f1*f2;
			break;
			
		case 4:
			temp = f1/f2;
			temp.reduce();
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
			temp = f1;
			temp.reduce();
			cout<<"Case ++: "<<f1;
			break;
			
		case 13:
			f1--;
			temp = f1;
			temp.reduce();
			cout<<"Case --: "<<f1;
			break;
			
		default:
			cout<<o<<endl;
			cout<<"Error: Choose atleast one operation : +, -, *, /...!";
			break;
	}
	!temp.GetNum() ? "" : cout<<"\nReduced Fraction: "<<temp<<endl;
}


void randFraction(Fraction &f1){
	f1.SetNum(rand() % 100 + 1);
	f1.SetDen(rand() % 100 + 1);
}


void fractionCalculator(char &ex, char &sel, Fraction &f1, Fraction &f2, int &o){
	
	options();
	bool counter = true;
	while(counter){
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
		if(ex == 'N' || ex == 'n') counter = false;
		else counter = true;
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

