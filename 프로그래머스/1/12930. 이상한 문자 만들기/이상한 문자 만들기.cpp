#include <string>

using namespace std;

string solution(string s) {
    int idx = 0;
    
    for(int i=0; i<s.size(); i++){
        
        if(s[i] == ' '){
            idx=0;
            continue; 
        }
       
        if(idx%2){
            s[i] = tolower(s[i]);
        }
        else{
            s[i] = toupper(s[i]); 
        }
        idx++;
    }
    
    return s;
}