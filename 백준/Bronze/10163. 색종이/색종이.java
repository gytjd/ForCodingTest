

import java.util.Scanner;

public class Main {

    static int N;
    static int arr[][]=new int[1004][1004];
    static int ret[]=new int[1004];

    public static void draw_(int startX,int startY,int tempN,int tempM,int Num) {

        for(int i=startX;i<startX+tempN;i++) {
            for(int j=startY;j<startY+tempM;j++) {
                arr[i][j]=Num;
            }
        }
    }

    public static void display_() {

        for(int i=0;i<1004;i++) {
            for (int j = 0; j < 1004; j++) {
                ret[arr[i][j]] += 1;
            }
        }
    }
    public static void main(String[] args) {

        Scanner in =new Scanner(System.in);
        N=in.nextInt();

        for(int i=0;i<N;i++) {
            int startX,startY,tempN,tempM;
            startX=in.nextInt();
            startY=in.nextInt();
            tempN=in.nextInt();
            tempM=in.nextInt();
            draw_(startX,startY,tempN,tempM,i+1);
        }

        display_();
        for(int i=1;i<=N;i++) {
            System.out.println(ret[i]);
        }
    }
}
