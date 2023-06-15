#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


long long count_T;
long long N;
string a,b,c;
long long visited[30];
long long temp[14];
vector<char> ret;

void go_(long long idx) {
    
    if(idx==N) {
        
        long long temp_A=0;
        long long temp_B=0;
        long long temp_C=0;
        
        for(long long i=0;i<a.size();i++) {
            temp_A*=10;
            temp_A+=visited[a[i]-65];
        }
        
        for(long long i=0;i<b.size();i++) {
            temp_B*=10;
            temp_B+=visited[b[i]-65];
        }
        
        for(long long i=0;i<c.size();i++) {
            temp_C*=10;
            temp_C+=visited[c[i]-65];
        }
        
//        cout << temp_A << " " << temp_B << " " << temp_C << "\n";
        if(temp_A+temp_B==temp_C) {
            cout << "YES" << "\n";
            exit(0);
//            count_T+=1;
//            cout << temp_A << " " << temp_B << " " << temp_C << "\n";
        }
        return;
    }
    
    for(long long i=0;i<10;i++) {
        if(temp[i]==0) {
            visited[ret[idx]-65]=i;
            temp[i]=1;
            
            go_(idx+1);
            
            temp[i]=0;
            visited[ret[idx]-65]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> a >> b >> c;
    
    for(long long i=0;i<a.size();i++) {
        
        if(visited[a[i]-65]==0) {
            visited[a[i]-65]=1;
            ret.push_back(a[i]);
            N+=1;
        }
    }
    for(long long i=0;i<b.size();i++) {
        if(visited[b[i]-65]==0) {
            visited[b[i]-65]=1;
            ret.push_back(b[i]);
            N+=1;
        }
    }
    for(long long i=0;i<c.size();i++) {
        if(visited[c[i]-65]==0) {
            visited[c[i]-65]=1;
            ret.push_back(c[i]);
            N+=1;
        }
    }
    
    if(N>10) {
        cout << "NO" << "\n";
    }
    else {
        memset(visited, -1, sizeof(visited));
        go_(0);
        cout << "NO" << "\n";
    }
    
    return 0;
}
