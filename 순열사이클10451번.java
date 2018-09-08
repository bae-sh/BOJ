package 백준;

import java.util.*;
public class 순열사이클10451번 {
	static void dfs(ArrayList<Integer> a[],boolean c[],int x) {
		c[x]=true;
		for(int i:a[x]) {
			if(c[i]==false) {
				dfs(a,c,i);
			}
		}
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		
		for(int i=0;i<t;i++) {
			int n=sc.nextInt();
			int ans=0;
			ArrayList<Integer>a[]= (ArrayList<Integer>[])new ArrayList[n+1];
			for(int j=1;j<=n;j++) {
				a[j]=new ArrayList<Integer>();
			}
			for(int j=1;j<=n;j++) {
				int k=sc.nextInt();
				a[j].add(k);
				a[k].add(j);
			}
			boolean c[]=new boolean[n+1];
			for(int j=1;j<=n;j++) {
				if(c[j]==false) {
					dfs(a,c,j);
					ans++;
				}
			}
			System.out.println(ans);
			
		}
		
	}

}
