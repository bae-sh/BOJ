package 백준;
import java.util.*;
import java.io.*;
public class 더하기9095번 {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int d[]= new int[12];
		d[0]=1;
		d[1]=1;
		d[2]=2;
		for(int i=3;i<12;i++) {
			d[i]=d[i-1]+d[i-2]+d[i-3];
		}
		for(int i=0;i<n;i++) {
			int x=Integer.parseInt(br.readLine());
			System.out.println(d[x]);
		}
	}

}
