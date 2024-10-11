#include<string>
#include <iostream>
#include <stack>

using namespace std;

stack<char> st;

bool solution(string s)
{
    bool answer = true;

    for(char temp:s) {
        if(st.empty()) {
            if(temp==')') return false;
            st.push(temp);
        } else {
            if(st.top()==temp) {
                st.push(temp);
            } else {
                st.pop();
            }
        }
    }
    if(st.empty()) {
        return true;
    } else {
        return false;
    }
}