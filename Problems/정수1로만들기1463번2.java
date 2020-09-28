package 백준;

import java.util.*;
import java.io.*;
public class 정수1로만들기1463번2 {
	//bottom up
	public static void main(String[] args)throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int d[]=new int[n+1];
		for(int i=2;i<n+1;i++) {
			int temp;
			d[i]=d[i-1]+1;
			if(i%2==0) {
				temp=d[i/2]+1;
				d[i]=Math.min(d[i], temp);
			}
			if(i%3==0) {
				temp=d[i/3]+1;
				d[i]=Math.min(d[i], temp);
			}
		}
		System.out.println(d[n]);
	}

}
