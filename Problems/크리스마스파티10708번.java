package 백준;
import java.util.*;
public class 크리스마스파티10708번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int a[]=new int[m];
		int d[]=new int[n+1];
		
		for(int i=0;i<m;i++) {
			a[i]=sc.nextInt();
		}
		
		for(int i=0;i<m;i++) {
			int cnt=0;
			for(int j=1;j<=n;j++) {
				int s=sc.nextInt();
				if(s==a[i]) {
					d[j]++;
				}else {
					cnt++;
				}
			}
			d[a[i]]+=cnt;
		}
		for(int i=1;i<=n;i++) {
			System.out.println(d[i]);
		}
	}

}
