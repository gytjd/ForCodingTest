
#include <iostream>
#include <cmath>
using namespace std;


long long A,B,C;

long long div_num(long long a,long long b) {
    
    if(b==1) {
        return a%C;
    }
    
    long long ret=div_num(a, b/2);
    ret=(ret*ret)%C;
    
    if(b%2) {
        ret=(ret*a)%C;
    }
    
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> A >> B >> C;

    cout << div_num(A, B) << "\n";
    
    return 0;
}
