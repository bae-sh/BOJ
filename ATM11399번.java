package 백준;
import java.util.*;
public class ATM11399번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int dp[]=new int[n];
		int d[]=new int[n];
		int ans=0;
		for(int i=0;i<n;i++) {
			dp[i]=sc.nextInt();
		}
		Arrays.sort(dp);
		for(int i=0;i<n;i++) {
			for(int j=i;j<n;j++) {
				d[j]+=dp[i];
			}
			ans+=d[i];
		}
		System.out.println(ans);
	}

}
