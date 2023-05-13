#include <iostream>

using namespace std;

int N;

bool is_Prime(long long temp) {
    
    long long i;
    
    for(i=2;i*i<=temp;i++) {
        if(temp%i==0) {
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
    for(long long i=0;i<N;i++) {
        long long data;
        cin >> data;
        
        if(data==0 or data==1) {
            cout << 2 << "\n";
            continue;
        }
        
        if(is_Prime(data)) {
            cout << data << "\n";
        }
        else {
            while(1) {
                data+=1;
                if(is_Prime(data)) {
                    cout << data << "\n";
                    break;
                }
            }
        }
        
    }
    
    return 0;
}
