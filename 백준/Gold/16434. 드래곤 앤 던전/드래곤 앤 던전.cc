#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int t,a,h;
};

vector<Node> v;
int N,H;
long long low=1,high=9e18,mid,ret;
long long temp;

int go_(long long Hp,long long Atk) {
    
    long long temp_Hp=Hp;
    for(Node temp:v) {
        
        if(temp.t==1) {
            if(temp.h%Atk) {
                temp_Hp-=(temp.h/Atk)*temp.a;
            }
            else {
                temp_Hp-=(temp.h/Atk-1)*temp.a;
            }
//            cout << temp_Hp << "\n";
//            cout << temp.h << " " << Atk << " " << temp.a << "\n";
            if(temp_Hp<=0) {
                return 0;
            }
        }
        else {
            Atk+=temp.a;
            temp_Hp+=temp.h;
            if(temp_Hp>Hp) {
                temp_Hp=Hp;
            }
        }
    }
    
    
    return 1;
}

void start() {
    
    while(low<=high) {
        mid=(low+high)/2;
//        cout << mid << "\n";
        
        if(go_(mid,H)) {
//            cout << mid << "\n";
            ret=mid;
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    
    cout << ret << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> H;
    temp=H;
    for(int i=0;i<N;i++) {
        int t,a,h;
        cin >> t >> a >> h;
        v.push_back({t,a,h});
    }
    
    start();
    
    return 0;
}
