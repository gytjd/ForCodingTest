#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[104];
struct Node {
    int x,y,z;
};

vector<Node> v;

bool cmp(Node &A,Node &B) {
    return A.z<B.z;
}

int find_Parent(int start) {
    if(parent[start]==start) {
        return start;
    }
    return parent[start]=find_Parent(parent[start]);
}

void union_Parent(int startA,int startB) {
    startA=find_Parent(startA);
    startB=find_Parent(startB);
    if(startA!=startB) {
        parent[startB]=startA;
    }
}

int Kruskal(int n) {
    
    int curr_Cnt=0;
    int ret=0;
    for(int i=0;i<v.size();i++) {
        int first=v[i].x;
        int second=v[i].y;
        int edge=v[i].z;
        
        if(find_Parent(first)!=find_Parent(second)) {
            union_Parent(first,second);
            ret+=edge;
            curr_Cnt+=1;
            
            if(curr_Cnt==n-1) {
                break;
            }
        }
    }
    return ret;
}

int solution(int n, vector<vector<int>> costs) {
    
    for(int i=0;i<costs.size();i++) {
        v.push_back({costs[i][0],costs[i][1],costs[i][2]});
    }
    sort(v.begin(),v.end(),cmp);
    
    for(int i=1;i<=n;i++) {
        parent[i]=i;
    }
    
    return Kruskal(n);
}