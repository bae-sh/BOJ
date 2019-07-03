import java.util.*;
import java.io.*;
public class 현수막 {
	static int[] dx= {-1,0,1,0,-1,1,1,-1};
	static int[] dy= {0,1,0,-1,1,1,-1,-1};
	static int ans=0;
	static void bfs(int x,int y,boolean c[][],int d[][],int m,int n) {
		Queue<Pair14716> q=new LinkedList();
		Pair14716 p=new Pair14716(x, y);
		c[x][y]=true;
		q.add(p);
		while(!q.isEmpty()) {
			p=q.poll();
			for(int i=0;i<8;i++) {
				int nx=p.x+dx[i];
				int ny=p.y+dy[i];
				if(0<=nx&&nx<m&&0<=ny&&ny<n) {
					if(d[nx][ny]==1&&c[nx][ny]==false) {
						c[nx][ny]=true;
						q.add(new Pair14716(nx, ny));
					}
				}
			}
			
		}
		ans++;
	}
	public static void main(String[] args) throws IOException{
		Scanner sc=new Scanner(System.in);
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s[]=br.readLine().split(" ");
		int m=Integer.parseInt(s[0]);
		int n=Integer.parseInt(s[1]);
		int d[][]=new int[m][n];
		boolean c[][]=new boolean[m][n];
		for(int i=0;i<m;i++) {
			s=br.readLine().split(" ");
			for(int j=0;j<n;j++) {
				d[i][j]=Integer.parseInt(s[j]);
			}
		}
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(c[i][j]==false&&d[i][j]==1) {
					bfs(i,j,c,d,m,n);
				}
			}
		}
		System.out.println(ans);
		
	}

}
class Pair14716{
	int x;
	int y;
	Pair14716(int x,int y){
		this.x=x;
		this.y=y;
	}
}
