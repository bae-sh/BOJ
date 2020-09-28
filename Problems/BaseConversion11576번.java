package 백준;

import java.util.*;
public class BaseConversion11576번 {
	public static void go(int b,int n) {
		if(n==0) {
			return;
		}
		go(b,n/b);
		System.out.print(n%b+" ");
	}
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int n=sc.nextInt();
		int ten=0;
		
		for(int i=0;i<n;i++) {
			int x=sc.nextInt();
			ten+=Math.pow(a, n-i-1)*x;
		}
		go(b,ten);

	}

}
