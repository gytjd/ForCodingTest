#include <iostream>
#include <algorithm>

using namespace std;

string N;
int visited[10];
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N.size();i++) {
        visited[N[i]-'0']+=1;
    }
    
    if(visited[6]+visited[9]%2) {
        visited[6]=(visited[6]+visited[9])/2+(visited[6]+visited[9])%2;
    }
    else {
        visited[6]=(visited[6]+visited[9])/2;
    }
    visited[9]=visited[6];
    

    for(int i=0;i<10;i++) {
        answer=max(answer,visited[i]);
    }
    cout << answer << "\n";
    
    return 0;
}
