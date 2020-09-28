package 백준;

import java.util.*;
public class 이진수8진수1373번 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		String a=sc.nextLine();
		int n=a.length();
		int sum=0;
		if(n%3==1) {
			System.out.print(a.charAt(0)-'0');
		}
		else if(n%3==2) {
			System.out.print((a.charAt(0)-'0')*2+(a.charAt(1)-'0'));
		}
		for(int i=n%3;i<a.length();i=i+3) {
			System.out.print((a.charAt(i)-'0')*4+(a.charAt(i+1)-'0')*2+(a.charAt(i+2)-'0'));
		}

	}

}
