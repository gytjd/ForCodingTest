#include <iostream>

using namespace std;

void oven_alarm(int a,int b,int c) {
    int sec=0;
    sec+=a*3600;
    sec+=b*60;
    sec+=c*60;
    
    int tempA=sec/3600;
    if(tempA>23) {
        tempA-=24;
    }
    
    int tempB=sec%3600/60;
    
    cout << tempA << " " << tempB << " ";
    cout << endl;
    
}

int main() {
    int a,b;
    cin >> a >> b;
    
    if(a>23 or b>59) {
        exit(1);
    }
    
    int c;
    cin >> c;
    
    oven_alarm(a, b, c);
    
    return 0;
}
