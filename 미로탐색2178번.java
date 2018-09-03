package 백준;
import java.util.*;
public class 미로탐색2178번 {
	public static final int dx[]= {0,-1,0,1};
	public static final int dy[]= {-1,0,1,0};
	static void bfs(int a[][],int g[][],int x,int y,int n,int m) {
		Queue<Pair> q=new LinkedList<Pair>();
		g[x][y]=1;
		q.add(new Pair(x,y));
		while(!q.isEmpty()) {
			Pair p=q.remove();
			x=p.x;
			y=p.y;
			for(int i=0;i<4;i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(0<=nx&&nx<n&&0<=ny&&ny<m&&g[nx][ny]==0&&a[nx][ny]==1) {
					g[nx][ny]=g[x][y]+1;
					q.add(new Pair(nx,ny));
				}
			}
		}
		
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int a[][]=new int[n][m];
		int g[][]=new int[n][m];
		for(int i=0;i<n;i++) {
			String s=sc.next();
			for(int j=0;j<m;j++) {
				a[i][j]=s.charAt(j)-'0';
			}
		}
		bfs(a,g,0,0,n,m);
		System.out.println(g[n-1][m-1]);
		
	}

}
