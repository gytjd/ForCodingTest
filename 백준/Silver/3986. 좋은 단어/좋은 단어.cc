#include <iostream>
#include <stack>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    int count=0;
    
    for(int i=0;i<N;i++) {
        
        stack<char> st;
        string a;
        cin >> a;
        
        bool A_Flag=false;
        bool B_Flag=false;
        
        bool R_Flag=false;
        
        for(char q:a) {
            
            if(q=='A') {
                
                if(st.size()==0) {
                    st.push(q);
                }
                else {
                    if(st.top()=='A') {
                        st.pop();
                    }
                    else {
                        st.push(q);
                    }
                }
            }
            else {
                if(st.size()==0) {
                    st.push(q);
                }
                else {
                    if(st.top()=='B') {
                        st.pop();
                    }
                    else {
                        st.push(q);
                    }
                }
            }
        }
        
        
        if(st.size()==0) {
            count+=1;
        }
    }
    cout << count << "\n";
    
    return 0;
}
