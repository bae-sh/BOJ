package 백준;

import java.util.*;
import java.io.*;
public class 타일링11726번2 {

	public static void main(String[] args)throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int d[]= new int[n+1];
		
		for(int i=0;i<n+1;i++) {
			if(i<=1) {
				d[i]=1;
				continue;
			}
			d[i]=(d[i-1]+d[i-2])%10007;
		}
		System.out.println(d[n]);
	}

}
