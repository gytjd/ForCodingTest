#include <iostream>
#include <unordered_map>

using namespace std;

int N,M;
unordered_map<string, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        string a,temp;
        cin >> a;
        temp="";
        for(int i=0;i<a.size();i++) {
            temp+=a[i];
            m[temp]=1;
        }
    }
    
    int ret=0;
    for(int i=0;i<M;i++) {
        string a;
        cin >> a;
        if(m[a]) {
            ret+=1;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
