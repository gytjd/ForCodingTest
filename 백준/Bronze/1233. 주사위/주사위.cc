#include <iostream>
#include <unordered_map>
using namespace std;

int a,b,c;
unordered_map<int, int> q;
int max_N=-987654321;
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    
    cin >> a >> b >> c;
    
    for(int i=1;i<=a;i++) {
        for(int j=1;j<=b;j++) {
            for(int k=1;k<=c;k++) {
                q[i+j+k]+=1;
            }
        }
    }
    
    for(int i=3;i<=a+b+c;i++) {
        
        if(q[i]>max_N) {
            max_N=q[i];
            ret=i;
        }
    }
    
    cout << ret << "\n";
    
    return 0;

}
