#include <iostream>
#include <string>
#include <cmath>

using namespace std;


string getInput(string promt) {
	string input = "";
	bool flag = false;
	do {
		cout << promt;
		getline(cin, input);
		flag = false;
		int count = 0;
		for (int i = 0; i<input.length(); i++) {
			if (input[i] < '0' || input[i] > '9') {
				if (input[i] == '.') {
					count++;
					if (count > 1) {
						flag = true;
					}
				}
				else {
					flag = true;
				}
			}
		}
	} while (flag);
	return input;
}

float offer(string input) {
	int i =0;
    float decimal, res,  val;
	for (i = 0; i < input.length(); i++) {
		if (input[i] == '.')
			break;
	}
	res = 0;
	val = 0;
	for (int j = i - 1; j >= 0; j--) {
		val = ((int)input[j]) - 48;
		res += val * pow(10, (i - 1 - j));
	}
	decimal = 0;
	int count = 1;
	for (int k = i + 1; k < input.length(); k++) {
		val = ((int)input[k]) - 48;
		decimal += val * pow(10, (-count));
		count++;
	}

	return (res + decimal);
}



int main() {
	float current_offer = 0, future_offer = 0, ir = 0, m = 1, n = 0, res, val, decimal;
	int i, count;	
	string input ="";

	current_offer = offer(getInput("Please provide the current offer amount: "));		

	future_offer = offer(getInput("Please provide the current offer amount: "));

	
	ir = offer(getInput("Please provide the interest rate: "));


	
	cout << "Please provide the amount of time in years between the current offer and future offer: ";
	cin >> n;

	input = getInput("Please provide the amount of time in years between the current offer and future offer: ");


	for (int i = (input.length() - 1); i >= 0; i--) {
		val = ((int)input[i]) - 48;
		res += val * pow(10, (input.length() - i - 1));
	}
	n = res;

	float val_current_offer = current_offer * (pow((1 + (ir / m)), (n*m)));
	float val_future_offer = future_offer / (pow((1 + (ir / m)), (n*m)));

	if (val_current_offer > val_future_offer) {
		cout << "Take the current offer" << endl;
	}
	else if (val_current_offer < val_future_offer) {
		cout << "Take the future offer" << endl;
	}
	else {
		cout << "Choose which ever" << endl;
	}


	return 0;
}
