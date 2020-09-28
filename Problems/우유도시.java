import java.util.*;
import java.io.*;
public class 우유도시 {
	static int ans=0;
	static void bfs(int d[][],int c[][],int n) {
		if(d[0][0]==0) {
			c[0][0]=1;
		}
		Queue<Pair14722> q=new LinkedList();
		q.add(new Pair14722(0, 0));
		while(!q.isEmpty()) {
			Pair14722 p= q.poll();
			if(p.x+1<n) {
				if(d[p.x+1][p.y]==(c[p.x][p.y])%3) {
					if(c[p.x+1][p.y]<c[p.x][p.y]+1) {
						c[p.x+1][p.y]=c[p.x][p.y]+1;
						ans=Math.max(ans, c[p.x+1][p.y]);
						q.add(new Pair14722(p.x+1,p.y));
					}
				}else {
					if(c[p.x+1][p.y]<c[p.x][p.y]+1) {
						c[p.x+1][p.y]=c[p.x][p.y];
						q.add(new Pair14722(p.x+1,p.y));
					}
				}
			}
			if(p.y+1<n) {
				if(d[p.x][p.y+1]==(c[p.x][p.y])%3) {
					if(c[p.x][p.y+1]<c[p.x][p.y]+1) {
						c[p.x][p.y+1]=c[p.x][p.y]+1;
						ans=Math.max(ans, c[p.x][p.y+1]);
						q.add(new Pair14722(p.x,p.y+1));
					}
				}else {
					if(c[p.x][p.y+1]<c[p.x][p.y]+1) {
						c[p.x][p.y+1]=c[p.x][p.y];
						q.add(new Pair14722(p.x,p.y+1));
					}
				}
			}
		}
	}
	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int d[][]=new int[n][n];
		int c[][]=new int[n][n];
		for(int i=0;i<n;i++) {
			String s[]=br.readLine().split(" ");
			for(int j=0;j<n;j++) {
				d[i][j]=Integer.parseInt(s[j]);
			}
		}
		bfs(d,c,n);
		System.out.println(ans);
	}

}
class Pair14722{
	int x;
	int y;
	public Pair14722(int x,int y) {
		this.x=x;
		this.y=y;
	}
}
