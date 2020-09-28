package 백준;

import java.util.*;
import java.io.*;
public class 수정렬하기3 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int d[]=new int[10001];
		for(int i=0;i<n;i++) {
			int x=Integer.parseInt(br.readLine());
			d[x]++;
		}
		for(int i=0;i<10001;i++) {
			while(d[i]!=0) {
			System.out.println(i);
			d[i]--;
			}
		}

	}
	}


