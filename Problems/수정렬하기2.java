package 백준;

import java.util.*;
import java.io.*;
public class 수정렬하기2 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int d[]=new int[n];
		for(int i=0;i<n;i++) {
			d[i]=Integer.parseInt(br.readLine());
		}
		Arrays.sort(d);
		for(int i=0;i<n;i++) {
			System.out.println(d[i]);
		}
		

	}

}
