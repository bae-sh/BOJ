package 백준;

import java.util.Scanner;

public class 상근날드5543번 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x[] = new int[3];
		int y[] = new int[2];
		for(int i=0;i<3;i++) {
			x[i]=sc.nextInt();
		}
		for(int i =0;i<2;i++) {
			y[i]=sc.nextInt();
		}
		for(int i=0;i<3;i++) {
			for(int j=0;j<2;j++) {
				if(x[j]>x[j+1]) {
					x[j]=x[j+1];
				}
			}
		}
		if(y[0]<y[1]) {
			y[1]=y[0];
		}
		System.out.println(x[0]+y[1]-50);
	}

}
