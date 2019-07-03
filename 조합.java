import java.math.BigInteger;
import java.util.Scanner;

public class 조합 {
    public static void main(String[] ar){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        BigInteger dp[][]=new BigInteger[n+1][n+1];
        BigInteger big=new BigInteger("1");
        dp[1][0]=dp[1][1]=big;
        for(int i=2;i<=n;i++) {
        	dp[i][0]=big;
        	dp[i][i]=big;
        }
        for(int i=2;i<=n;i++) {
        	for(int j=1;j<i;j++) {
        		dp[i][j]=dp[i-1][j-1].add(dp[i-1][j]);
        	}
        }
        System.out.println(dp[n][m]);

    }
}