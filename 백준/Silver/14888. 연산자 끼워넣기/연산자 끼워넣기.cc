#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> op;
vector<int> nums;

int visited[14];
int max_N=-987654321;
int min_N=987654321;

void comb_(int depth,int ret) {

    
    if(depth==N-1) {
        if(max_N<ret) {
            max_N=ret;
        }
        
        if(min_N>ret) {
            min_N=ret;
        }
        return;
    }
    
    for(int i=0;i<N-1;i++) {
        
        if(visited[i]==0) {
            visited[i]=1;
            if(op[i]==0) {
                comb_(depth+1,ret+nums[depth+1]);
            }
            else if(op[i]==1) {
                comb_(depth+1,ret-nums[depth+1]);
            }
            else if(op[i]==2) {
                comb_(depth+1,ret*nums[depth+1]);
            }
            else {
                comb_(depth+1,ret/nums[depth+1]);
            }
            visited[i]=0;
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        nums.push_back(data);
    }
    
    for(int i=0;i<4;i++) {
        int temp;
        cin >> temp;
        
        for(int j=0;j<temp;j++) {
            op.push_back(i);
        }
    }
    
    comb_(0,nums[0]);
    
    cout << max_N << "\n";
    cout << min_N << "\n";
    
    return 0;
}
