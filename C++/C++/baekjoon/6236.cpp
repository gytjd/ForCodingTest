#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int low=-987654321,high,mid,temp,d,count_T;
int ret;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        cin >> d;
        low=max(low,d);
        v.push_back(d);
        high+=d;
    }
    
    while(low<=high) {
        mid=(low+high)/2;
        
//        cout << mid << "\n";
        temp=0;
        count_T=1;
        
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

