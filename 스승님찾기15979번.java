package 백준;
import java.util.*;
public class 스승님찾기15979번 {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		a=Math.abs(a);
		int b=sc.nextInt();
		b=Math.abs(b);
		int c=Math.max(a, b);
		int dp[][]=new int[c+1][c+1];
		dp[0][0]=0;
		for(int i=1;i<=c;i++) {
			dp[i][i]=dp[i-1][i-1]+1;
			for(int j=i;j<=c;j++) {
				dp[j][i-1]=dp[j-1][i-1]+1;
				dp[i-1][j]=dp[i-1][j-1]+1;
				}
			}
		for(int i=0;i<=c;i++) {
			int p=0;
			for(int j=i+1;j<=c;j++) {//y축
				p++;
				for(int l=j+1;l<=c;l++) {//x축
					if(l%p!=0) {
						dp[j][l]=Math.min(dp[i][i]+1, dp[j][l]);
						dp[l][j]=dp[j][l];
					}
					else {
						dp[j][l]=dp[i][i]+1;
						dp[l][j]=dp[j][l];
					}
				}
			}
			
		}
		System.out.println(dp[a][b]);
		
	}

}
