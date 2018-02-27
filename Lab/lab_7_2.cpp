#include<iostream>
#include<string>


using namespace std;


string  *fun1() {
    string *out = new string;
	return out;
}

void fun2(string **input) {
    *input = new string("Hey fun2");

}

void fun3(string* &input) {
  input  = new string();
}


int main(int argc, char *argv[]) {
    string* n = fun1();
    delete n;
    fun2(&n);
    delete n;
    fun3(n);
    delete n;
}
