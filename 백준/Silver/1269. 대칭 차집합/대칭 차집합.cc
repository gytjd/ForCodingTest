#include <iostream>
#include <unordered_map>
using namespace std;

int A,B;

unordered_map<int, int> temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> A >> B;
    
    for(int i=0;i<A;i++) {
        int data;
        cin >> data;
        
        temp[data]+=1;
    }
    
    int A_cnt=A;
    int B_cnt=B;
    
    for(int i=0;i<B;i++) {
        int data;
        cin >> data;
        
        if(temp[data]==1) {
            A_cnt-=1;
            B_cnt-=1;
        }
    }
    
    cout << A_cnt+B_cnt << "\n";
    
    return 0;
}

