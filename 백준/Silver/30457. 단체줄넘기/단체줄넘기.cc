#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
int visited[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        visited[data]+=1;
    }
    
    int ret=0;
    for(int i=1;i<=1004;i++) {
        if(visited[i]) {
            ret+=min(visited[i],2);
        }
    }
    cout << ret << "\n";
    
    return 0;
}
