#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long N,K;
vector<pair<long long, long long>> v;
vector<long long> c;

priority_queue<long long,vector<long long>,less<>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    
    for(long long i=0;i<N;i++) {
        long long start,end;
        cin >> start >> end;
        v.push_back({start,end});
    }
    
    for(long long j=0;j<K;j++) {
        long long data;
        cin >> data;
        c.push_back(data);
    }
    
    sort(v.begin(), v.end());
    sort(c.begin(),c.end());
    
    long long temp=0;
    long long ret=0;
    for(long long i=0;i<K;i++) {
        
        while(temp<N and v[temp].first<=c[i]) {
            q.push(v[temp].second);
            temp+=1;
        }
        
        if(q.size()) {
            ret+=q.top();
            q.pop();
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
