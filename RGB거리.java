package 백준;

import java.util.*;
import java.io.*;
public class RGB거리 {

	public static void main(String[] args)throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int d[][]=new int[n+1][3];
		int ant[][]=new int[n+1][3];
		int count=1;
		for(int i=1;i<=n;i++) {
			String a[]=br.readLine().split(" ");
			d[i][0]=Integer.parseInt(a[0]);
			d[i][1]=Integer.parseInt(a[1]);
			d[i][2]=Integer.parseInt(a[2]);
		}
		ant[1][0]=d[1][0];
		ant[1][1]=d[1][1];
		ant[1][2]=d[1][2];
		for(int i=2;i<=n;i++) {
			for(int j=0;j<3;j++) {
				ant[i][j]=Math.min(ant[i-1][(j+1)%3], ant[i-1][(j+2)%3])+d[i][j];
			}
		}
		System.out.println(Math.min(ant[n][0], Math.min(ant[n][1], ant[n][2])));
	}

}

