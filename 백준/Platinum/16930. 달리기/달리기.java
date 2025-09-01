import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	static class Pair {
		int x;
		int y;
		
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static int N,M,K;
	static char arr[][]=new char[1004][1004];
	static int visited[][]=new int[1004][1004];
	static int dir[][]= {{0,1},{1,0},{0,-1},{-1,0}};
	static int startX,startY,endX,endY;
	
	public static void display_() {
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				System.out.print(visited[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println();
	}
	
public static void BFS_iter(int sx, int sy) {
    Queue<Pair> q = new LinkedList<>();
    q.add(new Pair(sx, sy));
    visited[sx][sy] = 1;

    while (!q.isEmpty()) {
        int x = q.peek().x;
        int y = q.peek().y;
        q.poll();

        for (int d = 0; d < 4; d++) {
            for (int step = 1; step <= K; step++) {
                int dx = x + dir[d][0] * step;
                int dy = y + dir[d][1] * step;

                if (dx < 0 || dx >= N || dy < 0 || dy >= M) break;
                if (arr[dx][dy] == '#') break;

                // 이미 더 짧은 거리로 방문된 칸을 만나면 그 방향은 중단
                if (visited[dx][dy] != 0 && visited[dx][dy] < visited[x][y] + 1) break;

                if (visited[dx][dy] == 0) {
                    visited[dx][dy] = visited[x][y] + 1;
                    q.add(new Pair(dx, dy));
                } else if (visited[dx][dy] == visited[x][y] + 1) {
                    // 같은 거리로 이미 방문된 칸: 그 칸은 스킵하고 뒤로 계속
                    continue;
                } else {
                    // visited[dx][dy] > visited[x][y] + 1 인 경우는 거의 없지만
                    // 어쨌든 더 볼 이유가 없으니 break 해도 무방
                    break;
                }
            }
        }
    }
}

	
	public static void main(String[] args) {
		//--------------솔루션 코드를 작성하세요.---------------------------
		
		Scanner in = new Scanner(System.in);
		N=in.nextInt();
		M=in.nextInt();
		K=in.nextInt();
		
		for(int i=0;i<N;i++) {
			String data;
			data=in.next();
			for(int j=0;j<M;j++) {
				arr[i][j]=data.charAt(j);
			}
		}
		
		startX=in.nextInt();
		startY=in.nextInt();
		endX=in.nextInt();
		endY=in.nextInt();
		
		BFS_iter(startX-1,startY-1);
		System.out.println(visited[endX-1][endY-1]-1);
	}
}
