#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
long long ret;
vector<long long> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    v.push_back(0);
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    for(int i=1;i<=N;i++) {
        v[i]+=v[i-1];
    }
    
    int low=0;
    int high=1;
    
    while(low<=high and high<=N) {
//        cout << low << " " << high << "\n";
        if(v[high]-v[low]<=M) {
            ret=max(ret,v[high]-v[low]);
            high+=1;
        } else {
            low+=1;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
