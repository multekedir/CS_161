#include <iostream>

#include <string>


using namespace std;

char  a_to_i(int letter){

    return letter;
}

int  i_to_a(char num){
    if(num >= '0' && num <= '9'){
        return (num-48);
}
    return 0;

}

int main(){
    int  m;
    cin >> m;
      cout <<  a_to_i(m) << endl;
}
