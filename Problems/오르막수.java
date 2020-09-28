package 백준;

import java.util.*;
public class 오르막수 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		long sum=0;
		long d[][]=new long[n+1][10];
		
		for(int i=0;i<10;i++) {
			d[1][i]=1;
		}
		
		for(int i=2;i<=n;i++) {
			for(int j=0;j<10;j++) {
				for(int k=0;k<=j;k++) {
					d[i][j]+=d[i-1][k];
				}
				d[i][j]%=10007;
			}
		}
		for(int i=0;i<10;i++) {
			sum+=d[n][i];
		}
		System.out.println(sum%10007);
	}

}
