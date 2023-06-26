#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;

int find_Mid(int start,int end) {
    
    for(int i=start+1;i<=end;i++) {
        if(v[start]<v[i]) {
            return i;
        }
    }
    return end+1;
}

void go_(int start,int end) {
    
//    cout << start << " " << end << "\n";
    
    
    if(start==end and start<N) {
        cout << v[start] << "\n";
        return;
    }
    
    if(start<end) {
        int mid=find_Mid(start, end);
        go_(start+1, mid-1);
        go_(mid,end);
        cout << v[start] << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int temp;
    while(cin >> temp) {
        v.push_back(temp);
        N+=1;
        
    }
    
    go_(0, N-1);
    
}
