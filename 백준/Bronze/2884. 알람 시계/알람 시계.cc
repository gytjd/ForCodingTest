#include <iostream>

using namespace std;

void min_alarm(int hour,int min) {
    int sec=0;
    sec+=hour*3600;
    sec+=min*60;
    
    sec-=45*60;
    
    int tempA=sec/3600;
    int tempB=sec%3600/60;
    
    if(tempB<0) {
        cout << 23 << " " << 60+tempB << " ";
        cout << endl;
    }
    else {
        cout << tempA << " " << tempB << " ";
        cout << endl;
    }
}

int main() {
    int hour,min;
    
    cin >> hour >> min;
    
    min_alarm(hour,min);
    
    return 0;
}
