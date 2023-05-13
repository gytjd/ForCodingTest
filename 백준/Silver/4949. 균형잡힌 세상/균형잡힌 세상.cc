#include <iostream>
#include <stack>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(1) {
        stack<char> temp;
        string a;
        getline(cin, a);
        bool stack_Flag=false;
        if(a==".") break;
        for(char q:a) {
            if(q=='(' or q=='[') temp.push(q);
            else if(q==')' or q==']'){
                if(temp.size()==0 or (temp.top()=='(' and q==']')or(temp.top()=='[' and q==')')) {
                    stack_Flag=true;
                    break;
                }
                else temp.pop();
            }
        }
        if(temp.size()!=0 or stack_Flag==true) cout << "no" << "\n";
        else cout << "yes" << "\n";
    }
    return 0;
}
