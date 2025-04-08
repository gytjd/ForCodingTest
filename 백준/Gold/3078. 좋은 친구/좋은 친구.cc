#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long N,K;
long long visited[24];
vector<long long> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    for(long long i=0;i<N;i++) {
        string data;
        cin >> data;
        v.push_back(data.size());
    }
    for(long long i=0;i<K;i++) {
        v.push_back(0);
    }
    
    long long ret=0;
    for(long long i=0;i<N+K;i++) {
        visited[v[i]]+=1;
        if(i>=K) {
            ret+=visited[v[i-K]]-1;
            visited[v[i-K]]-=1;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
