#include <iostream>
#include <vector>
using namespace std;

int N;
bool check[4000004];
vector<int> arr;

void init_() {
    for(long long i=2;i<=N;i++) {
        
        if(check[i]==true) {
            continue;
        }
        
        for(long long k=i*i;k<=N;k+=i) {
            check[k]=true;
        }
    }
    
    for(int i=2;i<=N;i++) {
        if(check[i]==false) {
            arr.push_back(i);
        }
    }
    
    
}

void cal_() {
    
    int start=0;
    int end=0;
    int ret=0;
    int ret_Cnt=0;
    
    while(end<arr.size()) {
        
        ret+=arr[end];
        
        if(ret==N) {
            ret_Cnt+=1;
        }
        else if(ret>N) {
            while(ret>N) {
                ret-=arr[start];
                start+=1;
            }
            
            if(ret==N) {
                ret_Cnt+=1;
            }
        }
        
        end+=1;
    }
    
    cout << ret_Cnt << "\n";
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    
    init_();
    cal_();
    
    return 0;
}
