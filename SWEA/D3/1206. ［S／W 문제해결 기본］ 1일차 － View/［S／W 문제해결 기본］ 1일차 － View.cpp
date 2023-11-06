#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ret;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int t=0;t<10;t++) {
        cin >> N;
        
        ret=0;
        v.clear();
        
        for(int i=0;i<N;i++) {
            int data;
            cin >> data;
            v.push_back(data);
        }
        
        for(int i=2;i<=N-2;i++) {
            if(v[i]>=v[i-2] and v[i]>=v[i-1] and v[i]>=v[i+1] and v[i]>=v[i+2]) {
                int temp=v[i-2];
                temp=max(temp,v[i-1]);
                temp=max(temp,v[i+1]);
                temp=max(temp,v[i+2]);
                ret+=v[i]-temp;
            }
        }
        
        cout << "#" << t+1 << " " << ret << "\n";
    }
    return 0;
}
