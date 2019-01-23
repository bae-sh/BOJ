package 백준;
import java.util.*;
public class 이항계수2_11051번 {
	public static void main(String[] args) {
		Scanner sc=new Scanner (System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		int dp[][]=new int[1001][1001];
		for(int i=0;i<=1000;i++) {
			dp[i][0]=1;
			dp[i][1]=i;
			dp[i][i]=1;
		}
		for(int i=2;i<=1000;i++) {
			for(int j=2;j<i;j++) {
				dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%10007;
			}
		}
		System.out.println(dp[n][k]);
	}

}
