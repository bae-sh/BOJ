package 백준;
import java.util.*;
public class 이차원배열의합2167번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int d[][]=new int[a+1][b+1];
		int dp[][]=new int[a+1][b+1];
		for(int i=1;i<=a;i++) {
			for(int j=1;j<=b;j++) {
				d[i][j]=sc.nextInt();
			}
		}
		for(int i=1;i<=b;i++) {
			for(int j=1;j<=a;j++) {
				if(j==1) {
				dp[j][i]=dp[a][i-1]+d[j][i];
					}
				else {
					dp[j][i]=dp[j-1][i]+d[j][i];
				}
			}
		}
		int k=sc.nextInt();
		for(int i=0;i<k;i++) {
			int ans=0;
			int a1=sc.nextInt();
			int b1=sc.nextInt();
			int a2=sc.nextInt();
			int b2=sc.nextInt();
			for(int j=a1;j<=a2;j++) {
				for(int q=b1;q<=b2;q++) {
					ans+=d[j][q];
				}
				
			}
			System.out.println(ans);
		}
	}

}
