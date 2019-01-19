package 백준;
import java.util.*;
public class 떡먹는호랑이2502번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int d=sc.nextInt();
		int k=sc.nextInt();
		for(int i=1;i<=100000;i++) {
			int dp[]=new int[31];
			dp[1]=i;
			for(int o=1;o<=100000;o++) {
				dp[2]=o;
				for(int j=3;j<=31;j++) {
					dp[j]=dp[j-1]+dp[j-2];
					if(j==d) {
						if(k==dp[j]) {
							System.out.println(dp[1]+"\n"+dp[2]);
							System.exit(0);
						}
						else {
							break;
						}
					}
					if(dp[j]>=k||j>d) {
						break;
					}
				}
			}
		}
	}

}
