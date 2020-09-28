import java.util.*;
import java.io.*;
public class 약수 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		String a[]=br.readLine().split(" ");
		long b[]=new long[n];
		for(int i=0;i<n;i++) {
			b[i]=Integer.parseInt(a[i]);
		}
		Arrays.sort(b);
		if(n%2==0) {
			long ans=b[0]*b[n-1];
			System.out.println(ans);
		}else {
			long ans=b[(n-1)/2]*b[(n-1)/2];
			System.out.println(ans);
		}
	}

}
