#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 1000000
using namespace std;

struct Node {
    long long A,B,C;
};

long long N,K,D;
vector<Node> v;

long long cal_(long long num) {
    
    long long temp=0;
    for(long long i=0;i<K;i++) {
        if(v[i].A>num) {
            continue;
        }
        temp+=(min(v[i].B,num)-v[i].A)/v[i].C+1;
    }
    return temp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K >> D;
    
    for(long long i=0;i<K;i++) {
        long long A,B,C;
        cin >> A >> B >> C;
        v.push_back({A,B,C});
    }
    
    long long ret=0;
    long long low=1;
    long long high=MAX_SIZE;
    
    while(low<=high) {
        long long mid=(low+high)/2;
        if(cal_(mid)<D) {
            low=mid+1;
        }
        else {
            high=mid-1;
            ret=mid;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
