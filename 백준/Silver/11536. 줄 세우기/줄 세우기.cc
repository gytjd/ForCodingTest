#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool check_Flag=false;
vector<pair<string,int>> v;
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        string data;
        cin >> data;
        v.push_back({data,i});
    }
    
    sort(v.begin(),v.end());
    int temp_Num=v[0].second;
    for(int i=1;i<N;i++) {
        if(temp_Num>v[i].second) {
            check_Flag=true;
            break;
        }
        temp_Num=v[i].second;
    }
    
    if(check_Flag) {// 증가 아님
        check_Flag=false;
        
        sort(v.begin(),v.end(),less<>());
    
        int temp_Num=v[0].second;
        for(int i=1;i<N;i++) {
            if(temp_Num<v[i].second) {
                check_Flag=true;
                break;
            }
            temp_Num=v[i].second;
        }
        
        if(check_Flag) {
            cout << "NEITHER" << "\n";
        } else {
            cout << "DECREASING" << "\n";
        }
        
    } else {
        cout << "INCREASING" << "\n";
    }
        
    return 0;
}
