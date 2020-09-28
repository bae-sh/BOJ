package 백준;

import java.util.*;
public class 피보나치수3 {

	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long a[]=new long[1500001];
		a[0]=0;a[1]=1;a[2]=1;
		if(n==0)
			System.out.println(0);
		else if(n==1) {
			System.out.println(1);
		}else if(n==2)
			System.out.println(1);
		else {
			for(int i=3;i<=1500000;i++) {
				a[i]=a[i-1]+a[i-2];
			}
			System.out.println(a[1499999]);
		}
	}

}
