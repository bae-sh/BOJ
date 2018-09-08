package 백준;

import java.util.*;
import java.io.*;
public class 쉬운계단수 {

	public static void main(String[] args)throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		long d[][]= new long[n+1][10];
		long sum=0;
		for(int i=1;i<=9;i++) {
			d[1][i]=1;
		}
		for(int i=2;i<n+1;i++) {
			for(int j=0;j<10;j++) {
				if(j==0) {
					d[i][j]=(d[i-1][j+1]);
				}
				else if(j==9) {
					d[i][j]=(d[i-1][j-1]);
				}
				else {
					d[i][j]=d[i-1][j-1]+d[i-1][j+1];
				}
				d[i][j]%=1000000000;
			}
		}
		for(int i=0;i<10;i++) {
			sum+=d[n][i];
		}
		System.out.println(sum%1000000000);

	}

}
