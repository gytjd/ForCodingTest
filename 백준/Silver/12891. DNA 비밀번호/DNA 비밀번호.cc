#include <iostream>

using namespace std;

int ret;
int S,P;
string str;
int visited[4];
int Num[4];

int chr_to_int(char temp) {
    
    if(temp=='A') {
        return 0;
    } else if(temp=='C') {
        return 1;
    } else if(temp=='G') {
        return 2;
    } else {
        return 3;
    }
}

void display_() {
    for(int i=0;i<4;i++) {
        cout << Num[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> S >> P;
    cin >> str;
    for(int i=0;i<4;i++) {
        cin >> visited[i];
    }
    
    for(int i=0;i<P;i++) {
        int temp_Num=chr_to_int(str[i]);
        Num[temp_Num]+=1;
    }
    int temp_Idx=P;
    while(temp_Idx<S) {
        
        if(visited[0]<=Num[0] and visited[1]<=Num[1] and visited[2]<=Num[2] and visited[3]<=Num[3]) {
            ret+=1;
        }
        int tempA=chr_to_int(str[temp_Idx-P]);
        int tempB=chr_to_int(str[temp_Idx]);
        
//        cout << temp_Idx-P << " " << temp_Idx << "\n";
//        display_();
        
        Num[tempA]-=1;
        Num[tempB]+=1;
        temp_Idx+=1;
    }
    
    if(visited[0]<=Num[0] and visited[1]<=Num[1] and visited[2]<=Num[2] and visited[3]<=Num[3]) {
        ret+=1;
    }
    
    
    
    cout << ret << "\n";
    
    return 0;
}
