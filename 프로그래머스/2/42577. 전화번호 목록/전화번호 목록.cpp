#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string,int> m;

bool solution(vector<string> phone_book) {
    
    for(int i=0;i<phone_book.size();i++) {
        m[phone_book[i]]=i+1;
    }
    
    for(int i=0;i<phone_book.size();i++) {
        string temp="";
        for(char temp_Char:phone_book[i]) {
            temp+=temp_Char;
        
            if(m[temp]!=i+1 and m[temp]!=0) {
                
                return false;
            }
        }
    }
    return true;;
    
}