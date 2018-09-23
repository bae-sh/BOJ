package 백준;
import java.util.*;

public class 토마토7576번 {
	public static final int dx[]= {0,-1,0,1};
	public static final int dy[]= {-1,0,1,0};
	static int day=0;
	static int s=0;
	static void bfs(int a[][],int g[][],int m,int n,Queue<Pair> q) {
		while(!q.isEmpty()) {
			Pair p=q.remove();
			int x=p.x;
			int y=p.y;
			if(g[x][y]!=day+1) {
				day++;
			}
			for(int i=0;i<4;i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(0<=nx&&nx<m&&0<=ny&&ny<n&&g[nx][ny]==0) {
					if(a[nx][ny]==0) {
						s--;
						a[nx][ny]=1;
						g[nx][ny]=g[x][y]+1;
						q.add(new Pair(nx,ny));
					}
					else if(a[nx][ny]==-1) {
						continue;
					}
				}
			}
		}
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int a[][]=new int[m][n];
		int g[][]=new int[m][n];
		Queue<Pair> q=new LinkedList<Pair>();
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				a[i][j]=sc.nextInt();
				if(a[i][j]==1) {
					q.add(new Pair(i,j));
					g[i][j]=1;
				}
				else if(a[i][j]==0) {
					s++;
				}
			}
		}
		bfs(a,g,m,n,q);
		if(s==0) {
			System.out.println(day);
		}
		else {
			System.out.println(-1);
		}
		
		
	}

}
