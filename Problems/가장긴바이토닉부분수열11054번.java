package 백준;

import java.util.*;
public class 가장긴바이토닉부분수열11054번 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n+1];
		int a2[]=new int[n+1];
		int d[]=new int[n+1];
		int d2[]=new int[n+1];
		for(int i=1;i<=n;i++) {
			a[i]=sc.nextInt();
			
		}
		for(int i=1;i<=n;i++) {
			a2[i]=a[n-i+1];
		}
		for(int i=1;i<=n;i++) {
			d[i]=1;
			d2[i]=1;
			for(int j=1;j<i;j++) {
				if(a[i]>a[j]&&d[i]<d[j]+1) {
					d[i]=d[j]+1;
				}
				if(a2[i]>a2[j]&&d2[i]<d2[j]+1) {
					d2[i]=d2[j]+1;
				}
			}
			
		}
		int Max=d[1]+d2[1]-1;
		for(int i=2;i<=n;i++) {
			if(Max<d[i]+d2[n-i+1]-1) {
				Max=d[i]+d2[n-i+1]-1;
			}
		}
		System.out.println(Max);
	}

}
