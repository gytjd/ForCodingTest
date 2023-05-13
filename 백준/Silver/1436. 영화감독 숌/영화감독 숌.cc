#include <iostream>
using namespace std;

int is_right(int temp) {
    string a=to_string(temp);
    
    int count=0;
    
    for(char q:a) {
        
        if(q=='6') {
            count+=1;
            
            if(count==3) {
                return 1;
            }
        }
        else {
            count=0;
        }
    }
    
    return 0;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    int temp=666;
    int count=0;
    while(1) {
        
        if(is_right(temp)) {
            count+=1;
        }
        
        if(count==N) {
            cout << temp << "\n";
            break;
        }
        
        temp+=1;
    }
    
    return 0;
}
