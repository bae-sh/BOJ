package 백준;
import java.util.*;
public class 퇴사14501번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int t[]=new int[n+1];
		int p[]=new int[n+1];
		int dp[]=new int[n+2];//p의값
		for(int i=0;i<n;i++) {
			t[i+1]=sc.nextInt();
			p[i+1]=sc.nextInt();
		}
		for(int i=1;i<=n+1;i++) {
			for(int j=1;j<i;j++) {
				if(j+t[j]>i) {
					continue;
				}
				else {
					dp[i]=Math.max(dp[i], p[j]+dp[j]);
				}
			}
		}
		System.out.println(dp[n+1]);
	}

}
