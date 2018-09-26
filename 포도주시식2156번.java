package 백준;

import java.util.*;
import java.io.*;
public class 포도주시식2156번 {

	public static void main(String[] args)throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int po[]=new int[n+1];
		int x[][]=new int[n+1][3];
		for(int i=1;i<=n;i++) {
			po[i]=Integer.parseInt(br.readLine());
		}
		x[1][0]=0;
		x[1][1]=po[1];
		if(n>1) {
		x[2][0]=x[1][1];
		x[2][1]=po[2];
		x[2][2]=po[1]+po[2];}
		for(int i=3;i<=n;i++) {
			x[i][0]=Math.max(x[i-1][0], Math.max(x[i-1][1], x[i-1][2]));
			x[i][1]=x[i-1][0]+po[i];
			x[i][2]=x[i-1][1]+po[i];
		}
		if(n==1) {
			System.out.println(x[1][1]);
		}
		else
		System.out.println(Math.max(x[n][0], Math.max(x[n][1], x[n][2])));
		}
		
	}


