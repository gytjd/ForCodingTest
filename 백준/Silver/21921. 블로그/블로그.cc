#include <iostream>
#include <algorithm>

using namespace std;

int X,N;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> X >> N;
    v.push_back(0);
    for(int i=0;i<X;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    for(int i=0;i<=X;i++) {
        v[i]+=v[i-1];
//        cout << v[i] << "\n";
    }
    
    int ret=0;
    for(int i=0;i<=X-N;i++) {
        ret=max(ret,v[i+N]-v[i]);
    }
    
//    cout << ret << "\n";
    
    if(ret) {
        int ret_Cnt=0;
        
        for(int i=0;i<=X-N;i++) {
            if(v[i+N]-v[i]==ret) {
                ret_Cnt+=1;
            }
        }
        
        cout << ret << "\n";
        cout << ret_Cnt << "\n";
        
    } else {
        cout << "SAD" << "\n";
    }
    return 0;
}
