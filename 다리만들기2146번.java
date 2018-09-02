package 백준;
import java.util.*;

public class 다리만들기2146번 {
	public static final int dx[]= {0,-1,0,1};
	public static final int dy[]= {-1,0,1,0};
	static int ans=10000;
	public static void bfs(int a[][],int g[][],int x,int y,int count,int n) {
		Queue<Pair> q=new LinkedList<Pair>();
		q.add(new Pair(x,y));
		a[x][y]=count;
		while(!q.isEmpty()) {
			Pair p=q.remove();
			x=p.x;
			y=p.y;
			g[x][y]=1;
			for(int i=0;i<4;i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(0<=nx&&nx<n&&0<=ny&&ny<n) {
					if(a[nx][ny]==1&&g[nx][ny]==0) {
						a[nx][ny]=count;
						q.add(new Pair(nx,ny));
					}
				}
			}
		}
	}
	public static void bfs2(int a[][],int g[][],int gg[][],int x,int y,int count,int n,Queue<Pair> qq) {
		Queue<Pair> q=new LinkedList<Pair>();
		q.add(new Pair(x,y));
		while(!q.isEmpty()) {
			Pair p=q.remove();
			x=p.x;
			y=p.y;
			for(int i=0;i<4;i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(0<=nx&&nx<n&&0<=ny&&ny<n) {
					if(a[nx][ny]==count&&g[nx][ny]==0) {
						g[nx][ny]=1;
						q.add(new Pair(nx,ny));
					}
					if(a[nx][ny]==0&&gg[nx][ny]==0) {
						gg[nx][ny]=1;
						g[nx][ny]=1;
						qq.add(new Pair(nx,ny));
					}
				}
			}
		}
	}
	public static void bfs3(int a[][],int g[][],int gg[][],int x,int y,int count,int n,Queue<Pair> qq) {
		while(!qq.isEmpty()) {
			Pair p=qq.remove();
			x=p.x;
			y=p.y;
			for(int i=0;i<4;i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(0<=nx&&nx<n&&0<=ny&&ny<n) {
					if(a[nx][ny]==0&&g[nx][ny]==0) {
						g[nx][ny]=1;
						gg[nx][ny]=gg[x][y]+1;
						qq.add(new Pair(nx,ny));
					}
					if(a[nx][ny]!=0&&a[nx][ny]!=count) {
						ans=Math.min(gg[x][y], ans);
						return;
					}
				}
			}
		}
	}
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int count=1;
		int a[][]=new int[n][n];
		int g[][]=new int[n][n];
		int gg[][]=new int[n][n];
		Queue<Pair> qq=new LinkedList<Pair>();
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				a[i][j]=sc.nextInt();
			}
		}
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(a[i][j]==1&&g[i][j]==0) {
					bfs(a,g,i,j,count,n);
					count++;
				}
			}
		}
		count=1;
		g=new int[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(a[i][j]==count&&g[i][j]==0) {
					bfs2(a,g,gg,i,j,count,n,qq);
					bfs3(a,g,gg,i,j,count,n,qq);
					g=new int[n][n];
					qq=new LinkedList<Pair>();
					count++;
				}
			}
		}
		System.out.println(ans);
		
	}

}
