#include <iostream>
#include <vector>
using namespace std;

int N;
int cnt_A=0;
int cnt_B=0;

void merge(int h,int m,vector<int> U,vector<int> V,vector<int> &S)
{
    cnt_A+=1;
    int i=1,j=1,k=1;
    
    while(i<=h and j<=m) {
        S[k++]=(U[i]<V[j]) ? U[i++]:V[j++];
    }
    
    if(i>h) {
        while(j<=m) {
            S[k++]=V[j++];
        }
    }
    else {
        while(i<=h) {
            S[k++]=U[i++];
        }
    }
}

void mergesort(int n, vector<int>& S) {
    cnt_B+=1;
    if (n > 1) {
        int h = n / 2, m = n - h;
        vector<int> U(h+1), V(m+1);

        for (int i = 1; i <= h; i++)
            U[i] = S[i];
        for (int i = h+1; i <= n; i++)
            V[i - h] = S[i];
        
        
        mergesort(h, U);
        mergesort(m, V);
        merge(h, m, U, V, S);
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    vector<int> temp(N+1);
    for(int i=1;i<=N;i++) {
        int data;
        cin >> data;
        temp[i]=data;
    }
    
    mergesort(N, temp);
    
    for(int i=1;i<=N;i++) {

        if(i==N) {
            cout << temp[i];
        }
        else {
            cout << temp[i] << " ";
        }
    }
    cout << "\n";
    cout << cnt_A << " " <<cnt_B <<  "\n";
    
}


