package 백준;
import java.util.*;
import java.io.*;
public class 수찾기1920번 {
	
	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int d[]=new int[n];
		String st[]=br.readLine().split(" ");
		for(int i=0;i<st.length;i++) {
			d[i]=Integer.parseInt(st[i]);
		}
		Arrays.sort(d);
		n=Integer.parseInt(br.readLine());
		st=br.readLine().split(" ");
		for(int i=0;i<n;i++) {
			int k=Integer.parseInt(st[i]);
			System.out.println(check(d,k,0,d.length-1));
		}
	}
	public static int check(int[] d,int n,int left,int right) {
		int pivot=(left+right)/2;
		
		if(d[left]==n||d[pivot]==n||d[right]==n) {
			return 1;
		}else if(right-left<=1) {
			return 0;
		}
		else if(n<d[pivot]) {
			return check(d,n,left,pivot);
		}
		else {
			return check(d,n,pivot+1,right);
		}
	}
}
