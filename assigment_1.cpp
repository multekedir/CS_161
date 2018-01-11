/*********************************************************
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


int main(){
	const double PI = 3.14159265;
	
	//calling cos form cmath
	double result = cos(2/3);	
	cout << "cos(2/3) = " << result << endl;
	
	//calling sin from cmath
	result = 2*sin(2/3);
	cout << "2sin(2/3) = " << result << endl;

	//calling log10 from cmath
	result = log10 (55);
	cout << "log 10 (55) = " << result << endl;
}	

