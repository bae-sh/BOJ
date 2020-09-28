package 백준;

import java.util.*;
public class 소수찾기1978번 {
	static int res=0;
	public static void go(int a) {
		if(a==1) {
			return;
		}
		for(int i=2;i*i<=a;i++) {
			if(a%i==0&&a!=i) {
				return;
			}
		}
		res++;
	}
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			go(a);
		}
		System.out.println(res);

	}

}
