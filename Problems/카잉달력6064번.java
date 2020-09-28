package 백준;
import java.util.*;
public class 카잉달력6064번 {
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		StringBuilder sb=new StringBuilder();
		while(t-->0) {
			int m=sc.nextInt();
			int n=sc.nextInt();
			int x=sc.nextInt();
			int y=sc.nextInt();
			int g=m*n/gcd(m,n);
			int ans=-1;
			if(n==y) y=0;
			for(int i=x;i<=g;i+=m) {
				if(i%n==y) {
					ans=i;
					break;
				}
			}
			sb.append(ans+"\n");
		}
		System.out.println(sb.toString());
	}
	public static int gcd(int a,int b) {
		while(b!=0) {
			int r=a%b;
			a=b;
			b=r;
		}
		return a;
	}
}
