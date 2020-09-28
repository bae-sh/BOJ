import java.util.*;

public class 유기농배추 {
	static int dx[] = { -1, 0, 1, 0 };
	static int dy[] = { 0, 1, 0, -1 };
	static int ans = 0;

	static void bfs(int d[][], boolean c[][], int x, int y, int m, int n) {
		Queue<Pair1012> q = new LinkedList();
		q.add(new Pair1012(x, y));
		while (!q.isEmpty()) {
			Pair1012 p = q.poll();
			for (int i = 0; i < 4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				if (0 <= nx && nx < m && 0 <= ny && ny < n) {
					if (d[nx][ny] == 1 && c[nx][ny] == false) {
						c[nx][ny] = true;
						q.add(new Pair1012(nx, ny));
					}
				}
			}
		}
		ans++;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int l = 0; l < t; l++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int k = sc.nextInt();
			ans=0;
			int d[][] = new int[m][n];
			boolean c[][] = new boolean[m][n];
			for (int i = 0; i < k; i++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				d[b][a] = 1;
			}
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (d[i][j] == 1 && c[i][j] == false)
						bfs(d, c, i, j, m, n);
				}
			}
			System.out.println(ans);
		}
	}

}

class Pair1012 {
	int x;
	int y;

	Pair1012(int x, int y) {
		this.x = x;
		this.y = y;
	}
}
