package 백준;
import java.util.*;
import java.io.*;
public class 동전0 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		int n=Integer.parseInt(st.nextToken());
		int k=Integer.parseInt(st.nextToken());
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=Integer.parseInt(br.readLine());
		}
		int min=0;
		for(int i=n-1;i>=0;i--) {
			min+=k/a[i];
			k%=a[i];
		}
		System.out.println(min);
	}

}
