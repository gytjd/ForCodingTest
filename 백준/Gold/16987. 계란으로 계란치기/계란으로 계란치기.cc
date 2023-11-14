#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ret;
int N;
int visited[10]; // 0 은 안꺠짐 1은깨짐
vector<pair<int, int>> v; // first 는 내구도 second 는 무게

void Egg_Recur(int curr,int cnt) {
    
    if(curr==N) {
        return;
    }
    
    
    for(int i=0;i<N;i++) {
        
        int temp_Cnt=0;
        if(curr==i or visited[i]==1) {
            continue;
        }
        
        if(visited[curr]==1) {
            Egg_Recur(curr+1, cnt);
        }
        else {
            v[curr].first-=v[i].second;
            v[i].first-=v[curr].second;
            
            if(v[curr].first<=0) {
                visited[curr]=1;
                temp_Cnt+=1;
            }
            if(v[i].first<=0) {
                visited[i]=1;
                temp_Cnt+=1;
            }
            
            ret=max(ret,cnt+temp_Cnt);
            Egg_Recur(curr+1, cnt+temp_Cnt);
            
            v[curr].first+=v[i].second;
            v[i].first+=v[curr].second;
            
            if(v[curr].first>0) {
                visited[curr]=0;
                temp_Cnt-=1;
            }
            if(v[i].first>0) {
                visited[i]=0;
                temp_Cnt-=1;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int def,weight;
        cin >> def >> weight;
        v.push_back({def,weight});
    }
    
    Egg_Recur(0, 0);
    
    cout << ret << "\n";
    
    return 0;
}
