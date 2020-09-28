package 백준;

import java.util.Scanner;

public class 소수구하기1929 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		
		for(int i=m;i<=n;i++) {
			for(int j=2;j<i;j++) {
				if(i%j==0) {
					break;
				}
				if(j==i-1) {
					if(i%j!=0) {
						System.out.println(i);
					}
				}
			}
		}

	}

}
