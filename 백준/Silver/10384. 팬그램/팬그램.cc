#include <iostream>
#include <cstring>

using namespace std;

int N;
int visited[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    cin.ignore();
    
    for(int i=0;i<N;i++) {
        string data;
        getline(cin,data);
        
        int temp_Ret=987654321;
        memset(visited,0,sizeof(visited));
        
        for(int j=0;j<data.size();j++) {
            if(data[j]>=65 and data[j]<=90) {
                visited[data[j]-65]+=1;
            }
            
            if(data[j]>=97 and data[j]<=122) {
                visited[data[j]-97]+=1;
            }
        }
        
        for(int i=0;i<26;i++) {
            temp_Ret=min(temp_Ret,visited[i]);
        }
        
        cout << "Case " << i+1 << ": ";
        if(temp_Ret==1) {
            cout << "Pangram!" << "\n";
        } else if(temp_Ret==2) {
            cout << "Double pangram!!" << "\n";
        } else if(temp_Ret==3) {
            cout << "Triple pangram!!!" << "\n";
        } else {
            cout << "Not a pangram" << "\n";
        }
    }
    
    return 0;
    
}
