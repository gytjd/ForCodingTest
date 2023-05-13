#include <iostream>
#include <vector>
using namespace std;

int N;
struct Node {
    int protein;
    int fat;
    int tan;
    int vitamin;
    int price;
};

vector<Node> temp;
int first,second,third,fourth;
int min_ret=987654321;
string tot_str;

void DFS_recur(int tempA,int tempB,int tempC,int tempD,int tot,int start,string str) {
    
    if(tempA>=first and tempB>=second and tempC>=third and tempD>=fourth) {
        if(tot<min_ret) {
            min_ret=tot;
            tot_str=str;
        }
        return;
    }
    
    for(int i=start;i<N;i++) {
        DFS_recur(tempA+temp[i].protein, tempB+temp[i].fat, tempC+temp[i].tan, tempD+temp[i].vitamin, tot+temp[i].price,i+1,str+to_string(i+1)+" ");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    cin >> first >> second >> third >> fourth;
    
    
    for(int i=0;i<N;i++) {
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        temp.push_back({a,b,c,d,e});
    }
    DFS_recur(0,0,0,0,0,0,"");
    
    if(min_ret==987654321) {
        cout << -1 << "\n";
    }
    else {
        cout << min_ret << "\n";
        cout << tot_str << "\n";
    }
    
    return 0;
}
