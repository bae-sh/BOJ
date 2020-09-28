package 백준;

import java.util.*;
public class 골드바흐의추측6588번 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n[]=new int[1000001];
		for(int i=2;i<=1000000;i++) {
			n[i]=i;
		}
		for(int i=2;i<=1000000;i++) {
			if(n[i]==0) {
				continue;
			}
			for(int j=i;j<=1000000;j+=i) {
				if(j==i) {
					continue;
				}
				n[j]=0;
			}
		}
		while(true) {
			int a=sc.nextInt();
			for(int i=2;i<=a;i++) {
				if(n[i]!=0) {
					if(n[a-i]!=0) {
						System.out.println(a+" = "+n[i]+" + "+n[a-i]);
						break;
					}
				}
			}
			if(a==0) {
				break;
			}
		}

	}

}
