#include <iostream>
#include <stack>
using namespace std;

int ret;
int N,M;
stack<int> s[7];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        int A,B;
        cin >> A >> B;
        
        if(s[A].empty()) {
            s[A].push(B);
            ret+=1;
        }
        else {
            if(s[A].top()<B) {
                s[A].push(B);
                ret+=1;
            }
            else {
                if(s[A].top()!=B) {
                    while(!s[A].empty() and s[A].top()>B) {
                        ret+=1;
                        s[A].pop();
                    }
                    
                    if(s[A].empty() or s[A].top()!=B) {
                        s[A].push(B);
                        ret+=1;
                    }
                }
            }
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
