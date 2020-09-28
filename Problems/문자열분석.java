package 백준;

import java.util.*;
import java.io.*;
public class 문자열분석 {

	public static void main(String[] args)throws IOException {
		Scanner sc = new Scanner(System.in);
		
		
		while(sc.hasNext()) {
			int a=0;
			int b=0;
			int c=0;
			int d=0;
			String x=sc.nextLine();
			for(int i=0;i<x.length();i++) {
				char k=x.charAt(i);
				if(k>='A'&&k<='Z') {
					a++;
				}
				else if(k>='a'&&k<='z') {
					b++;
				}
				else if(k==' ') {
					c++;
				}
				else if(k>='0'&&k<='9') {
					d++;
				}
			}
			System.out.println(b+" "+a+" "+d+" "+c);
		}
	}

}
