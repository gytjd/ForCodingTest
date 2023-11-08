#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N,M;
vector<long long> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(long long i=0;i<N;i++) {
        long long data;
        cin >> data;
        v.push_back(data);
    }
    
    for(long long i=0;i<M;i++) {
        sort(v.begin(), v.end());
        
        long long temp=v[0]+v[1];
        v[0]=temp;
        v[1]=temp;
    }
    
    long long ret=0;
    for(long long i=0;i<N;i++) {
        ret+=v[i];
    }
    
    cout << ret << "\n";
    
    return 0;
}
