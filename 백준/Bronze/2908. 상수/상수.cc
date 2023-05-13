#include <iostream>
#include <string>

using namespace std;

void max_num(string a,string b) {
    int tempA=stoi(a);
    int tempB=stoi(b);
    
    if(tempA>tempB) {
        cout << tempA << "\n";
    }
    else if (tempA<tempB) {
        cout << tempB << "\n";
    }
    else {
        cout << "?" << "\n";
    }
}

int main() {
    string a,b;
    cin >> a >> b;
    
    char temp;
    temp=a[2];
    a[2]=a[0];
    a[0]=temp;
    
    temp=b[2];
    b[2]=b[0];
    b[0]=temp;
    
    max_num(a,b);
    
    return 0;
}
