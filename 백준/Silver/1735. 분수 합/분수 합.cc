#include <iostream>
using namespace std;

int startA,startB,endA,endB;


int gcd(int a,int b) {
    int c;
    
    while(b!=0) {
        c=a%b;
        a=b;
        b=c;
    }
    
    return a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> startA >> startB;
    cin >> endA >> endB;
    
    int a,b;
    b=startB*endB;
    a=startB*endA+endB*startA;
    
    int temp=gcd(a, b);
    cout << a/temp << " " << b/temp << "\n";
    
    return 0;
}
