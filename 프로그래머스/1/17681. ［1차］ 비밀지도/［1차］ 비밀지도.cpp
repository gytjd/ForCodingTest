#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_bin(int n,int temp) {
    
    string ret="";
    while(temp!=0) {
        if(temp%2) {
            ret+='#';
        }
        else {
            ret+=' ';
        }
        temp/=2;
    }
    reverse(ret.begin(),ret.end());
    for(int i=0;i<ret.size()-n;i++) {
        ret=' '+ret;
    }
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0;i<n;i++) {
        int temp=arr1[i]|arr2[i];
        answer.push_back(to_bin(n,temp));
    }
    return answer;
}