package 백준;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class 네수 {

	public static void main(String[] args)throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] x=br.readLine().split(" ");
		x[0]=x[0]+x[1];
		x[1]=x[2]+x[3];
		long a=Long.parseLong(x[0]);
		long b=Long.parseLong(x[1]);
		System.out.println(a+b);
	}

}