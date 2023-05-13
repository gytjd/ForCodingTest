#include<iostream>
#include<string>
using namespace std;

int main() {

	string inputs;
	cin >> inputs;  //48 --> '0' (ASCII)
	int size = inputs.length()/2; //half
	int leftsum = 0;
	int rightsum = 0;
	for (int i = 0; i < size; i++) {
		leftsum += inputs[i] - 48;
		rightsum += inputs[i + size] - 48;
	}
	if (leftsum == rightsum) cout << "LUCKY";
	else cout<<"READY";

	return 0;
}