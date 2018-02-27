#include <iostream>
#include <sys/time.h>
#include <cstdlib>
#include <string>

using std::cout;
using std::endl;
using std::cin;


int FibIter(int n){
    int a = 0;
    int b = 1;
    int c;

    if (n == 0){
        return 0;
    }

    for(int i=1; i <= n; ++i){

		if(i >  1){  
			c = a+b;
			a  =b;
			b  = c;
		}
    }
     return b;
 }


int FibRec(int n){

    if(n <= 1){
        return n;
    }else{
    return FibRec(n-1)+ FibRec(n-2);
    }

}

int FibRecs(int n) {
	
	if (n <= 1) {
		return n;
	}
	else {
		return FibRec(n - 1) + FibRec(n - 2);
	}

}


 int main(){

	typedef struct timeval time;
	time stop, start;
	cout << "bRec" << endl;
	int input;
	//cin >> input;
	gettimeofday(&start, NULL);
	//cout << FibRec(input) << endl;
	gettimeofday(&stop, NULL);
	if (stop.tv_sec > start.tv_sec)
		cout << "Seconds: " << stop.tv_sec - start.tv_sec << endl;
	else
		cout << "Micro: " << stop.tv_usec - start.tv_usec << endl;

	cin >> input;
	cout << "Number of steps " << input << " is " << FibRecs(input+1) << endl;
	
	/*
	while (true){
		cin >> input;
		for (int i = 0; i < input; i++)	{
			cout << "F" << i << " is " << FibRec(input) << endl;
		}
	}
	
	*/
	return 0;
	
}
