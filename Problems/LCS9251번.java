package 백준;
import java.util.*;
public class LCS9251번 {
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a=sc.nextLine();
		String b=sc.nextLine();
		int dp[][]=new int[a.length()+2][b.length()+2];
		
		for(int i=1;i<=a.length();i++) {
			for(int j=1;j<=b.length();j++) {
				if(a.charAt(i-1)==b.charAt(j-1)) {
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else {
					dp[i][j]=Math.max(dp[i][j-1], dp[i-1][j]);
				}
			}
		}
		System.out.println(dp[a.length()][b.length()]);
	}
}
