#include <iostream>
#include <string>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int result[101]={0,};
    int A,B,C;
    cin >> A >> B >> C;
    
    for(int i=0;i<3;i++) {
        int tempA,tempB;
        cin >> tempA >> tempB;
        
        for(int j=tempA;j<tempB;j++) {
            result[j]+=1;
        }
    }
    
    int total=0;
    
    for(int i=0;i<101;i++) {
        
        if(result[i]==1) {
            total+=(A*result[i]);
        }
        else if(result[i]==2) {
            total+=(B*result[i]);
        }
        else if(result[i]==3) {
            total+=(C*result[i]);
        }
    }
    
    cout << total <<"\n";
    
    
    return 0;
}

