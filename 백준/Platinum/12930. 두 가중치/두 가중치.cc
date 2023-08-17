#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9+7
using namespace std;

struct Node {
    long long weight,w1,w2,curr;
};

struct cmp {
    bool operator()(Node &a,Node &b) {
        return a.weight>b.weight;
    }
};

long long N;
pair<long long, long long> arr[24][24];
long long distA[24];
long long distB[24];

long long Dijkstra(long long curr) {
    
    long long weight;
    long long w1;
    long long w2;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({0,0,0,curr});
    distA[curr]=0;
    distB[curr]=0;
    
    while(!q.empty()) {
        weight=q.top().weight;
        w1=q.top().w1;
        w2=q.top().w2;
        curr=q.top().curr;
        q.pop();
        
        if(curr==1) {
            return weight;
        }
        
        if(w1>distA[curr] and w2>distB[curr]) {
            continue;
        }
        
        
        for(long long i=0;i<N;i++) {
            if(i!=curr and (arr[curr][i].first!=0 and arr[curr][i].second!=0)) {
                if(w1+arr[curr][i].first<distA[i] or w2+arr[curr][i].second<distB[i]) {
                    distA[i]=min(distA[i],w1+arr[curr][i].first);
                    distB[i]=min(distB[i],w2+arr[curr][i].second);
                    q.push({(w1+arr[curr][i].first)*(w2+arr[curr][i].second),w1+arr[curr][i].first,w2+arr[curr][i].second,i});
                }
            }
        }
        
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(long long i=0;i<N;i++) {
        distA[i]=INF;
        distB[i]=INF;
    }
    
    for(long long i=0;i<N;i++) {
        string a;
        cin >> a;
        for(long long j=0;j<N;j++) {
            if(a[j]!='.') {
                arr[i][j].first=a[j]-'0';
            }
        }
    }
    for(long long i=0;i<N;i++) {
        string a;
        cin >> a;
        for(long long j=0;j<N;j++) {
            if(a[j]!='.') {
                arr[i][j].second=a[j]-'0';
            }
        }
    }
    
    cout << Dijkstra(0) << "\n";
    
    return 0;
}
