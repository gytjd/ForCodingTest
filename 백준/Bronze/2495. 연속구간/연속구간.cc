#include <iostream>
using namespace std;

int main() {
    int i,j;
    for(i=0;i<3;i++) {
        string temp;
        cin >> temp;
        
        int result=1;
        int total_result=1;
        
        for(j=1;j<temp.size();j++) {
            if(temp[j]==temp[j-1]) {
                result+=1;
                
                if(total_result<result) {
                    total_result=result;
                }
            }
            else {
                result=1;
            }
        }
        
        cout << total_result << "\n";
        
    }
    
    return 0;
}
