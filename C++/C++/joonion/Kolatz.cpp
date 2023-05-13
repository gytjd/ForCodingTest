#include <iostream>
#include <vector>

using namespace std;

int N,M;
int count_=0;

void Kolatz_per(int start) {
    count_+=1;
    
    if(start==1) {
        return;
    }
    else {
        
        if(start%2==0) {
            Kolatz_per(start/2);
        }
        else {
            Kolatz_per(start*3+1);
        }
    }
}

void Kolatz_s(int start) {
    cout << start << " ";
    
    if(start==1) {
        return;
    }
    else {
        
        if(start%2==0) {
            Kolatz_s(start/2);
        }
        else {
            Kolatz_s(start*3+1);
        }
    }
}

void find_Min() {
    
    int min_num=987654321;
    int min_idx=0;
    
    for(int i=N;i<M;i++) {
        Kolatz_per(i);
        
        if(min_num>=count_) {
            min_num=count_;
            min_idx=i;
        }
        count_=0;
    }
    cout << min_idx << " " << min_num << "\n";
    
    Kolatz_s(min_idx);
    cout << "\n";
    
    
}

void find_Max() {
    
    
    int max_num=0;
    int max_idx=0;
    
    for(int i=N;i<=M;i++) {
        Kolatz_per(i);
        
        if(max_num<=count_) {
            max_num=count_;
            max_idx=i;
        }
        count_=0;
    }
    cout << max_idx << " " << max_num << "\n";
    
    Kolatz_s(max_idx);
    cout << "\n";
    
}
int main() {
    cin >> N >> M;
    
    find_Max();
    
    return 0;
}

