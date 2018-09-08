package 백준;

import java.util.*;
import java.io.*;
public class 알파벳개수 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s= br.readLine();
		int [] x=new int[26];
		for(int i=0;i<s.length();i++) {
			switch(s.charAt(i)) {
			case 'a':  x[0]++; break;
			case 'b':  x[1]++;break;
			case 'c':  x[2]++;break;
			case 'd': x[3]++;break;
			case 'e':  x[4]++;break;
			case 'f':  x[5]++;break;
			case 'g': x[6]++;break;
			case 'h':  x[7]++;break;
			case 'i':  x[8]++;break;
			case 'j':  x[9]++;break;
			case 'k':  x[10]++;break;
			case 'l': x[11]++;break;
			case 'm':  x[12]++;break;
			case 'n':  x[13]++;break;
			case 'o':  x[14]++;break;
			case 'p':  x[15]++;break;
			case 'q':  x[16]++;break;
			case 'r':  x[17]++;break;
			case 's': x[18]++;break;
			case 't': x[19]++;break;
			case 'u':  x[20]++;break;
			case 'v':  x[21]++;break;
			case 'w':  x[22]++;break;
			case 'x':  x[23]++;break;
			case 'y':  x[24]++;break;
			case 'z':  x[25]++;break;
			
			
			}
		}
		for(int i=0;i<x.length;i++) {
			System.out.print(x[i]+" ");
		}

	}

}
