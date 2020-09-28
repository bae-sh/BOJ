package 백준;

import java.util.*;
import java.io.*;
public class 텀프로젝트9466번 {
	static void dfs(int aa[],int x,int c[],int count,ArrayList<Integer>a[]) {
		int i=aa[x];
			if(c[i]==0) {
				c[x]=count;
				if(x!=i&&aa[i]==i) {
					a[0].add(count);
					return;
				}
				dfs(aa,i,c,count,a);
			}
			else {
				if(c[i]!=c[x]) {
					a[0].add(count);
				}
				else {
					return;
				}
			}
		
	}
	public static void main(String[] args)throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int count=0;
		for(int i=0;i<n;i++) {
			int k=Integer.parseInt(br.readLine());
			int aa[]=new int[k+1];
			ArrayList<Integer> a[]=(ArrayList<Integer>[])new ArrayList[1];
			a[0]=new ArrayList<Integer>();

			String g[]=br.readLine().split(" ");
			for(int j=1;j<=k;j++) {
				aa[j]=Integer.parseInt(g[j-1]);
			}
			int c[]=new int[k+1];
			for(int j=1;j<=k;j++) {
				count++;
				if(c[j]==0)
				dfs(aa,j,c,count,a);
			}
			int out=0;
			for(int j=1;j<=k;j++) {
				if(a[0].contains(c[j])) {
					out++;
				}
			}
			System.out.println(out);
		}
	}

}
