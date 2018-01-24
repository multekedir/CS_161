#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib> /*include to allow rand() and srand() to be used*/

using namespace std;

int getRandom(int start, int end){

	int x;
	x = start + rand() %(end - start +1);
	return x;
}
string  getUppercase(int num){
	string out = "";
	for (int i=0; i < num; i++){
		char letter = getRandom(65,90);
		out += letter;
	}
	return out;
}
string  getLowercase(int num){
	string out = "";
	for (int i=0; i < num; i++){
		char letter = getRandom(97,122);
		out += letter;
	}
	return out;
}

string  getNumbers(int num){
	string out = "";
	for (int i=0; i < num; i++){
		char letter = getRandom(48,57);
		out += letter;
	}
	return out;
}

int main(){
	int length,upper,lower,num;
	string all = "";
	srand(time(NULL));
	cout << getRandom(100,200) << endl;
	cout << "Welcome to Password Creator" << endl;
	
	cout << "How long do you want the password to be >> " ;
	cin >> length;
	cout << "How many uppercase >> " ;
	cin >> upper;
	cout << "How many lowercase >> " ;
	cin >> lower;
	cout << "How many numbers >> ";
	cin >> num;
	
	if(length == (lower+upper+num)){
		
		all += getUppercase(upper);
		all += getLowercase(lower);
		all +=  getNumbers(num);
	}

	cout << all << endl;
return 0;
}
