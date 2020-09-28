package 백준;

import java.util.*;
import java.io.*;
public class 시간관리하기 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n= Integer.parseInt(br.readLine());
		int [][] x =new int[n][2];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			x[i][0]=Integer.parseInt(st.nextToken());
			x[i][1]=Integer.parseInt(st.nextToken());
		}
		
		
	}
}
