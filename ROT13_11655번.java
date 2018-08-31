package 백준;

import java.util.*;

public class ROT13_11655번 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		String x=sc.nextLine();
		for(int i=0;i<x.length();i++) {
			char c=x.charAt(i);
			if((c>='a'&&c<='z')) {
				if((int)c+13>'z') {
					int a=c-13;
					char b=(char)a;
					System.out.print(b);
				}
				else {
					int a=c+13;
					char b=(char)a;
					System.out.print(b);
				}
			}
			else if((c>='A'&&c<='Z')) {
				if((int)c+13>'Z') {
					int a=c-13;
					char b=(char)a;
					System.out.print(b);
				}
				else {
					int a=c+13;
					char b=(char)a;
					System.out.print(b);
				}
			}
			else {
				System.out.print(c);
			}
		}
	}

}
