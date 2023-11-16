#include <iostream>
#include <algorithm>
using namespace std;

int ret=987654321;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string A,B;
    cin >> A >> B;
    
    for(int i=0;i<=B.size()-A.size();i++) {
        
        int temp_Cnt=0;
        for(int j=0;j<A.size();j++) {
            if(A[j]!=B[i+j]) {
                temp_Cnt+=1;
            }
        }
        ret=min(ret,temp_Cnt);
    }
    
    cout << ret << "\n";
    return 0;
}
