#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string,int> m;

vector<string> solution(vector<string> players, vector<string> callings) {    
    int curr=0;
    for(string temp:players) {
        m[temp]=curr++;
    }
    
    for(string temp:callings) {  
        string tempB=players[m[temp]-1];
        swap(players[m[temp]],players[m[tempB]]);      
        
        m[temp]-=1;
        m[tempB]+=1;
        
    }
    return players;
}