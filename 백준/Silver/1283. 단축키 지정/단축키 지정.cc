#include <iostream>
#include <vector>
using namespace std;

int N;
int visited[40];

int go_(string &temp) {
    if(temp[0]>=97) { // 소문자
        if(visited[temp[0]-97]==0) {
            
            visited[temp[0]-97]=1;
            temp.insert(0,"[");
            temp.insert(2,"]");
            return 1;
        }
    }
    else {
        if(visited[temp[0]-65]==0) {
            
            visited[temp[0]-65]=1;
            temp.insert(0,"[");
            temp.insert(2,"]");
            return 1;
        }
    }
    
    return 0;
}
void start_(vector<string> &temp) {
    
    bool check_Flag=false;
    for(int i=0;i<temp.size();i++) {
        if(go_(temp[i])) {
            check_Flag=true;
            break;
        }
    }
    
    if(!check_Flag) {
        for(int i=0;i<temp.size();i++) {
            for(int j=0;j<temp[i].size();j++) {
                if(temp[i][j]>=97) {
                    
                    if(visited[temp[i][j]-97]==0) {// 소문자
                        
                        visited[temp[i][j]-97]=1;
    
                        temp[i].insert(j,"[");
                        temp[i].insert(j+2, "]");
                        check_Flag=true;
                        break;
                    }

                }
                else {
                    if(visited[temp[i][j]-65]==0) {
                        string s="";
                        s+='[';
                        s+=temp[i][j];
                        

                        visited[temp[i][j]-65]=1;

                        temp[i].insert(j,"[");
                        temp[i].insert(j+2, "]");
                        check_Flag=true;
                        break;
                    }
                }
                
                if(check_Flag) {
                    break;
                }
            }
        }
    }
    
    for(string s:temp) {
        cout << s << " ";
    }
    cout << "\n";
}
int main() {
    
    cin >> N;
    for(int i=0;i<N+1;i++) {
        
        string a;
        getline(cin,a);
        
        if(i==0) {
            continue;
        }
        
        vector<string> v;
        string temp="";
        for(int i=0;i<a.size();i++) {
            
            if(a[i]==' ') {
                if(temp!="") {
                    v.push_back(temp);
                }
                temp="";
                continue;
            }
            else {
                temp+=a[i];
            }
        }
        v.push_back(temp);
        start_(v);
    }
    
    
    return 0;
}
