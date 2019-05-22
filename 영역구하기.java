import java.util.*;
public class 영역구하기 {
	static int dx[]= {-1,0,1,0};
	static int dy[]= {0,1,0,-1};
	static int ans=0;
	static Stack<Integer> s=new Stack();
	static void bfs(int d[][],boolean c[][],int x,int y,int m,int n) {
		Queue<Pair2583> q=new LinkedList();
		q.add(new Pair2583(x,y));
		c[x][y]=true;
		int width=1;
		while(!q.isEmpty()) {
			Pair2583 p=q.poll();
			for(int i=0;i<4;i++) {
				int nx=p.x+dx[i];
				int ny=p.y+dy[i];
				if(0<=nx&&nx<m&&0<=ny&&ny<n) {
					if(d[nx][ny]==0&&c[nx][ny]==false) {
						q.add(new Pair2583(nx,ny));
						c[nx][ny]=true;
						width++;
					}
				}
			}
		}
		s.push(width);
		ans++;
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int m=sc.nextInt();
		int n=sc.nextInt();
		int k=sc.nextInt();
		int d[][]=new int[m][n];
		boolean c[][]=new boolean[m][n];
		for(int i=0;i<k;i++) {
			int x1=sc.nextInt();
			int y1=sc.nextInt();
			int x2=sc.nextInt();
			int y2=sc.nextInt();
			for(int j=x1;j<x2;j++) {
				for(int l=y1;l<y2;l++) {
					d[l][j]=1;
				}
			}
		}
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(d[i][j]==0&&c[i][j]==false) {
					bfs(d,c,i,j,m,n);
				}
			}
		}
		System.out.println(ans);
		int a[]=new int[ans];
		while(!s.isEmpty()) {
			for(int i=0;i<ans;i++) {
				a[i]=s.pop();
			}
		}
		Arrays.sort(a);
		for(int i:a) {
			System.out.print(i+" ");
		}
	}

}
class Pair2583{
	int x;
	int y;
	Pair2583(int x,int y){
		this.x=x;
		this.y=y;
	}
}

