#include <iostream>
#include <map>
using namespace std;

int ret;
int N;
int cnt[4];
map<int, int> m;

void Recur_Roma(int start,int count) {
    if(count==N) {
        int temp=cnt[0]*1+cnt[1]*5+cnt[2]*10+cnt[3]*50;
        if(m[temp]==0) {
            m[temp]+=1;
            ret+=1;
        }
        return;
    }
    
    for(int i=start;i<4;i++) {
        cnt[i]+=1;
        Recur_Roma(i,count+1);
        cnt[i]-=1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    Recur_Roma(0,0);
    
    cout << ret << "\n";
    return 0;
}
