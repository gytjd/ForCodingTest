#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A,B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        A.push_back(data);
    }
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        B.push_back(data);
    }
    sort(A.begin(),A.end(),greater<>());
    sort(B.begin(),B.end());
    
    int answer=0;
    for(int i=0;i<N;i++) {
        answer+=(A[i]*B[i]);
    }
    
    cout << answer << "\n";
    
    return 0;
}
