
/********************************************************
 **  Program Filename: assigment_1
 **  Author: Multezem Kedir 
 **  Date:   Wednesday Jan 10, 2018 22:55:59 PST
 **  Description: Calling function from cmath library
 **  Input: cmath library
 **  Output: Text
 ******************************************************** */

#include<iostream>
#include<cmath>

using namespace std;


int logbase(int, int);

int main(){
	

	cout <<endl << endl << "Assigment 1" << endl << endl;	
	//calling cos form cmath
	cout << "**********************************************************" << endl;
	float result = cos((float)2/3);	
	cout << "cos(2/3) = " << result << endl << endl;
	
	//calling sin from cmath
	cout << "**********************************************************" << endl;
	result = 2*(sin((float)2/3));
	cout << "2sin(2/3) = " << result << endl << endl;

	//calling log10 from cmath
	cout << "**********************************************************" << endl;
	result = log10 (55);
	cout << "log base 10 of (55) = " << result << endl << endl;

	cout << "**********************************************************" << endl;
	logbase(15, 2);
	cout << "**********************************************************" << endl;
	logbase(40, 4);

	cout << "**********************************************************" << endl;
	cout << "Calculating for 3^sin(x) " << endl;
       	cout << "\t x=1   \t  3^sin(x)=" << pow(3, sin((float)1)) << endl;
	cout << "\t x=10  \t  3^sin(x)=" << pow(3, sin((float)10)) << endl;
	cout << "\t x=100 \t  3^sin(x)=" << pow(3, sin((float)100)) << endl << endl;

	cout << "**********************************************************" << endl;
	cout << "Calculating for log base 2 of (x^2 +1) " << endl;
	cout << "**********************************************************" << endl;
	cout << "\t x=1   \t  3^sin(x)=" << logbase(pow(1,2)+ 1, 2) << endl;
	cout << "**********************************************************" << endl;
	cout << "\t x=10  \t  3^sin(x)=" << logbase(pow(10,2)+ 1, 2) << endl;
	cout << "**********************************************************" << endl;
	cout << "\t x=100 \t  3^sin(x)=" << logbase(pow(100,2)+ 1, 2) << endl;
	cout << "**********************************************************" << endl;


}

int logbase(int x, int b){

	/********************************************************************* 
	 * ** Function: logbase 
	 * ** Description: caculates the log of a difrent base using ln(x)/ln(base)
	 * ** Parameters:  term, base
	 * ** Pre-Conditions: None
	 * ** Post-Conditions: None
	 *********************************************************************/


	cout << "Calculating log base: " << b <<" term: " << x << " using formula ln(term)/ln(base)"<< endl;
	float term = log(x);
      	cout << "\t ln(x) = "<< term << endl;
	float base = log(b);
	cout << "\t ln(b) = " << base << endl;
	float result = term/base;
	cout << "\t ln(x)/ln(b) =  " << result << endl;	
	
	return result;
}


