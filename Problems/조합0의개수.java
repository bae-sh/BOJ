package 백준;

import java.util.*;
public class 조합0의개수 {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		long two=0;
		long five=0;

		for(long i=2;i<=a;i*=2) {
			if(i<=a-b) {
				two+=a/i-b/i-(a-b)/i;
			}
			else if(i<=b) {
				two+=a/i-b/i;
			}
			else
			two+=a/i;
		}
		for(long i=5;i<=a;i*=5) {
			if(i<=a-b) {
				five+=a/i-b/i-(a-b)/i;;
			}
			else if(i<=b) {
				five+=a/i-b/i;
			}
			else
			five+=a/i;
		}
		System.out.println(Math.min(two, five));
		
	}

}
