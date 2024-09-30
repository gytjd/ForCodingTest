#include <iostream>
#include <vector>

using namespace std;

int N;
int temp;

int main() {
	
	cin >> N;
	for(int i=0;i<N;i++) {
		int data;
		cin >> data;
		temp+=data;
	}
	
	int temp_Cnt=1;
	int ret=0;
	
	while(temp!=0) {
		ret+=(temp%8)*temp_Cnt;
		temp/=8;
		temp_Cnt*=10;
	}
	
	cout << ret << "\n";
	
	return 0;
}