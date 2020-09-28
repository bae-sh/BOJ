package 백준;

import java.util.*;
public class 소수구하기1929번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n[]=new int[1000001];
		int a=sc.nextInt();
		int b=sc.nextInt();
		for(int i=2;i<=b;i++) {
			n[i]=i;
		}
		for(int i=2;i<=b;i++) {
			if(n[i]==0) {
				continue;
			}
			for(int j=i;j<=b;j+=i) {
				if(j==i) {
					continue;
				}
				n[j]=0;
			}
			if(i>=a) {
			System.out.println(i);
			}
		}

	}

}
