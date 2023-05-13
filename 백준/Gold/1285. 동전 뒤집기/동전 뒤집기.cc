#include <iostream>
#include <vector>

using namespace std;

int N;
bool arr[24][24];
bool temp[24][24];
int min_N=987654321;

void change_to(int idx) {
        
    for(int i=0;i<N;i++) {
        temp[idx][i]=!temp[idx][i];
    }
}

int ret_to() {
    
    int tmp_ret=0;
    
    for(int i=0;i<N;i++) {
        
        int zero_Cnt=0;
        int one_Cnt=0;
        
        for(int j=0;j<N;j++) {
            
            if(temp[j][i]==0) {
                zero_Cnt+=1;
            }
            else if(temp[j][i]==1) {
                one_Cnt+=1;
            }
        }
        
        
        if(zero_Cnt>one_Cnt) {
            tmp_ret+=one_Cnt;
        }
        else {
            tmp_ret+=zero_Cnt;
        }
    }
    
    return tmp_ret;
}

int go_(int n) {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            temp[i][j]=arr[i][j];
        }
    }
    
    for(int i=0;i<N;i++) {
        if(n&(1<<i)) {
            change_to(i);
        }
    }


    return ret_to();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        for(int j=0;j<N;j++) {
            if(a[j]=='H') {
                arr[i][j]=1;
            }
            else {
                arr[i][j]=0;
            }
        }
    }
    
    
    for(int i=0;i<(1<<N);i++) {
        int tot=go_(i);
        
        if(tot<min_N) {
            min_N=tot;
        }
    }
    
    cout << min_N << "\n";;
    
    return 0;
}
