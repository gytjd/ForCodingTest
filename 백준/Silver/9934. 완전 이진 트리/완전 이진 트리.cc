#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int arr[1028];
int K;
vector<int> tree[11];

void BFS_recur(int start,int end,int depth) {
    
    int mid=(start+end)/2;
    
    if(start==end) {
        tree[depth].push_back(arr[mid]);
        return;
    }
    
    BFS_recur(start, mid-1,depth+1);
    tree[depth].push_back(arr[mid]);
    BFS_recur(mid+1, end,depth+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> K;
    
    int sizeK=pow(2, K)-1;
    
    for(int i=1;i<=sizeK;i++) {
        cin >> arr[i];
    }
    
    BFS_recur(1,sizeK,1);
    
    for(int i=1;i<=K;i++) {
        for(int j:tree[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
    
    
    
    return 0;
}
