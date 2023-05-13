#include <stdio.h>

int main(){
    int B1, B2, B3;
    int V1, V2;
    int Min1, Min2;
    
    scanf("%d\n%d\n%d\n%d\n%d\n", &B1, &B2, &B3, &V1, &V2);
    
    if(B1 < B2){
        if(B1 < B3){
            Min1 = B1;  }


        else {
            Min1= B3;  }

       }
   
     else {
        if(B2 < B3){
            Min1 = B2; }

        else {
            Min1 = B3; }
      }
     
    if(V1 < V2){
        Min2 = V1;     }
    
    else{
        Min2 = V2;     }
    
    printf("%d", Min1+Min2-50);
    return 0;
}