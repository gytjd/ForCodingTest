#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int dp[100004][5][5];

vector<int> v;
int N;

int check_(int prev,int curr) {
    if(prev==0)
        return 2;
    else if(prev==curr)
        return 1;
    else if(prev==1 or prev==3) {
        if(curr==2 or curr==4)
            return 3;
        else
            return 4;
    }
    else if(prev==2 or prev==4) {
        if(curr==1 or curr==3)
            return 3;
        else
            return 4;
    }
    
    return -1;
}

int go_(int left,int right,int depth) {
    
    if(depth==N+1) {
        return 0;
    }
    
    int &ret=dp[depth][left][right];
    if(ret!=INF) {
        return ret;
    }
    
    if(right!=v[depth]) {
        ret=min(ret,go_(v[depth], right, depth+1)+check_(left, v[depth]));
    }
    
    if(left!=v[depth]) {
        ret=min(ret,go_(left, v[depth], depth+1)+check_(right,v[depth]));
    }
    
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i=0;i<100004;i++) {
        for(int j=0;j<5;j++) {
            for(int k=0;k<5;k++) {
                dp[i][j][k]=INF;
            }
        }
    }
    
    v.push_back(0);
    
    while(1) {
        int data;
        cin >> data;
        
        if(data==0) {
            break;
        }
        
        v.push_back(data);
        N+=1;
    }
    cout << go_(0,0,1) << "\n";
    
    return 0;
}
