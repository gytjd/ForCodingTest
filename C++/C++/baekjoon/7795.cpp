#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T,N,M,temp;
int low,high,mid;
int ret;

vector<int> q;
vector<int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    
    for(int i=0;i<T;i++) {
        
        q.clear();
        p.clear();
        
        cin >> N >> M;
        
        for(int j=0;j<N;j++) {
            cin >> temp;
            q.push_back(temp);
        }
        
        for(int j=0;j<M;j++) {
            cin >> temp;
            p.push_back(temp);
        }
        
        sort(q.begin(), q.end());
        sort(p.begin(), p.end());
        ret=0;
        
        for(int a:q) {
            
            low=0;
            high=M-1;
                
            while(low<=high) {
                mid=(low+high)/2;
                
                if(p[mid]<a) {
                    low=mid+1;
                }
                else {
                    high=mid-1;
                }
            }
            ret+=low;
        }
        
        cout << ret << "\n";
    }
    
    
}

