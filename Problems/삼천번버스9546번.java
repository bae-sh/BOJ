package 백준;
import java.util.*;
public class 삼천번버스9546번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int dp[]=new int[31];
		for(int i=1;i<=30;i++) {
			dp[i]=2*dp[i-1]+1;
		}
		int t=sc.nextInt();
		for(int i=0;i<t;i++) {
			int a=sc.nextInt();
			System.out.println(dp[a]);
		}
	}

}
