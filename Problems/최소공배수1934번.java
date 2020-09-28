package 백준;

import java.util.*;
public class 최소공배수1934번 {
	public static int gcd(int a,int b) {
		if(b==0) {
			return a;
		}
		else {
			return gcd(b,a%b);
		}
	}
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		
		for(int i=0;i<n;i++) {
			int b=sc.nextInt();
			int c=sc.nextInt();
			a[i]=b*c/gcd(b,c);
		}
		for(int i=0;i<n;i++) {
			System.out.println(a[i]);
		}

	}

}
