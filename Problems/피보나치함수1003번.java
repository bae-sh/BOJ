package 백준;

import java.util.*;
import java.io.*;
public class 피보나치함수1003번 {
	static int zero=0;
	static int one=0;
	public static void main(String[] args)throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int f[][]=new int[41][2];
		f[0][0]=1;
		f[0][1]=0;
		f[1][0]=0;
		f[1][1]=1;
		for(int i=2;i<41;i++) {
			f[i][0]=f[i-1][0]+f[i-2][0];
			f[i][1]=f[i-1][1]+f[i-2][1];
		}
		for(int i=0;i<n;i++) {
			int a=Integer.parseInt(br.readLine());
			System.out.println(f[a][0]+" "+f[a][1]);
		}
		
	}
}
