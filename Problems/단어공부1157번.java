package 백준;

import java.util.*;
public class 단어공부1157번 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a=sc.nextLine();
		int d[]=new int[26];
		a=a.toUpperCase();
		int k=0;
		for(int i=0;i<a.length();i++) {
			d[a.charAt(i)-'A']++;
		}
		int Max=0;
		for(int i=1;i<26;i++) {
			if(d[Max]<d[i]) {
				Max=i;
				k=0;
			}
			else if(d[Max]==d[i]) {
				k=1;
			}
		}
		if(k==1) {
			System.out.println("?");
		}
		else {
		System.out.println((char)(Max+'A'));
		}
		
	}

}
