#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T;
int N;
int first,second;
vector<int> v1,v2;
int parent[10004];

void find_init(vector<int> &v,int start) {
    
    v.push_back(start);
    while(start!=0) {
        v.push_back(parent[start]);
        start=parent[start];
    }
}

void find_Parent() {
//    for(int i=0;i<v1.size();i++) {
//        cout << v1[i] << " ";
//    }
//    cout << "\n";
//    
//    for(int i=0;i<v2.size();i++) {
//        cout << v2[i] << " ";
//    }
//    cout << "\n";
    
    int answer=0;
    int v1_Size=v1.size()-1;
    int v2_Size=v2.size()-1;
    while(v1_Size!=-1 and v2_Size!=-1) {
        if(v1[v1_Size]==v2[v2_Size]) {
            answer=v1[v1_Size];
        }
        v1_Size--;
        v2_Size--;
    }
    
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test=0;test<T;test++) {
        cin >> N;
        v1.clear();
        v2.clear();
        memset(parent,0,sizeof(parent));
        
        for(int i=0;i<N-1;i++) {
            int start,end;
            cin >> start >> end;
            parent[end]=start;
        }
        cin >> first >> second;
        find_init(v1,first);
        find_init(v2,second);
        find_Parent();
    }
    
    return 0;
}
