#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=1;i<=N;i++) {
        temp.push_back(i);
    }
    
    for(int i=0;i<M;i++) {
        vector<int> arr;
        int start,end,mid;
        
        cin >> start >> end >> mid;
        
        for(int j=0;j<start-1;j++) {
            arr.push_back(temp[j]);
        }
        
        for(int j=mid-1;j<end;j++) {
        
            arr.push_back(temp[j]);
        }
        
        
        for(int j=start-1;j<mid-1;j++) {
            
            arr.push_back(temp[j]);
        }
        
        
        for(int j=end;j<N;j++) {
        
            arr.push_back(temp[j]);
        }
        
        temp.clear();
        temp=arr;
    }
    
    for(int i:temp) {
        cout << i << " ";
    }
    cout << "\n";
    
    return 0;
}
