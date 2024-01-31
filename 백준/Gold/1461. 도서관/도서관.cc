#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N,M;
vector<int> neg;
vector<int> pos;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        if(data<0) {
            neg.push_back(data);
        }
        else {
            pos.push_back(data);
        }
    }
    sort(neg.begin(),neg.end());
    sort(pos.begin(),pos.end());
    
    int answer=0;
    long long pos_Tsize=pos.size();
    long long neg_Tsize=neg.size();
    
    for(int i=M;i<neg_Tsize;i+=M) {
        answer+=(abs(neg[i])*2);
    }
    for(int i=pos_Tsize-1-M;i>=0;i-=M) {
        answer+=(pos[i]*2);
    }
    
    if(pos_Tsize==0 and neg_Tsize!=0) {
        answer+=abs(neg[0]);
    }
    else if(pos_Tsize!=0 and neg_Tsize==0) {
        answer+=pos[pos_Tsize-1];
    }
    else {
        if(abs(neg[0])<pos[pos_Tsize-1]) {
            answer+=abs(neg[0])*2;
            answer+=pos[pos_Tsize-1];
        }
        else {
            answer+=pos[pos_Tsize-1]*2;
            answer+=abs(neg[0]);
        }
    }
    cout << answer << "\n";

    
    return 0;
}
