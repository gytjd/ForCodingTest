#include <iostream>
using namespace std;

int p[10000]={0};

void find_selfNum(int a) {
    
    int temp=a;
    
    if(a<10) {
        temp+=a;
    }
    else if(a<100) {
        int tempA;
        int tempB;
        
        tempA=temp/10;
        tempB=temp%10;
        temp+=tempA+tempB;
    }
    else if(a<1000) {
        int tempA;
        int tempB;
        int tempC;
        
        tempA=temp/100;
        tempB=temp%100/10;
        tempC=temp%100%10;
        
        temp+=tempA+tempB+tempC;
    }
    else {
        int tempA;
        int tempB;
        int tempC;
        int tempD;
        
        tempA=temp/1000;
        tempB=temp%1000/100;
        tempC=temp%1000%100/10;
        tempD=temp%1000%100%10;
        
        temp+=tempA+tempB+tempC+tempD;
    }
    
    p[temp]=1;
    if(temp<10000) {
        find_selfNum(temp);
    }
}
int main() {
    
    
    int i;
    
    for(i=1;i<10000;i++) {
        if(p[i]==1) {
            continue;
        }
        find_selfNum(i);
    }
    
    for(i=1;i<10000;i++){
        if(p[i]==0) {
            cout << i << "\n";
        }
    }
    
    return 0;
}
