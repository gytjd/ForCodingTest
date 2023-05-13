#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,ret,maxPos,temp;
int arr[1004];
int dp[1004];
int dir[1004];

vector<int> tot;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    ret=dp[0];
    dir[0]=0;
    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            if(arr[i]>arr[j]) {
                dp[i]=max(dp[j]+1,dp[i]);
                
                if(dp[i]==dp[j]+1) {
                    dir[i]=j;
                }
                ret=max(dp[i],ret);
                
                if(ret==dp[i]) {
                    maxPos=i;
                }
            }
        }
    }
    
    cout << ret+1 << "\n";
    
    if(maxPos==0) {
        cout << arr[maxPos] << "\n";
    }
    else {
        while(maxPos!=0) {
            temp=arr[maxPos];
            tot.push_back(temp);
            maxPos=dir[maxPos];
        }
        
        if(arr[maxPos]<temp) {
            tot.push_back(arr[maxPos]);
        }

        reverse(tot.begin(), tot.end());
        
        for(int a:tot) {
            cout << a << " ";
        }
        cout << "\n";
    }
    

    return 0;
}
