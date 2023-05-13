#include <iostream>
using namespace std;

int find_Num(int a) {
    int tempA,tempB,tempC;
    
    tempA=a/100;
    tempB=a%100/10;
    tempC=a%100%10;
    
    if((tempB-tempA) == (tempC-tempB)) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {
    int i;
    int n;
    cin >> n;
    
    if(n<100) {
        cout << n << "\n";
    }
    else if(n>=100 && n<111) {
        cout << 99 << "\n";
    }
    else {
        int count=0;
        
        for(i=111;i<=n;i++) {
            if(find_Num(i)==1) {
                count+=1;
            }
        }
        
        cout << count+99 << "\n";
    }
    
    return 0;
    
    
}
