import java.util.*;
import java.io.*;
public class 어두운건무서워 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s[]=br.readLine().split(" ");
		StringBuilder sb=new StringBuilder();
		int r=Integer.parseInt(s[0]);
		int c=Integer.parseInt(s[1]);
		int q=Integer.parseInt(s[2]);
		int d[][]=new int[r][c];
		int t[][]=new int[r][c];
		for(int i=0;i<r;i++) {
			s=br.readLine().split(" ");
			for(int j=0;j<c;j++) {
				d[i][j]=Integer.parseInt(s[j]);
				if(j==0) {
					t[i][j]=d[i][j];
				}else {
					t[i][j]=t[i][j-1]+d[i][j];
				}
			}
		}
		for(int k=0;k<q;k++) {

			s=br.readLine().split(" ");
			int r1=Integer.parseInt(s[0])-1;
			int c1=Integer.parseInt(s[1])-1;
			int r2=Integer.parseInt(s[2])-1;
			int c2=Integer.parseInt(s[3])-1;
			int ans=0;
			for(int i=r1;i<=r2;i++) {
				ans+=t[i][c2]-t[i][c1]+d[i][c1];
			}
			int cnt=(r2-r1+1)*(c2-c1+1);
			sb.append(ans/cnt+"\n");
		}
		System.out.println(sb.toString());
	}

}
