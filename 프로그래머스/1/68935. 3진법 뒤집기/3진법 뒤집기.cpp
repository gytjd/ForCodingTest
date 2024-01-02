#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string to_3nd(int n) {
    string ans="";
    
    while(n!=0) {
        ans+=char(n%3+48);
        n/=3;
    }
    return ans;
}
int solution(int n) {
    int answer = 0;
    string temp=to_3nd(n);
    int n_Size=temp.size();
    
    for(int i=n_Size-1;i>=0;i--) {
        // cout << pow(3,n_Size-i-1) << "\n";
        answer+=pow(3,n_Size-i-1)*(temp[i]-'0');
    }
    return answer;
}