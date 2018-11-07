package 백준;
import java.util.*;
public class 통계학2108번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int d[]=new int[n];
		int b[]=new int[8002];
		double a=0;
		int max=0;
		int ans=0;
		int cnt=1;
		for(int i=0;i<n;i++) {
			d[i]=sc.nextInt();
			a+=d[i];
			b[d[i]+4000]++;
		}
		a/=n;
		System.out.println(Math.round(a));
		Arrays.sort(d);
		System.out.println(d[n/2]);
		for(int i=0;i<=8001;i++) {
			if(b[i]>max) {
				max=b[i];
				ans=i-4000;
				cnt=1;
			}else if (b[i]==max&&cnt==1) {
				ans=i-4000;
				cnt++;
			}
		}
		System.out.println(ans);
		System.out.println(d[n-1]-d[0]);
		
	}

}
