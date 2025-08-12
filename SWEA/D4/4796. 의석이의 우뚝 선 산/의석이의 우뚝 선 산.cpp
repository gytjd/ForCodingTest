#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T,N;
int ret;
vector<int> v;
int visitedLeft[50004];
int visitedRight[50004];

void init_() {
    memset(visitedLeft, 0, sizeof(visitedLeft));
    memset(visitedRight,0,sizeof(visitedRight));
    
    visitedLeft[0]=1;
    visitedRight[N-1]=1;
    
    for(int i=1;i<N;i++) {
        if(v[i]>v[i-1]) {
            visitedLeft[i]=visitedLeft[i-1]+1;
        } else {
            visitedLeft[i]=1;
        }
    }
    
    for(int i=N-2;i>=0;i--) {
        
        if(v[i]>v[i+1]) {
            visitedRight[i]=visitedRight[i+1]+1;
        } else {
            visitedRight[i]=1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test=1;test<=T;test++) {
        
        ret=0;
        v.clear();
        
        cin >> N;
        for(int i=0;i<N;i++) {
            int data;
            cin >> data;
            v.push_back(data);
        }
        
        init_();
        
        for(int i=1;i<N-1;i++) {
            if(v[i-1]<v[i] and v[i+1]<v[i]) {
                ret+=(visitedLeft[i-1]*visitedRight[i+1]);
            }
        }
        cout << "#" << test << " " << ret << "\n";
    }
    
    return 0;
}
