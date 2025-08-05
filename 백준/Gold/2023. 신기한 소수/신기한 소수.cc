#include <iostream>

using namespace std;

int N;

bool find_Prime(int curr) {
    
    if(curr<2) {
        return false;
    }
    
    for(int i=2;i*2<=curr;i++) {
        if(curr%i==0) {
            return false;
        }
    }
    return true;
}

void DFS_recur(int curr,int temp) {
    
    if(curr==N) {
        cout << temp << "\n";
        return;
    }
    
    for(int i=0;i<10;i++) {
    
        int temp_Num=temp*10+i;
        if(find_Prime(temp_Num)) {
            DFS_recur(curr+1, temp_Num);
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    DFS_recur(0, 0);
    
    return 0;
}
