#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;
string a;
stack<int> s;
int visited[200004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    cin >> a;
    
    
    for(int i=0;i<a.size();i++) {
        
        if(a[i]=='(') {
            s.push(i);
        }
        else if(a[i]==')') {
            
            if(s.size()==0) {
                continue;
            }
            
            int temp=s.top();
            
            if(a[temp]=='(') {
                visited[temp]=1;
                visited[i]=1;
                s.pop();
            }
        }
    }
    
    int max_N=-987654321;
    int ret_Cnt=0;
    for(int i=0;i<a.size();i++) {

        if(visited[i]==1) {
            ret_Cnt+=1;
        }
        else {
            if(max_N<ret_Cnt) {
                max_N=ret_Cnt;
            }
            ret_Cnt=0;
        }
    }

    
    if(max_N<ret_Cnt) {
        max_N=ret_Cnt;
    }
    
    if(max_N==-987654321) {
        cout << 0 << "\n";
    }
    else {
        cout << max_N << "\n";
    }
        

    return 0;
}
