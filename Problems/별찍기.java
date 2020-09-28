package ¹éÁØ;

import java.util.Scanner;

public class º°Âï±â {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int x= sc.nextInt();
		int count=0;
		for(int i=x;i>0;i--) {
			for(int k=0;k<count;k++) {
				System.out.print(" ");
			}
			for(int j=0;j<2*i-1;j++) {
				System.out.print("*");
			}
			System.out.println();
			count++;
		}

	}

}
