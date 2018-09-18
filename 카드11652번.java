package 백준;

import java.util.*;
public class 카드11652번 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int cnt=1;
		int ans=0;
		
		long a[]=new long[n];
		for(int i=0;i<n;i++) {
			long b=sc.nextLong();
			a[i]=b;
		}
		Arrays.sort(a);
		long bb=a[0];
		for(int i=0;i<n-1;i++) {
			if(a[i]==a[i+1]) {
				cnt++;
				if(cnt>ans) {
					ans=cnt;
					bb=a[i];
				}
			}
			else {
				cnt=1;
			}
			
		}
		System.out.println(bb);
	}

}
