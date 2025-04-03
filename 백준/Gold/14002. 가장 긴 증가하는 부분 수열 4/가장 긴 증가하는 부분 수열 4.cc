#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ret=1,retIdx=1;

vector<int> v;
vector<int> temp;
int visited[1004];
int dir[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    v.push_back(0);
    for(int i=1;i<=N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    for(int i=1;i<=N;i++) {
        visited[i]=1;
        for(int j=1;j<i;j++) {
            if(v[j]<v[i]) {
                
                if(visited[i]<visited[j]+1) {
                    visited[i]=visited[j]+1;
                    dir[i]=j;
                }
                
                if(visited[i]>ret) {
                    ret=visited[i];
                    retIdx=i;
                }
            }
        }
    }
    
    
    while(dir[retIdx]!=0) {
        temp.push_back(v[retIdx]);
        retIdx=dir[retIdx];
    }
    temp.push_back(v[retIdx]);
    
    reverse(temp.begin(), temp.end());
    
    cout << ret << "\n";
    for(int data:temp) {
        cout << data << " ";
    }
    cout << "\n";
    
    return 0;
}
