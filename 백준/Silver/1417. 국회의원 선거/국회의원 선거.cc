#include <iostream>
#include <vector>
using namespace std;

int ret;
int N;
vector<int> v;

pair<int, int> is_max() {
    
    int max_Ret=0;
    int max_Idx=0;
    for(int i=1;i<N;i++) {
        if(max_Ret<v[i]) {
            max_Ret=v[i];
            max_Idx=i;
        }
    }
    return {max_Ret,max_Idx};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    while(1) {
        pair<int, int> temp=is_max();
        if(v[0]<=temp.first) {
            v[0]+=1;
            v[temp.second]-=1;
            ret+=1;
        }
        else {
            break;
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
