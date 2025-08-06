import java.util.Scanner;

public class Main {

    static int N,M,L;
    static int visited[]=new int[54];

    public static void main(String[] args) {

        Scanner in=new Scanner(System.in);
        N=in.nextInt();
        M=in.nextInt();
        L=in.nextInt();

        int ret=0;
        int curr=0;

        visited[0]=1;
        while(true) {

            if(visited[curr]==M) {
                System.out.println(ret);
                break;
            }
            if(visited[curr]%2==0) {
                curr=(curr+L)%N;
            } else {
                curr=((curr-L)+N)%N;
            }
            visited[curr]+=1;
            ret+=1;
        }
    }
}
