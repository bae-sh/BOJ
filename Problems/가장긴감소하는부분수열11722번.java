package 백준;

import java.util.*;
public class 가장긴감소하는부분수열11722번 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n+1];
		int d[]=new int[n+1];
		
		for(int i=n;i>=1;i--) {
			a[i]=sc.nextInt();
		}
		
		for(int i=1;i<=n;i++) {
			d[i]=1;
			for(int j=1;j<i;j++) {
				if(a[i]>a[j]&&d[i]<d[j]+1) {
					d[i]=d[j]+1;
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
