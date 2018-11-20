package 백준;
import java.util.*;
public class 경비원2564번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int n=sc.nextInt();
		P[] pair=new P[n+1];
		int ans=0;
		for(int i=0;i<n+1;i++) {
			pair[i]=new P();
		}
		for(int i=0;i<=n;i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			pair[i].n=x;
			if(x==1) {
				pair[i].x=y;
				pair[i].y=0;
			}else if(x==2) {
				pair[i].x=y;
				pair[i].y=b;
			}else if(x==3) {
				pair[i].x=0;
				pair[i].y=y;
			}else {
				pair[i].x=a;
				pair[i].y=y;
			}
		}
		for(int i=0;i<n;i++) {
			if(Math.abs(pair[i].x-pair[n].x)!=a&&Math.abs(pair[i].y-pair[n].y)!=b) {
				ans+=Math.abs(pair[i].x-pair[n].x)+Math.abs(pair[i].y-pair[n].y);
			}else if(pair[i].n==1||pair[i].n==2) {
				ans+=Math.min(pair[i].x+pair[n].x+b, 2*a-pair[i].x-pair[n].x+b);
			}else {
				ans+=Math.min(pair[i].y+pair[n].y+a, 2*b-pair[i].y-pair[n].y+a);
			}
			
		}
		System.out.println(ans);
		
	}

}
class P{
	int x;
	int y;
	int n;
}
