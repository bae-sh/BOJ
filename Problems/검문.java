import java.util.*;
public class 검문 {
	static int g;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		int b[]=new int[n-1];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		for(int i=0;i<n-1;i++) {
			b[i]=Math.abs(a[i+1]-a[i]);
		}
		if(n==2) {
			g=b[0];
		}else {
			g=gcd(b[0],b[1]);
			for(int i=1;i<n-1;i++) {
				g=gcd(g,b[i]);
			}
			
		}
		for(int i=2;i<=g/2;i++) {
			if(g%i==0) {
				System.out.print(i+" ");
			}
		}
		System.out.print(g);
	}
	static int gcd(int a,int b) {
		if(b==0)
			return a;
		else
			return gcd(b,a%b);
	}
}
