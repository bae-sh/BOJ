package 백준;
import java.util.*;
public class 동전1 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		int dp[]=new int[k+1];
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		for(int i=1;i<=k;i++) {
			for(int j:a) {
				if(i-j>0) {
					continue;
				}
			}
		
		}
		System.out.println(dp[k]);
	}

}
