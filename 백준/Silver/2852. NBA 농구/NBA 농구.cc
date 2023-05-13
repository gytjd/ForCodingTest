#include <iostream>
using namespace std;

struct Player{
    int cnt;
    int curr_hour;
    int curr_min;
    
    int total;
    
    Player() {
        cnt=0;
        curr_hour=0;
        curr_min=0;
        total=0;
    }
};



void check_hour(Player *pa,int from_H,int from_M,int to_H,int to_M) {
    int tempA=from_H*60+from_M;
    int tempB=to_H*60+to_M;
    
    pa->total+=tempA-tempB;
}

void sub_hour(Player *pa,int from_H,int from_M,int to_H,int to_M) {
    int tempA=from_H*60+from_M;
    int tempB=to_H*60+to_M;
    
    pa->total-=(tempA-tempB);
}

void print_time(int total) {
    int tempA=total/60;
    int tempB=total%60;
    
    if(tempA<10) {
        printf("0%d",tempA);
    }
    else {
        printf("%d",tempA);
    }
    
    printf(":");
    
    if(tempB<10) {
        printf("0%d",tempB);
    }
    else {
        printf("%d",tempB);
    }
}
int main() {
    
    
    Player A,B;
    A=Player();
    B=Player();

    bool A_Flag=false;
    bool B_Flag=false;
    
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++) {
        int tempCnt,hour,min;
        scanf("%d %d:%d",&tempCnt,&hour,&min);
        
        if(tempCnt==1) {
            
            if(A.cnt==0) {
                A.curr_hour=hour;
                A.curr_min=min;
            }
            A.cnt+=1;
            
            if(A.cnt>B.cnt and A_Flag==false) {
                check_hour(&A, 48, 0, hour, min);
                A_Flag=true;
            }
            else if(A.cnt==B.cnt) {
                sub_hour(&B, 48, 0, hour, min);
                B_Flag=false;
                B.cnt=0;
                A.cnt=0;
            }
        }
        else {
            
            if(B.cnt==0) {
                B.curr_hour=hour;
                B.curr_min=min;
            }
            
            B.cnt+=1;
            
            if(A.cnt<B.cnt and B_Flag==false) {
                check_hour(&B, 48, 0, hour, min);
                B_Flag=true;
            }
            else if(A.cnt==B.cnt) {
                sub_hour(&A, 48, 0, hour, min);
                A_Flag=false;
                A.cnt=0;
                B.cnt=0;
            }
        }
    }
    print_time(A.total);
    printf("\n");
    print_time(B.total);
    printf("\n");
    
    
    return 0;
}
