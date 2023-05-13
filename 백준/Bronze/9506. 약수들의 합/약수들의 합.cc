#include <iostream>
#include <vector>
using namespace std;


void is_(int a) {
    
    int result=0;
    vector<int> tmp;
    
    for(int i=1;i<a;i++) {
        if(a%i==0) {
            tmp.push_back(i);
            result+=i;
        }
    }

    
    if(result==a) {
        cout << a << " = ";
        for(int i=0;i<tmp.size();i++) {
            if(i==tmp.size()-1) {
                cout << tmp[i];
            }
            else {
                cout << tmp[i] << " + ";
            }
        }
        cout << "\n";
    }
    else {
        cout << a << " is NOT perfect." << "\n";
    }
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(1) {
        int a;
        cin >> a;
        
        if(a==-1) {
            break;
        }
        
        is_(a);
    }
    
    return 0;
}
