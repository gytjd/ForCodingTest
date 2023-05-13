#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if(n==1) {
        cout << n << "\n";
    }
    else {
        int temp=1;
        int temp_n=1;
        int count=0;
        
        while(temp<n) {
            
            count+=1;
            temp+=(6*temp_n);
            temp_n+=1;
            
        }
        cout << count+1 <<"\n";
    }
    
    
    return 0;
}
