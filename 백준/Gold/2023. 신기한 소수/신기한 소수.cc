#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;

bool is_Prime(int num) {
    if(num<2) {
        return false;
    }
    
    for(int i=2;i*2<=num;i++) {
        if(num%i==0) {
            return false;
        }
    }
    return true;
}

void Prime_Recur(int curr,int temp) {
    
//    cout << curr << " " << temp << "\n";
    
    if(curr==N) {
        cout << temp << "\n";
        return;
    }

    for(int i=0;i<10;i++) {
        int temp_Ret=temp*10+i;
        
        if(is_Prime(temp_Ret)) {
            Prime_Recur(curr+1, temp_Ret);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    Prime_Recur(0, 0);
    
    return 0;
}
