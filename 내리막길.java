import java.util.*;
import java.io.*;
public class 내리막길 {
	static int dx[]= {-1,0,1,0};
	static int dy[]= {0,1,0,-1};
	static int ans=0;
	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s[]=br.readLine().split(" ");
		int m=Integer.parseInt(s[0]);
		int n=Integer.parseInt(s[1]);
		int c[][]=new int[m][n];
		int d[][]=new int[m][n];
		for(int i=0;i<m;i++) {
			s=br.readLine().split(" ");
			for(int j=0;j<n;j++) {
				d[i][j]=Integer.parseInt(s[j]);
			}
		}
		for(int i=0;i<m;i++) {
			Arrays.fill(c[i], -1);
		}
		dfs(d,0,0,c,m,n);
		System.out.println(c[0][0]);
		
		
	}
	 public static int dfs(int d[][],int x,int y,int c[][],int m,int n) {
	        if (x==m-1&&y==n-1) {
	        	return 1;
	        }else if(c[x][y]!=-1){
	        	return c[x][y];
	        }else {
	        	int temp=0;
	        	for(int i=0;i<4;i++) {
	        		int nx=x+dx[i];
	        		int ny=y+dy[i];
	        		if(0<=nx&&nx<m&&0<=ny&&ny<n&&d[nx][ny]<d[x][y]) {
	        			temp+=dfs(d,nx,ny,c,m,n);
	        		}
	        	}
	        	return c[x][y]=temp;
	        }
	    }
}
