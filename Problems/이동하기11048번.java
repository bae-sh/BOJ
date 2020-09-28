package 백준;
import java.util.*;
public class 이동하기11048번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int dp[][]=new int[n+1][m+1];
		int a[][]=new int [n+1][m+1];
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				int s=sc.nextInt();
				a[i][j]=s;
			}
		}
		dp[1][1]=a[1][1];
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(i+1<=n) {
					dp[i+1][j]=Math.max(dp[i+1][j], dp[i][j]+a[i+1][j]);
				}
				if(j+1<=m) {
					dp[i][j+1]=Math.max(dp[i][j+1], dp[i][j]+a[i][j+1]);
				}
				if(i+1<=n&&j+1<=m) {
					dp[i+1][j+1]=Math.max(dp[i+1][j+1], dp[i][j]+a[i+1][j+1]);
				}
			}
		}
		System.out.println(dp[n][m]);
	}

}
