#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<int> v[1004];
int in_degree[1004];
queue<int> q;
vector<int> answer;

//void display_() {
//    for(int i=1;i<=N;i++) {
//        cout << i << " : ";
//        for(int j=0;j<v[i].size();j++) {
//            cout << v[i][j] << " ";
//        }
//        cout << "\n";
//    }
//}

void topo_S() {
    
    int start;
    for(int i=1;i<=N;i++) {
        if(in_degree[i]==0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        start=q.front();
        q.pop();
        answer.push_back(start);
        
        for(int i=0;i<v[start].size();i++) {
            in_degree[v[start][i]]-=1;
            if(in_degree[v[start][i]]==0) {
                q.push(v[start][i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<M;i++) {
        int tempN;
        cin >> tempN;
        vector<int> tempV;
        for(int j=0;j<tempN;j++) {
            int data;
            cin >> data;
            tempV.push_back(data);
        }
    
        if(tempN>1) {
            for(int j=0;j<tempN-1;j++) {
                v[tempV[j]].push_back(tempV[j+1]);
                in_degree[tempV[j+1]]+=1;
            }
        }
    }
//    display_();
    
    topo_S();
    
    if(answer.size()==N) {
        for(int i=0;i<N;i++) {
            cout << answer[i] << "\n";
        }
    }
    else {
        cout << 0 << "\n";
    }
    
    return 0;
}
