package 백준;

import java.util.*;
public class 스티커9465번 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int sum=0;
		
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			int d[][] = new int[a+1][3];
			int b[] = new int[a*2];
			for(int j=0;j<a*2;j++) {
				b[j]=sc.nextInt();
			}
			d[1][0]=0;
			d[1][1]=b[0];
			d[1][2]=b[a];
			for(int j=2;j<a+1;j++) {
				int max;
				if(d[j-1][0]>=d[j-1][1]) {
					max=d[j-1][0];
				}
				else {
					max=d[j-1][1];
				}
				if(max<d[j-1][2]) {
					max=d[j-1][2];
				}
				d[j][0]=max;
				d[j][1]=Math.max(d[j-1][0], d[j-1][2])+b[j-1];
				d[j][2]=Math.max(d[j-1][0], d[j-1][1])+b[j+a-1];
				
			}
			int Max;
			if(d[a][0]>=d[a][1]) {
				Max=d[a][0];
			}
			else {
				Max=d[a][1];
			}
			if(Max<d[a][2]) {
				Max=d[a][2];
			}
			System.out.println(Max);
		}

	}

}
