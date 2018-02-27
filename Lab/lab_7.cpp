#include<iostream>
#include<string>
#include <stdlib.h>

using namespace std;

void get_string(string *);
void set_replace_string(string, string *);
int get_search_replace(char, string, string &);


bool is_letter(char letter) {

	return ((('a' <= letter) && (letter <= 'z')) || (('A' <= letter) && (letter <= 'Z')));
}

int main() {
	string input, copy;
	char letter;
	int count, total;
	get_string(&input);
	set_replace_string(input, &copy);
	do {
		system("clear");
		cout << copy << endl;
		cout << "Guess a Letter >> ";
		cin >> letter;
		count = get_search_replace(letter, input, copy);
		total += count;
		cout << "Found " << count << " " << letter << "\t";
	} while (total < input.length());
	system("clear");
	cout << input << endl;
	cout << "You Won" << endl;
	return 0;
}

void get_string(string * data){
	cout << "Enter a String >> " ;
	getline(cin, *data); //user input
}

void set_replace_string(string input, string * copy){

	string new_string = "";
	for (int i = 0; i < input.length(); i++){
		if (is_letter(input[i]))
			new_string += '_';
		else
			new_string += input[i];
	}
	*copy = new_string;

}

int get_search_replace(char letter, string input, string & copy){
	int count = 0;
	string new_string = "";
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == letter) {
			count++;
			new_string += letter;
		}else if (is_letter(copy[i])) {
			new_string += input[i];
		}else {
			new_string += '_';
		}

	}
	copy = new_string;
	return count;

}
