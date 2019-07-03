import java.util.*;
public class 파일합치기 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0) {
			int n=sc.nextInt();
			int d[]=new int[n+1];
			for(int i=1;i<=n;i++) {
				int a=sc.nextInt();
				d[i]=d[i-1]+a;
			}
			int dp[][]=new int[n][n];
			for(int i=1;i<n;i++) {
				for(int j=0;j+i<n;j++) {
					dp[j][j+i]=200000000;
					for(int k=0;k<i;k++) {
						dp[j][j+i]=Math.min(dp[j][j+k]+dp[j+k+1][j+i]+d[j+i+1]-d[j],dp[j][j+i]);
						
					}
				}
			}
			System.out.println(dp[0][n-1]);
			
		}
	}

}
