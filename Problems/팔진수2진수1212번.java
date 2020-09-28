package 백준;

import java.util.*;
public class 팔진수2진수1212번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String x=sc.nextLine();
		Stack st = new Stack();
		for(int i=0;i<x.length();i++) {
			int a=x.charAt(i)-'0';
			if(i!=0&&a==1) {
				System.out.print("00");
			}
			else if(i!=0&&a==0) {
				System.out.print("000");
			}
			else if(i==0&&a==0) {
				System.out.print("0");
			}
			else if(i!=0&&a<4) {
				System.out.print("0");
			}
			while(a!=0) {
				st.push(a%2);
				a/=2;
			}
			while(!st.isEmpty()) {
				System.out.print(st.pop());
			}
		}
		

	}

}
