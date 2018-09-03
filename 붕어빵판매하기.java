package 백준;

import java.util.*;
public class 붕어빵판매하기 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int x[]=new int[n+1];
		int d[]=new int[n+1];
		
		
		for(int i=1;i<=n;i++) {
			x[i]=sc.nextInt();
		}
		for(int i=1;i<n+1;i++) {
			for(int j=0;j<=i;j++) {
				d[i]=Math.max(d[i-j]+x[j],d[i]);
			}
		}
		System.out.println(d[n]);
	}

}
