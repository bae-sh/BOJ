package 백준;
import java.util.*;
import java.io.*;
public class 정수삼각형1932번 {

	public static void main(String[] args)throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int Max=0;
		int [][]dp=new int[n+1][n+1];
		for(int i=1;i<=n;i++) {
			int d[]=new int[i+1];
			String s[]=br.readLine().split(" ");
			if(i==1) {
				dp[1][1]=Integer.parseInt(s[0]);
				Max=dp[1][1];
				continue;
			}
			for(int j=1;j<=s.length;j++) {
				dp[i][j]=Math.max(dp[i-1][j-1]+Integer.parseInt(s[j-1]), dp[i-1][j]+Integer.parseInt(s[j-1]));

				if(i==n) {
					Max=Math.max(Max, dp[n][j]);
				}
			}
			
		}
		System.out.println(Max);
	}

}
