#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

bool cmp(int a,int b) {
    return a>b;
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
    
    sort(v.begin(), v.end(), cmp);
    
    int temp=0;
    for(int j=0;j<N;j++) {
        temp+=v[j];
    }
    
    if(temp%2==0) {
        cout << temp << "\n";
    }
    else {
        for(int i=N-1;i>=0;i--) {
            if(v[i]%2) {
                temp-=v[i];
                break;
            }
        }
        cout << temp << "\n";
    }
    
    
    return 0;
}

