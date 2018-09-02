package 백준;

import java.util.*;
public class 단지번호붙이기2667번 {
	static ArrayList<Integer> q= new ArrayList<Integer>();
	static int ans2=1;
	static void dfs(int a[][],int d[][],int ans,int x,int y) {
		d[x][y]=1;
		if(y-1>=0) {
			if(a[x][y-1]==1&&d[x][y-1]==0) {
				ans++; ans2++;
				dfs(a,d,ans,x,y-1);
			}
		}
		if(x-1>=0) {
			if(a[x-1][y]==1&&d[x-1][y]==0) {
				ans++;ans2++;
				dfs(a,d,ans,x-1,y);
			}
		}
		if(y+1<=a.length-1) {
			if(a[x][y+1]==1&&d[x][y+1]==0) {
				ans++;ans2++;
				dfs(a,d,ans,x,y+1);
			}
		}
		if(x+1<=a.length-1) {
			if(a[x+1][y]==1&&d[x+1][y]==0) {
				ans++;ans2++;
				dfs(a,d,ans,x+1,y);
			}
		}
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[][]=new int[n][n];
		int d[][]=new int[n][n];
		
		int ans=1;
		for(int i=0;i<n;i++) {
			String p=sc.next();
			for(int j=0;j<n;j++) {
				a[i][j]=p.charAt(j)-'0';
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(a[i][j]==1&&d[i][j]==0) {
					ans2=1;
					dfs(a,d,ans,i,j);
					q.add(ans2);
					
				}
			}
		}
		System.out.println(q.size());
		Collections.sort(q);
		for(int i:q) {
			System.out.println(i);
		}

	}

}
