package 백준;

import java.util.*;
import java.io.*;
public class 피보나치수3 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long n=Integer.parseInt(br.readLine());
		System.out.println(f(n));

	}
	public static long f(long n) {
		if(n<=1) {
			return n;
		}
		else {
			return (f(n-1)%1000000+f(n-2)%1000000)%1000000;
		}
	}

}
