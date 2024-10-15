#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int,int>> v;

string solution(string number, int k) {
    
    string answer="";

    for(int i=0;i<number.size();i++) {
        // cout << "# " << i << '\n';
        int max_Num=number[i]-'0';
        int max_Idx=i;
        
        for(int j=i+1;j<=i+k;j++) {
            if(max_Num<number[j]-'0') {
                max_Num=number[j]-'0';
                max_Idx=j;
            }
        }    
        
        answer+=number[max_Idx];
        
        k-=max_Idx-i;
        i=max_Idx;
    }
    
    if (k > 0) {
        answer.erase(answer.end() - k, answer.end());
    }

    return answer;
}