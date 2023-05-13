#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int T;
int N,M;

vector<int> A;
vector<int> B;

unordered_map<int, int> tempA;
unordered_map<int, int> tempB;

void find_N(int n) {
    
    vector<int> temp=A;
    
    int idx=1;
    int temp_idx;
    
    while(idx!=n) {
        
        for(int i=0;i<n;i++) {
            
            temp_idx=(i+idx)%n;
            temp[i]+=A[temp_idx];
            
            if(temp[i]>T) {
                continue;
            }
            
            tempA[temp[i]]+=1;
            if(idx==n-1) {
                break;
            }
        }
        idx+=1;
    }
}

void find_M(int m) {
    
    
    vector<int> temp=B;
    
    int idx=1;
    int temp_idx;
    
    while(idx!=m) {
        
        for(int i=0;i<m;i++) {
            temp_idx=(i+idx)%m;
            temp[i]+=B[temp_idx];
            
            if(temp[i]>T) {
                continue;
            }
            
            tempB[temp[i]]+=1;
            if(idx==m-1) {
                break;
            }
        }
        
        idx+=1;
    }
    
}

void find_NM() {
    
    int count_T=0;
    for(pair<int, int> temp:tempA) {
        
        if(temp.first==T) {
            count_T+=temp.second;
        }
        else {
            count_T+=tempA[temp.first]*tempB[T-temp.first];
        }
    }
    
    for(pair<int, int> temp:tempB) {
        if(temp.first==T) {
            count_T+=temp.second;
        }
    }
    
    cout << count_T << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    cin >> N >> M;
    int data;
    
    for(int i=0;i<N;i++) {
        cin >> data;
        A.push_back(data);
        tempA[data]+=1;
    }
    
    for(int i=0;i<M;i++) {
        cin >> data;
        B.push_back(data);
        tempB[data]+=1;
    }
    
    find_N(N);
    find_M(M);
    find_NM();
    
    return 0;
}
