import java.util.*;
public class LCS2 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String s1=sc.nextLine();
		String s2=sc.nextLine();
		String dp[][]=new String[s2.length()+1][s1.length()+1];
		for(int i=0;i<s2.length()+1;i++) {
			for(int j=0;j<s1.length()+1;j++) {
				dp[i][j]="";
			}
		}
		for(int i=0;i<s2.length();i++) {
			for(int j=0;j<s1.length();j++) {
				if(s1.charAt(j)==s2.charAt(i)) {
					char c=s1.charAt(j);
					dp[i+1][j+1]=dp[i][j]+c;
				}else {
					dp[i+1][j+1]=dp[i][j+1].length()>dp[i+1][j].length() ? dp[i][j+1]:dp[i+1][j];
				}
			}
		}
		System.out.println(dp[s2.length()][s1.length()].length());
		System.out.println(dp[s2.length()][s1.length()]);
	}

}
