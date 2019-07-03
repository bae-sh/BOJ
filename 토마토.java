import java.util.*;
import java.io.*;

public class 토마토 {
	static int dx[] = { -1, 0, 1, 0, 0, 0 };
	static int dy[] = { 0, 1, 0, -1, 0, 0 };
	static int dz[] = { 0, 0, 0, 0, 1, -1 };
	static int day = 0;
	static int s1 = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s[] = br.readLine().split(" ");
		int m = Integer.parseInt(s[0]);
		int n = Integer.parseInt(s[1]);
		int h = Integer.parseInt(s[2]);
		int dp[][][] = new int[n][m][h];
		Queue<Pair7569> q = new LinkedList();
		for (int k = 0; k < h; k++) {
			for (int i = 0; i < n; i++) {
				s = br.readLine().split(" ");
				for (int j = 0; j < m; j++) {
					dp[i][j][k] = Integer.parseInt(s[j]);
					if (dp[i][j][k] == 0)
						s1++;
					else if (dp[i][j][k] == 1) {
						q.add(new Pair7569(i, j, k));
					}
				}
			}
		}
		bfs(dp,q,m,n,h);
		if (s1 == 0) {
			System.out.println(day-1);
		} else {
			System.out.println(-1);
		}

	}

	static void bfs(int dp[][][],Queue<Pair7569> q,int m, int n, int h) {
		while (!q.isEmpty()) {
			Pair7569 p = q.poll();
			if(day<dp[p.x][p.y][p.z]) {
				day=dp[p.x][p.y][p.z];
			}
			for (int i = 0; i < 6; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				int nz = p.z + dz[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && 0 <= nz && nz < h && dp[nx][ny][nz] == 0) {
					dp[nx][ny][nz] = dp[p.x][p.y][p.z] + 1;
					q.add(new Pair7569(nx, ny, nz));
					s1--;
				}
			}
		}

	}
}

class Pair7569 {
	int x, y, z;

	Pair7569(int x, int y, int z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}
}
