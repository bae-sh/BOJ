package 백준;

import java.util.*;
public class 연속합1912번 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n+1];
		int d[]=new int[n+1];
		for(int i=1;i<=n;i++) {
			a[i]=sc.nextInt();
		}
		
		d[1]=a[1];
		for(int i=2;i<=n;i++) {
			if(d[i-1]+a[i]>a[i]) {
				d[i]=d[i-1]+a[i];
			}
			else {
				d[i]=a[i];
			}
		}
		int Max=d[1];
		for(int i=1;i<=n;i++) {
			if(Max<d[i]) {
				Max=d[i];
			}
		}
		System.out.println(Max);
	}

}
