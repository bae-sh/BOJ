package 백준;
import java.util.*;
public class 다리놓기1010번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			int b=sc.nextInt();
			int ans=0;
			int dp[][]=new int[a+1][b+1];
			for(int j=1;j<=b;j++) {
				dp[1][j]=1;
			}
			for(int j=2;j<=a;j++) {
				for(int k=j;k<=b;k++) {
					for(int l=1;l<k;l++) {
					dp[j][k]+=dp[j-1][l];
					}
				}
				
			}
			for(int j=1;j<=b;j++) {
				ans+=dp[a][j];
			}
			System.out.println(ans);
			
		}
	}

}
