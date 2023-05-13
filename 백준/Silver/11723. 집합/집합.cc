#include <iostream>
using namespace std;

int tot=0;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        string a;
        int temp;
        cin >> a;
        
        
        if(a=="add") {
            cin >> temp;
            if((tot&(1<<temp))==0) {
                tot|=(1<<temp);
            }
        }
        else if(a=="check") {
            cin >> temp;
            if(((tot&(1<<temp))>>temp)==1) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        else if(a=="remove") {
            cin >> temp;
            if((tot&(1<<temp))!=0) {
                tot^=(1<<temp);
            }
        }
        else if(a=="toggle") {
            cin >> temp;
            if(((tot&(1<<temp))>>temp)==1) {
                tot&=~(1<<temp);
            }
            else {
                tot|=(1<<temp);
            }
        }
        else if(a=="all") {
            tot=2097151;
        }
        else if(a=="empty") {
            tot=0;
        }
    }
    
    return 0;
}
