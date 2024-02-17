#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer;
int N,M;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    sort(v.begin(),v.end());
    
    int low=0;
    int high=N-1;
    
    while(low<high) {
        for(int i=low+1;i<high;i++) {
            
            if(v[low]==M or v[i]==M or v[high]==M) {
                answer=1;
            }
            if(v[low]+v[i]==M or v[low]+v[high]==M or v[i]+v[high]==M) {
                answer=1;
            }
            if(v[low]+v[i]+v[high]==M) {
                answer=1;
            }
        }
        
        if(v[low]+v[high]<M) {
            low+=1;
        }
        else {
            high-=1;
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
