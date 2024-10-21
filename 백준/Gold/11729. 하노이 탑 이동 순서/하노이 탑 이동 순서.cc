#include <iostream>
#include <vector>

using namespace std;

int N;
int curr_Cnt=0;
vector<pair<int,int>> v;

void hanoi_(int curr,int start,int mid,int end) {
    
    curr_Cnt+=1;
    if(curr==1) {
        v.push_back({start,mid});
        return;
    }
    
    hanoi_(curr-1, start, end,  mid);
    v.push_back({start,mid});
    hanoi_(curr-1,end, mid, start);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    hanoi_(N, 1, 3, 2);
    
    cout << curr_Cnt << "\n";
    for(pair<int,int> temp:v) {
        cout << temp.first << " " << temp.second << "\n";
    }
    
    return 0;
}
