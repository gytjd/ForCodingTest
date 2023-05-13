#include <iostream>

using namespace std;

void three_six_nine(int n) {
    int a,b,c;
    int count=0;
    int temp[3];
    
    temp[0]=n/100;
    temp[1]=n%100/10;
    temp[2]=n%100%10;
    
    for(int i=0;i<3;i++) {
        if(temp[i]==3 or temp[i]==6 or temp[i]==9) {
            count+=1;
        }
    }
    
    if(count==0) {
        cout << n << " ";
    }
    else {
        for(int i=0;i<count;i++) {
            cout << "-";
        }
        cout << " ";
    }
    
    
}
int main() {
    int n;
    int i;
    
    cin >> n;
    
    for(i=1;i<=n;i++) {
        three_six_nine(i);
    }
    cout << "\n";
}
