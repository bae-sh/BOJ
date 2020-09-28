package 백준;

import java.util.*;
	
public class 팩토리얼10872 {
	public static long fac(long a) {
		if(a==0) {
			return 1;
		}
		else {
			return fac(a-1)*a;
		}
	}
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		long n=sc.nextLong();
		System.out.println(fac(n));

	}

}

