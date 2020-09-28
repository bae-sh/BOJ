package 백준;
import java.util.*;
public class 토너먼트1057번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n+1];
		int x=sc.nextInt();
		int y=sc.nextInt();
		a[x]=-1;
		a[y]=-1;
		int cnt=0;
		while(true) {
			cnt++;
		for(int i=1;i<=n;i+=2) {
			if(i+1>n) {
				a[i/2+1]=a[i];
				a[i]=0;
				break;
			}
			if(a[i]==-1&&a[i+1]==-1) {
				System.out.println(cnt);
				System.exit(0);
			}
			if(i==1) {
				if(a[i+1]==-1) {
					a[i]=-1;
					a[i+1]=0;
				}
				continue;
			}
			if(a[i]==-1) {
				a[i/2+1]=a[i];
				a[i]=0;
			}else if(a[i+1]==-1) {
				a[i/2+1]=a[i+1];
				a[i+1]=0;
			}
			}
		
		if(n%2==0) {
			n/=2;
		}else {
			n/=2;
			n++;
		}
		}
		
	}

}
