package 백준;
import java.util.*;
public class 타일채우기2718번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			if(a==1) {
				System.out.println(1);
				continue;
			}
			if(a==2) {
				System.out.println(5);
				continue;
			}
			int dp[]=new int[a+1];
			dp[1]=1;
			dp[2]=5;
			dp[3]=11;
			for(int j=4;j<=a;j++) {
				dp[j]=dp[j-1]+dp[j-2]*4+dp[j-3]*2;
			}
			System.out.println(dp[a]);
		}
	}

}
