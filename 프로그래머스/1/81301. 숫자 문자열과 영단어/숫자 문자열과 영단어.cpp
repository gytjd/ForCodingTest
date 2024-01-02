#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    
    while(s.find("one")<100) {
        s.replace(s.find("one"),3,"1");
    }
    
        while(s.find("two")<100) {
        s.replace(s.find("two"),3,"2");
    }
    
        while(s.find("three")<100) {
        s.replace(s.find("three"),5,"3");
    }
    
        while(s.find("four")<100) {
        s.replace(s.find("four"),4,"4");
    }
    
        while(s.find("five")<100) {
        s.replace(s.find("five"),4,"5");
    }
    
        while(s.find("six")<100) {
        s.replace(s.find("six"),3,"6");
    }
    
        while(s.find("seven")<100) {
        s.replace(s.find("seven"),5,"7");
    }
    
        while(s.find("eight")<100) {
        s.replace(s.find("eight"),5,"8");
    }
    
        while(s.find("nine")<100) {
        s.replace(s.find("nine"),4,"9");
    }
    
        while(s.find("zero")<100) {
        s.replace(s.find("zero"),4,"0");
    }
    
    
    return stoi(s);
}