#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
int low=-987654321,high,temp,mid;
int count_T,ret;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        cin >> temp;
        low=max(temp,low);
        high+=temp;
        v.push_back(temp);
    }
    while(low<=high) {
        mid=(low+high)/2;
        count_T=1;
        temp=0;
        
        for(int a:v) {
            temp+=a;
            if(temp>mid) {
                count_T+=1;
                temp=a;
            }
        }
        
        if(count_T<=M) {
            ret=mid;
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
