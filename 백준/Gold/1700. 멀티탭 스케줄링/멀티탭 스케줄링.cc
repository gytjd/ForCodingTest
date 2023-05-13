#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int visited[104];
vector<int> v;
vector<int> temp;

struct cmp {
    bool operator()(const pair<int, int> a,const pair<int, int> b) {
        return a.second<b.second;
    }
};

priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    
    for(int i=0;i<M;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    
    int cnt_T=0;
    
    for(int i=0;i<M;i++) {
        if(visited[v[i]]==0) {
            if(temp.size()<N) {
                visited[v[i]]=1;
                temp.push_back(v[i]);
            }
            else {
                
                for(int j=0;j<temp.size();j++) {
                    
                    int k;
                    bool check_Flag=false;
                    
                    for(k=i+1;k<M;k++) {
                        if(temp[j]==v[k]) {
                            check_Flag=true;
                            break;
                        }
                    }
                
                    if(check_Flag) {
                        q.push(make_pair(temp[j], k));
                    }
                    else {
                        q.push(make_pair(temp[j], 104));
                    }
                }
                
//                cout << q.top().first << " " << q.top().second << "\n";
                
                visited[q.top().first]=0;
                q.pop();
                
                visited[v[i]]=1;
                q.push(make_pair(v[i], 0));
                
                temp.clear();
                while(!q.empty()) {
                    temp.push_back(q.top().first);
                    q.pop();
                }
                
                cnt_T+=1;
            }
        }
        else {
            continue;
        }
    }
    
    cout << cnt_T << "\n";
    
    return 0;
}
