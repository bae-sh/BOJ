import java.util.*;
import java.io.*;
public class 체스판다시칠하기 {
	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String t[]=br.readLine().split(" ");
		int n=Integer.parseInt(t[0]);
		int m=Integer.parseInt(t[1]);
		String s[][]=new String[n][m];
		int ans=1000000000;
		
		for(int i=0;i<n;i++) {
			t=br.readLine().split("");
			for(int j=0;j<m;j++) {
				s[i][j]=t[j];
			}
		}
		for(int i=0;i<n-7;i++) {
			for(int j=0;j<m-7;j++) {
				ans=Math.min(ans, Math.min(p(s,i,j,0), p(s,i,j,1)));
			}
		}
		System.out.println(ans);
	}
	static int p(String s[][],int x,int y,int z) {
		int ans=0;
		for(int i=0;i<8;i++) {
			for(int j=0;j<8;j++) {
				if((x+y+i+j+z)%2==0&&!s[x+i][y+j].equals("B")) {
					ans++;
				}else if((x+y+i+j+z)%2!=0&&!s[x+i][y+j].equals("W")) {
					ans++;
				}
			}
		}
		return ans;
	}
	
}
