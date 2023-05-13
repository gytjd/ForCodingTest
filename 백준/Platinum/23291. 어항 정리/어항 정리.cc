#include <iostream>
#include <queue>
#include <vector>
using namespace std;

deque<int> arr[10];
int N,K;
int row=2;
int col=1;
int dir[2][2]={{-1,0},{0,1}};

void display_() {
    for(int i=0;i<arr[0].size();i++) {
        cout << arr[0][i] << " ";
    }
    cout << '\n';
}
void init_() {
    
    int min_data=987654321;
    for(int i=0;i<N;i++) {
        if(min_data>arr[0][i]) {
            min_data=arr[0][i];
        }
    }
    
    for(int i=0;i<N;i++) {
        if(arr[0][i]==min_data) {
            arr[0][i]+=1;
        }
    }
    
    row=2;
    col=1;
}

void go_() {
    
    
    int temp=arr[0].front();
    arr[0].pop_front();
    arr[1].push_back(temp);
    
    
    bool col_Check=true;
    
    while(arr[0].size()-col>=row) {
        
        for(int i=0;i<col;i++) {
            for(int j=0;j<row;j++) {
                
                temp=arr[j].front();
                arr[j].pop_front();
                arr[col-i].push_back(temp);
            }
        }
        
        if(col_Check) {
            col+=1;
            col_Check=false;
        }
        else {
            row+=1;
            col_Check=true;
        }
    }
//    for(int i=row-1;i>=0;i--) {
//        for(int j=0;j<arr[i].size();j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << "\n";
//    }
    
}

void adjust_init_() {
    
    deque<int> temp_q;
    for(int i=0;i<col;i++) {
        for(int j=0;j<row;j++) {
            int temp=arr[j].front();
            arr[j].pop_front();
            temp_q.push_back(temp);
        }
    }
    
    unsigned long q_Size=arr[0].size();
    for(int i=0;i<q_Size;i++) {
        temp_q.push_back(arr[0].front());
        arr[0].pop_front();
    }
    
    for(int i=0;i<row;i++) {
        arr[i].clear();
    }
    
    arr[0]=temp_q;
    
//    for(int i=0;i<arr[0].size();i++) {
//        cout << arr[0][i] << " ";
//    }
//    cout << '\n';
}


void adjustFish() {
    
    deque<int> tmp[10];
    for (int i = 0; i < row; i++) {
        tmp[i] = arr[i];
    }
 
    for (int i = row - 1; i >= 0; i--) {
        for (int j = 0; j < arr[i].size(); j++) {
            int x = i;
            int y = j;
            int num = arr[x][y];
            
            for (int k = 0; k < 2; k++) {
                int nx = x + dir[k][0];
                int ny = y + dir[k][1];
                
                if (nx >= 0 and ny < arr[i].size()) {
                    int num2 = arr[nx][ny];
                    
                    int diff = abs(num - num2) / 5;
                    if (diff > 0) {
                        if (num > num2) {
                            tmp[x][y] -= diff;
                            tmp[nx][ny] += diff;
                        } else {
                            tmp[nx][ny] -= diff;
                            tmp[x][y] += diff;
                        }
                    }
                    
                }
            }
        }
    }
 
    for (int i = 0; i < row; i++) {
        arr[i] = tmp[i];
    }
//
//    for(int i=row-1;i>=0;i--) {
//        for(int j=0;j<arr[i].size();j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << "\n";
//    }
}

void last_fun() {
    
    
    for(int i=0;i<N/2;i++) {
        arr[1].push_front(arr[0][i]);
    }
    
    for(int i=0;i<N/2;i++) {
        arr[0].pop_front();
    }
    
    for(int i=0;i<N/4;i++) {
        arr[2].push_front(arr[1][i]);
        arr[3].push_front(arr[0][i]);
    }
    
    for(int i=0;i<N/4;i++) {
        arr[0].pop_front();
        arr[1].pop_front();
    }
    
    col=N/4;
    row=4;
//
//    for(int i=row-1;i>=0;i--) {
//        for(int j=0;j<arr[i].size();j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";
    
    adjustFish();
//    cout << "\n";
//    for(int i=row-1;i>=0;i--) {
//        for(int j=0;j<arr[i].size();j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << "\n";
//    }
//
    
    deque<int> ret;
    for(int i=0;i<col;i++) {
        for(int j=0;j<row;j++) {
            int tmp_N=arr[j].front();
            arr[j].pop_front();
            ret.push_back(tmp_N);
        }
    }
    
    for(int i=0;i<row;i++) {
        arr[i].clear();
    }
    
    arr[0]=ret;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K;
    
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        arr[0].push_back(data);
    }
    
    int cnt_tot=0;
    while(1) {
        cnt_tot+=1;
        init_();
        go_();
        adjustFish();
        adjust_init_();
        last_fun();
        
        int max_N=-987654321;
        int min_N=987654321;
        
        for(int i=0;i<arr[0].size();i++) {

            if(max_N<arr[0][i]) {
                max_N=arr[0][i];
            }
            if(min_N>arr[0][i]) {
                min_N=arr[0][i];
            }
        }
        
        
        if(abs(max_N-min_N)<=K) {
            cout << cnt_tot << "\n";
            break;
        }
    }
    
    
    return 0;

}


