import java.util.*;
public class 헨리 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0) {
			long a=sc.nextInt();
			long b=sc.nextInt();
			
			long k=2;
			while(true) {
				long d=1;
				if(k*a>=b) {
					long c=b*k/gcd(b,k);
					a*=c/b;
					b=c;
					d=c/k;
					a=a-d;
					if(a==0) {
						System.out.println(k);
						break;
					}
				}
				k=(b-1)/a+1;
			}
		}
	}
	public static long gcd(long a,long b) {
		if(b==0)
			return a;
		else
			return gcd(b,a%b);
	}
}
