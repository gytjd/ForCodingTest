#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long N;
deque<pair<long long,long long>> q;
deque<pair<long long,long long>> temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(long long i=0;i<N;i++) {
        long long data;
        cin >> data;
        q.push_back({i,data});
    }
    
    while(true) {
        
        if(q.size()==1) {
            cout << q.front().second << "\n";
            cout << q.front().first+1 << "\n";
            break;
        }
        
        while(!q.empty()) {
            long long idx,Num;
            long long tempNum;
            idx=q.front().first;
            Num=q.front().second;
            tempNum=Num;
            q.pop_front();
            
            if(!temp.empty() and temp.back().second<=Num) {
                tempNum+=temp.back().second;
                temp.pop_back();
            }
            
            if(!q.empty() and q.front().second<=Num) {
                tempNum+=q.front().second;
                q.pop_front();
            }
            temp.push_back({idx,tempNum});
        }
        
        q=temp;
        temp.clear();
    }

    
    return 0;
}
