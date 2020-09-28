package 백준;
import java.util.*;

public class 스승님찾기2 {
	public static int gcd(int p, int q)
	   {
	    if (q == 0) return p;
	    return gcd(q, p%q);
	   }
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		a=Math.abs(a);
		int b=sc.nextInt();
		b=Math.abs(b);
		if(a==0&&b==0) {
			System.out.println(0);
		}
		else {
		int p=gcd(a,b);
		int aa=a/p;
		if(a==0) {
			System.out.println(b);
		}
		else if(b==0) {
			System.out.println(a);
		}
		else {
		System.out.println(a/aa);
		}
		}
	}

}
