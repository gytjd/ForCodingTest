#include <iostream>
#include <string>

using namespace std;

int main() {
    string temp;
    cin >> temp;
    
    int result=0;
    
    for(char a:temp) {
        if(a=='A' or a=='B' or a=='C') {
            result+=3;
        }
        else if(a=='D' or a=='E' or a=='F') {
            result+=4;
        }
        else if(a=='G' or a=='H' or a=='I') {
            result+=5;
        }
        else if(a=='J' or a=='K' or a=='L') {
            result+=6;
        }
        else if(a=='M' or a=='N' or a=='O') {
            result+=7;
        }
        else if(a=='P' or a=='Q' or a=='R' or a=='S') {
            result+=8;
        }
        else if(a=='T' or a=='U' or a=='V') {
            result+=9;
        }
        else if(a=='W' or a=='X' or a=='Y' or a=='Z') {
            result+=10;
        }
        else {
            result+=3;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
