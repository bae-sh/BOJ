package 백준;

import java.util.*;
import java.io.*;
public class 정수1로만들기1463번 {

	public static void main(String[] args)throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		
		int n=Integer.parseInt(br.readLine());
		int d[]=new int[n+1];
		System.out.println(cal(n,d));

	}
	public static int cal(int n,int d[]) {
		if(n<=1) {
			return 0;
		}
		else if(d[n]>0) {
			return d[n];
		}
		else {
			int temp;
			d[n]=cal(n-1,d)+1;
			if(n%3==0) {
				temp=cal(n/3,d)+1;
				d[n]=Math.min(d[n], temp);
			}
			if(n%2==0) {
				temp=cal(n/2,d)+1;
				d[n]=Math.min(d[n], temp);
			}
			return d[n];
		}
	}
	

}
