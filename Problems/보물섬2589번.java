package 백준;

import java.util.*;
class Pair{
	int x;
	int y;
	Pair(int x,int y){
		this.x=x;
		this.y=y;
	}
}
public class 보물섬2589번 {
	static int dx[] = { -1, 0, 1, 0 };
	static int dy[] = { 0, -1, 0, 1 };
	static int Max=0;
	static int s3=0;
	static void bfs(String s[][], int c[][], int x, int y, int m, int n, Pair pair,Queue<Pair> p2) {
		Queue<Pair> q = new LinkedList<Pair>();
		q.add(new Pair(x, y));
		pair.x=x;
		pair.y=y;
		c[x][y] = 1;
		int max = 0;

		while (!q.isEmpty()) {
			Pair p = q.remove();
			x = p.x;
			y = p.y;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && c[nx][ny] == 0 && s[nx][ny].equals("L")) {
					c[nx][ny] = c[x][y] + 1;
					q.add(new Pair(nx, ny));
					if(c[nx][ny]>max) {
						max=c[nx][ny];
						if(max>Max) {
							Max=max;
						}
					}
				}
			}
		}
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(c[i][j]==max&&s3==0) {
					p2.add(new Pair(i,j));
				}
			}
		}

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		Pair p = new Pair(-1, -1);
		int max = 0;
		String s[][] = new String[n][m];
		int c[][] = new int[n][m];
		Queue<Pair> p2=new LinkedList<Pair>();
		for (int i = 0; i < n; i++) {
			String a = sc.next();
			for (int j = 0; j < m; j++) {
				s[i][j] = a.charAt(j) + "";
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j].equals("L") && c[i][j] == 0) {
					bfs(s, c, i, j, m, n, p,p2);
				}
			}
		}
		s3=1;
		while(!p2.isEmpty()) {
			p2.remove();
			int ans[][] = new int[n][m];
			bfs(s, ans, p.x, p.y, m, n, p,p2);
		}
		System.out.println(Max-1);

	}

}
