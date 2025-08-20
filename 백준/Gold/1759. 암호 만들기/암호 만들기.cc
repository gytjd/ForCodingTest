#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L,C;
vector<char> v;
int visited[20];

bool is_check(string data) {
    
    int evenCnt=0;
    int oddCnt=0;
    for(int i=0;i<data.size();i++) {
        if(data[i]=='a' or data[i]=='e' or data[i]=='i' or data[i]=='o' or data[i]=='u') {
            evenCnt+=1;
        } else {
            oddCnt+=1;
        }
    }
    
    if(evenCnt>=1 and oddCnt>=2) return true;
    return false;
}

void DFS_recur(int curr,int idx,string temp) {
    
    if(curr==L) {
        if(is_check(temp)) {
            cout << temp << "\n";
        }
        return;
    }
    
    for(int i=idx;i<C;i++) {
        DFS_recur(curr+1, i+1, temp+v[i]);
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> L >> C;
    for(int i=0;i<C;i++) {
        char data;
        cin >> data;
        v.push_back(data);
    }
    sort(v.begin(),v.end());
    
    DFS_recur(0, 0, "");
    
    return 0;
}
