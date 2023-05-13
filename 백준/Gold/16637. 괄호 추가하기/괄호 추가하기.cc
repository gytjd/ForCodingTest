#include <iostream>
#include <vector>
using namespace std;

int tot=-987654321;
int N;
string a;

vector<char> op;
vector<int> num;

int cal(int a,int b,char oper) {
    if(oper=='+') return a+b;
    if(oper=='-') return a-b;
    if(oper=='*') return a*b;
    
    return a+b;
}

void go(int idx,int sum) {
    if(idx==num.size()-1) {
        if(tot<sum) {
            tot=sum;
        }
        return;
    }
    
    go(idx+1,cal(sum, num[idx+1], op[idx]));
    if(idx+2<=num.size()-1) {
        int temp=cal(num[idx+1],num[idx+2], op[idx+1]);
        go(idx+2, cal(sum, temp, op[idx]));
    }
    
    return;
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    cin >> a;
    
    for(int i=0;i<N;i++) {
        if(i%2==0) {
            num.push_back(a[i]-'0');
        }
        else {
            op.push_back(a[i]);
        }
    }
    go(0, num[0]);
    cout << tot << "\n";
    return 0;
}
