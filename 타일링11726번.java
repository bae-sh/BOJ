package 백준;

import java.util.*;
import java.io.*;
public class 타일링11726번 {

	public static void main(String[] args)throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int d[]= new int[n+1];
		System.out.println(cal(n,d));
	}
	public static int cal(int n,int d[]) {
		if(n<=1) {
			d[n]=1;
			return d[n];
		}
		d[n]=(cal(n-1,d)+cal(n-2,d))%10007;
		return d[n];
	}
}
