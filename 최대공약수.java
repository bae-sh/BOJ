import java.util.*;
public class 최대공약수 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		StringBuilder sb=new StringBuilder();
		long a=sc.nextLong();
		long b=sc.nextLong();
		long c=gcd(a,b);
		for(int i=0;i<c;i++) {
			sb.append(1);
		}
		System.out.println(sb.toString());
	}
	public static long gcd(long a,long b) {
		if(b==0)
			return a;
		else
			return gcd(b,a%b);
	}
}
