package 백준;

import java.util.*;
public class GCD합9613번 {
	public static int gcd(int a,int b) {
		if(b==0) {
			return a;
		}
		else {
			return gcd(b,a%b);
		}
	}
	public static void main(String[] args){
		Scanner sc =new Scanner(System.in);
		int n=sc.nextInt();
		int d[]=new int[100];
		for(int i=0;i<n;i++) {
			int k=sc.nextInt();
			long gcd=0;
			for(int j=0;j<k;j++) {
				d[j]=sc.nextInt();
			}
			for(int j=0;j<k-1;j++) {
				for(int l=j+1;l<k;l++) {
					gcd+=gcd(d[j],d[l]);
				}
			}
			System.out.println(gcd);
		}
		
		

	}

}
