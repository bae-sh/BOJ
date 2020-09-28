package 백준;

import java.util.*;
public class 연결요소의개수11724번 {
	static ArrayList<Integer> a[];
	static boolean check[];
	public static void bfs(int start) {
		Queue<Integer> q=new LinkedList<Integer>();
		q.add(start);
		check[start]=true;
		while(!q.isEmpty()) {
			int x=q.remove();
			for(int i:a[x]) {
				if(check[i]==false) {
					check[i]=true;
					q.add(i);
				}
			}
		}
	}
	public static void dfs(int x) {
		if(check[x]) {
			return;
		}
		check[x]=true;
		for(int i:a[x]) {
			if(check[i]==false) {
				dfs(i);
			}
		}
		
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int ans=0;
		a=(ArrayList<Integer>[]) new ArrayList[n+1];
		for(int i=1;i<=n;i++) {
			a[i]=new ArrayList<Integer>();
		}
		for(int i=0;i<m;i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			a[x].add(y);
			a[y].add(x);
		}
		check=new boolean[n+1];
		for(int i=1;i<=n;i++) {
			if(check[i]==false) {
				dfs(i);
				ans++;
			}
		}
		System.out.println(ans);
		
	}

}
