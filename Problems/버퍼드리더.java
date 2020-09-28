package 백준;

import java.util.*;
import java.io.*;
public class 버퍼드리더 {

	public static void main(String[] args) throws IOException {
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine());
		int save[] = new int[num];
		for(int i=0;i<num;i++) {
			int a=Integer.parseInt(br.readLine());
			int b=Integer.parseInt(br.readLine());
			save[i]=a+b;
			
		}
		for(int i=0;i<num;i++) {
			System.out.println(save[i]);
		}
		
	}

}
