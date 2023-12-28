
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max_health;
int visited[1004];

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    
    max_health=health;
    int curr_cnt=0;
    int size_vec=attacks.size();
    
    for(vector<int> temp:attacks) {
        visited[temp[0]]=temp[1];
    }
    
    for(int i=1;i<=attacks[size_vec-1][0];i++) {
        
        // cout << health << " " << curr_cnt << "\n";
        if(visited[i]==0) { // 붕대...높임,,
            curr_cnt+=1;
            
            if(curr_cnt==bandage[0]) {
                health+=bandage[2];
                health+=bandage[1];
                curr_cnt=0;
            }
            else {
                health+=bandage[1];
            }
            if(health>max_health) {
                health=max_health;
            }
        }
        else { // 공격
            health-=visited[i];
            curr_cnt=0;
            if(health<=0) {
                return -1;
            }
        }
    }
    return health;
}