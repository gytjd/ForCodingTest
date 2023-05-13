#include <iostream>
#include <string>

using namespace std;

int main() {
    int i,j;
    int n;
    cin >> n;
    
    for(i=0;i<n;i++) {
        
        int count=1;
        int result=0;
        string a;
        cin >> a;
        
        for(j=0;j<a.size();j++) {
            
            if(a[j]=='O') {
                result+=count;
                count++;
            }
            else {
                count=1;
            }
        }
        cout << result << "\n";
    }
    
    return 0;
}
