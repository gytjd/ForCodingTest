#include <iostream>
using namespace std;

string arr[10]={{"1101111"},
    {"0101000"},
    {"1110110"},
    {"1111100"},
    {"0111001"},
    {"1011101"},
    {"1011111"},
    {"1101000"},
    {"1111111"},
    {"1111101"}
};

int num[10][10];

int N,K,P,X;

int is_diff(int a,int b) {
    
    int ret=0;
    for(int i=0;i<7;i++) {
        if(arr[a][i]!=arr[b][i]) {
            ret+=1;
        }
    }
    
    return ret;
}


void go_() {
    
    int ret=0;
    string oriTemp="";
    string ori=to_string(X);
    long long oriS=ori.size();
    
    for(int i=0;i<K-oriS;i++) {
        oriTemp+='0';
    }
    ori=oriTemp+ori;
    
    
    
    
    for(int i=1;i<=N;i++) {
        
        if(i==X) {
            continue;
        }
        
        string temp=to_string(i);
        long long tempS=temp.size();
        string a="";
        int sum=0;
        
        for(int j=0;j<K-tempS;j++) {
            a+='0';
        }
        temp=a+temp;
        
//        cout << temp << "\n";
        for(int j=0;j<K;j++) {
//            cout << temp[j] << " " << ori[j] << " " << num[temp[j]-'0'][ori[j]-'0']  << "\n";
            sum+=num[temp[j]-'0'][ori[j]-'0'];
        }
        
        if(sum<=P) {
            ret+=1;
        }
    }
    
    cout << ret << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K >> P >> X;
    
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            num[i][j]=is_diff(i, j);
        }
    }
    
    go_();
    
    return 0;
    
}
