#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> v;
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    int left=1;
    int right=-987654321;
    
    for(int i=0;i<M;i++) {
        int data;
        cin >> data;
        right=max(right,data);
        v.push_back(data);
    }
    
    while(left<=right) {
        
        int temp=0;
        int mid=(left+right)/2;
//        cout << mid << "\n";
        
        for(int t:v) {
            temp+=t/mid;
        }
//        cout << "\n";
//        cout << temp << "\n";
//        cout << "\n";
        
        if(temp<N) {
            right=mid-1;
        }
        else {
            ret=mid;
            left=mid+1;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
