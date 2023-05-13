#include <iostream>
using namespace std;

int N,M;

int is_prime(int a) {
    
    if(a==1) {
        return 0;
    }
    
    for(int i=2;i<a;i++) {
        if(a%i==0) {
            return 0;
        }
    }
    
    return 1;
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    cin >> M;
    
    int tot=0;
    int min_tmp=N;
    bool check_Flag=false;
    
    for(int i=N;i<=M;i++) {
        if(is_prime(i)==1) {
            tot+=i;
            
            if(check_Flag==false) {
                min_tmp=i;
                check_Flag=true;
            }
        }
    }
    
    if(tot==0) {
        cout << -1 << "\n";
    }
    else {
        cout << tot << "\n";
        cout << min_tmp << "\n";
    }
    
    return 0;
}
