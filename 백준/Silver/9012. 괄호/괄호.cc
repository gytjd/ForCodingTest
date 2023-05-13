#include <iostream>
#include <stack>
using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;

    
    for(int i=0;i<N;i++) {
        
        bool stack_Flag=false;
        stack<char> temp;
        string a;
        cin >> a;
        
        for(char q:a) {
            
            if(q=='(') {
                temp.push(q);
            }
            else if(q==')') {
                
                if(temp.size()==0) {
                    stack_Flag=true;
                    break;
                }
                temp.pop();
            }
        }
        
        
        if(temp.size()!=0 or stack_Flag==true) {
            cout << "NO"<< "\n";
        }
        else {
            cout << "YES"<< "\n";
        }
    }
    
    return 0;
}

