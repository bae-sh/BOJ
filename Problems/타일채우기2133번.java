package 백준;

import java.util.*;
public class 타일채우기2133번 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int d[]=new int [n+1];
		if(n>1)
		d[2]=3;
			for(int i=3;i<=n;i++) {
				if(i%2==0) {
					for(int j=2;j<i;j+=2) {
						if(j==2) {
							d[i]+=3*d[i-j];
						}
						else {
							d[i]+=2*d[i-j];
						}
					}
					d[i]+=2;
				}
			}
			System.out.println(d[n]);

	}

}
