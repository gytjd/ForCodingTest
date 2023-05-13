#include <iostream>
#include <string>

#define MAX_SIZE 26

using namespace std;

void display(int *pa) {
    
    for(int i=0;i<MAX_SIZE;i++) {
        cout << pa[i] << " ";
    }
    cout << "\n";
}

void max_index(int *pa) {

    int i;

    int max=pa[0];
    int maxpos=0;

    for(i=1;i<MAX_SIZE;i++) {
        if(pa[i]>max) {
            max=pa[i];
            maxpos=i;
        }
    }
    
    for(i=1;i<MAX_SIZE;i++) {
        if(i==maxpos) {
            continue;
        }
        if(max==pa[i])
        {
            cout << "?" << "\n";
            return;
        }
    }
    
    cout << char(maxpos+65) << "\n";
}

int main() {
    int result[MAX_SIZE]={0};
    
    string temp;
    cin >> temp;
    
    for(char a:temp) {
        if(a>=97 && a<=123) {
            result[a-97]+=1;
        }
        else {
            result[a-65]+=1;
        }
    }
    max_index(result);

    return 0;
    
}
