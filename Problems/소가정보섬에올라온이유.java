import java.util.*;
import java.io.*;
public class 소가정보섬에올라온이유 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s3[]=br.readLine().split(" ");
		int n=Integer.parseInt(s3[0]);
		int q=Integer.parseInt(s3[1]);
		int d[]=new int[n];
		long ans[]=new long[n];
		StringBuilder sb=new StringBuilder();
		String s[]=br.readLine().split(" ");
		String s2[]=br.readLine().split(" ");
		long allSum=0;
		for(int i=0;i<n;i++) {
			d[i]=Integer.parseInt(s[i]);
		}
		for(int i=0;i<n;i++) {
			long temp=1;
			int t[]=new int[4];
			t[0]=i;
			for(int j=1;j<4;j++) {
				t[j]=t[j-1]+1;
				if(t[j]==n) {
					t[j]=0;
				}
			}
			for(int j=0;j<4;j++) {
				temp*=d[t[j]];
			}
			ans[i]=temp;
		}
		for(long i:ans) {
			allSum+=i;
		}
		for(int k=0;k<q;k++) {
			int a=Integer.parseInt(s2[k])-4;
			if(a<0) {
				a+=n;
			}
			for(int i=0;i<4;i++) {
				if(a>=n) {
					a=0;
				}
				ans[a]=-ans[a];
				allSum+=ans[a]*2;
				a++;
			}
			sb.append(allSum+"\n");
		}
		System.out.println(sb.toString());
	}

}
