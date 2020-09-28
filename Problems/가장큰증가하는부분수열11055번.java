package 백준;

import java.util.*;
public class 가장큰증가하는부분수열11055번 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int [n+1];
		int d[]=new int[n+1];
		for(int i=1;i<=n;i++) {
			a[i]=sc.nextInt();
		}
		
		d[1]=a[1];
		for(int i=2;i<=n;i++) {
			d[i]=a[i];
			for(int j=1;j<=n;j++) {
				if(a[i]>a[j]&&d[i]<d[j]+a[i]) {
					d[i]=d[j]+a[i];
				}
			}
		}
		int Max=d[1];
		for(int i=2;i<=n;i++) {
			if(Max<d[i]) {
				Max=d[i];
			}
		}
		System.out.println(Max);
	}

}
