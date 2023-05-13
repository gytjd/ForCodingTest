#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> arr;

void find_Num() {
    int start=0;
    int end=arr.size()-1;
    int cnt_N=0;
    
    while(start<end) {
        
        if(arr[start]+arr[end]>M) {
            end-=1;
        }
        else if(arr[start]+arr[end]<M) {
            start+=1;
        }
        else {
            cnt_N+=1;
            start+=1;
            end-=1;
        }
    }
    
    cout << cnt_N << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        arr.push_back(data);
    }
    cin >> M;
    
    sort(arr.begin(), arr.end());
    
    find_Num();
    
    return 0;
}
