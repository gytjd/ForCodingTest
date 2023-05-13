#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string a,b;

int M[1004][1004];
int dir[1004][1004];
string get_Lcs(int i,int j) {
    
    if(i==0 or j==0) {
        return "";
    }
    else {
        if(dir[i][j]==1) {
            return get_Lcs(i-1, j-1)+a[i];
        }
        else if(dir[i][j]==2) {
            return get_Lcs(i-1, j);
        }
        else {
            return get_Lcs(i, j-1);
        }
    }
}
void LCS_() {
    
    for(int i=1;i<a.size();i++) {
        for(int j=1;j<b.size();j++) {
            if(a[i]==b[j]) {
                M[i][j]=M[i-1][j-1]+1;
                dir[i][j]=1;
            }
            else {
                M[i][j]=max(M[i][j-1], M[i-1][j]);
                dir[i][j]=2;
                if(M[i][j-1]>M[i-1][j]) {
                    dir[i][j]=3;
                }
            }
        }
    }
    
    cout << M[a.size()-1][b.size()-1] << "\n";
    cout << get_Lcs(a.size()-1,b.size()-1) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> a;
    cin >> b;
    
    a=" "+a;
    b=" "+b;
    
    LCS_();
    
    return 0;
}

