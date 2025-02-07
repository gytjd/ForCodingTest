import java.io.*;
import java.util.*;

public class Main {

    static int N,M;
    static List<Integer> arr = new ArrayList<>();

    public static void main(String[] args) throws IOException {


        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++) {
            arr.add(Integer.parseInt(st.nextToken()));
        }
        Collections.sort(arr);

        int ret=0;
        int low=0;
        int high=N-1;

        while(low<high) {
            if(arr.get(low)+arr.get(high)>=M) {
                ret += 1;
                high -= 1;
            }
            low+=1;
        }

        bw.write(Integer.toString(ret));

        bw.flush();
        br.close();
        bw.close();
    }
}
