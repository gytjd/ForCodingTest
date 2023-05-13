#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

vector<pair<int, int>> result_T;

int N,M;
int visited[13];

int total;

int calculate_chicken() {
    
    int result=0;
    
    for(int i=0;i<house.size();i++) {
        int temp_result=0;
        for(int j=0;j<result_T.size();j++) {
            
            int dir=abs(result_T[j].first-house[i].first)+abs(result_T[j].second-house[i].second);
            
            if(temp_result==0) {
                temp_result=dir;
            }
            else {
                if(temp_result>dir) {
                    temp_result=dir;
                }
            }
            
        }
        
        result+=temp_result;
    }
    
    return result;
}

void DFS_iter(int start,int count) {

    if(result_T.size()==M) {
        
        if(total==0) {
            total=calculate_chicken();
        }
        else {
            int temp_ret=calculate_chicken();
            if(total>temp_ret) {
                total=temp_ret;
            }
        }
        return;
    }
    
    for(int i=start;i<chicken.size();i++) {
        if(visited[i]==0) {
            visited[i]=1;
            result_T.push_back(chicken[i]);
            
            DFS_iter(i+1, count+1);
            
            visited[i]=0;
            result_T.pop_back();
        }
    }
    
    
    
    
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            
            int idx;
            cin >> idx;
            if(idx==1) {
                house.push_back(make_pair(i, j));
            }
            
            if(idx==2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    
    DFS_iter(0, 0);
    
    cout << total << "\n";
    
    return 0;
}
