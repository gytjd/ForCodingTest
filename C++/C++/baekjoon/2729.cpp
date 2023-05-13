#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
int min_N=1,max_N=-987654321,data_N,temp,mid;
int ret;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        cin >> data_N;
        max_N=max(data_N,max_N);
        v.push_back(data_N);
    }
    
    while(min_N<=max_N) {
        
        mid=(min_N+max_N)/2;
        temp=0;
        
        for(int a:v) {
            if(a%mid)
                temp+=(a/mid)+1;
            else
                temp+=(a/mid);
        }
        
        if(temp<=N) {
            ret=mid;
            max_N=mid-1;
        }
        else {
            min_N=mid+1;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}

