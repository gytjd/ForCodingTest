#include <iostream>
#include <string>

using namespace std;

int main() {
    string temp;
    cin >> temp;
    
    int i;
    int count=0;
    
    for(i=0;i<temp.size();i++) {
        
        if(temp[i]=='c') {
            if(temp[i+1]=='=' or temp[i+1]=='-') {
                i+=1;
                count+=1;
            }
            else {
                count+=1;
            }
        }
        else if (temp[i]=='d') {
            if(temp[i+1]=='z' and temp[i+2]=='=') {
                
                i+=2;
                count+=1;
            }
            else if (temp[i+1]=='-') {
                i+=1;
                count+=1;
            }
            else {
                count+=1;
            }
        }
        else if (temp[i]=='l' and temp[i+1]=='j') {
            i+=1;
            count+=1;
        }
        else if(temp[i]=='n' and temp[i+1]=='j') {
            i+=1;
            count+=1;
        }
        else if(temp[i]=='s' and temp[i+1] =='=') {
            i+=1;
            count+=1;
        }
        else if(temp[i]=='z' and temp[i+1]=='=') {
            i+=1;
            count+=1;
        }
        else {
            count+=1;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}
