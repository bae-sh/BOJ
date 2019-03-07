package 백준;

import java.util.*;

public class 합분해2225번 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		long d[][] = new long[n + 1][k + 1];
		for (int i = 0; i <= n; i++) {
			d[i][1] = 1;
		}
		for(int i=1;i<=k;i++) {
			d[0][i]=1;
		}
		for(int i=1;i<=n;i++) {
			for(int j=2;j<=k;j++) {
				for(int l=0;l<=j;l++) {
					d[i][j]+=d[i-1][j-l];
					d[i][j]%=1000000000;
				}
			}
		}
		System.out.println(d[n][k] % 1000000000);
	}

}
