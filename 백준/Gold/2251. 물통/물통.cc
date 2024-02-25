#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int A,B,C;
int visited[204][204][204];
vector<int> answer;
struct Bottle {
    int x,y,z;
};

void BFS_iter(int x,int y,int z) {
    queue<Bottle> q;
    q.push({x,y,z});
    
    while(!q.empty()) {
        x=q.front().x;
        y=q.front().y;
        z=q.front().z;
        q.pop();
        
        if(visited[x][y][z]==0) {
            visited[x][y][z]=1;
            
            if(x==0) {
                answer.push_back(z);
            }
            
            if(x+y<B) q.push({0,x+y,z});
            else q.push({x+y-B,B,z});
            
            if(x+z<C) q.push({0,y,x+z});
            else q.push({x+z-C,y,C});
            
            if(y+x<A) q.push({y+x,0,z});
            else q.push({A,y+x-A,z});
            
            if(y+z<C) q.push({x,0,y+z});
            else q.push({x,y+z-C,C});
            
            if(z+x<A) q.push({z+x,y,0});
            else q.push({A,y,z+x-A});
            
            if(z+y<B) q.push({x,z+y,0});
            else q.push({x,B,z+y-B});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> A >> B >> C;
    
    BFS_iter(0, 0, C);
    sort(answer.begin(),answer.end());
    
    for(int i=0;i<answer.size();i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
