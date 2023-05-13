#include <iostream>

using namespace std;

int main() {
    
    int i;
    int M,N;
    cin >> M >> N;
    
    int left=1;
    int right=N;
    
    int J;
    cin >> J;
    
    int result=0;
    
    for(i=0;i<J;i++) {
        
        int temp;
        cin >> temp;
        
        if(temp>=left and temp<=right) {
            continue;
        }
        else if(temp>right) {
            result+=(temp-right);
            left=temp-N+1;
            right=temp;
        }
        else {
            result+=(left-temp);
            left=temp;
            right=temp+N-1;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
