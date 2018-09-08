package 백준;

import java.util.*;
public class 제곱수의합1699번 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		long d[]=new long[n+1];
		
		for(int i=1;i<=n;i++) {
			d[i]=i;
			for(int j=1;j*j<=i;j++) {
				if(i-j*j>=0)
				d[i]=Math.min(d[i], d[i-j*j]+1);
			}
	
		}
		System.out.println(d[n]);
	}

}
