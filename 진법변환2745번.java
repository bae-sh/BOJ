package 백준;

import java.util.*;
public class 진법변환2745번 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		String a=sc.next();
		int n=sc.nextInt();
		long sum=0;
		for(int i=0;i<a.length();i++) {
			int x;
			if(a.charAt(i)>='A') {
				 x=a.charAt(i)-'A'+10;}
			else {
				x=a.charAt(i)-'0';
			}
				sum+=Math.pow(n, a.length()-i-1)*x;
			
		}
		System.out.println(sum);

	}

}
