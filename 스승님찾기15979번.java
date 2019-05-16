package 백준;
import java.util.*;
public class 스승님찾기15979번 {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int m=sc.nextInt();
		int n=sc.nextInt();
		m=Math.abs(m);
		n=Math.abs(n);
		if(m==0&&n==0)
			System.out.println(0);
		else if(gcd(m,n)==1) 
			System.out.println(1);
		else 
			System.out.println(2);
	}
	public static int gcd(int i,int j) {
		if(j==0) 
			return i;
		else 
			return gcd(j,i%j);
	}
}
