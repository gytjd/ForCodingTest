#include <iostream>
using namespace std;

int N,M;
int temp[104];

void SWAP(int &pa,int &pb) {
    int temp;
    temp=pa;
    pa=pb;
    pb=temp;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
     
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        temp[i]=i;
    }
    
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        SWAP(temp[start], temp[end]);
    }
    
    for(int i=1;i<=N;i++) {
        cout << temp[i] << " ";
    }
    cout << "\n";
}
