package 백준;

import java.util.*;
public class 이분그래프1707번 {
	static ArrayList<Integer> a[];
	static int check[];
	static boolean bfs(int start) {
		Queue<Integer> q= new LinkedList<Integer>();
		q.add(start);
		check[start]=1;
		while(!q.isEmpty()) {
			int x=q.remove();
			for(int i:a[x]) {
				if(x==i) {
					return false;
				}
				if(check[i]==0) {
				q.add(i);
				check[i]=3-check[x];
				}
				else if(check[i]!=3-check[x]&&i!=x) {
					return false;
				}
			}
		}
		return true;
		
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		
		for(int i=0;i<n;i++) {
			boolean p=true;
			boolean pp=true;
			int x=sc.nextInt();
			int y=sc.nextInt();
			a=(ArrayList<Integer>[]) new ArrayList[x+1];
			for(int j=1;j<x+1;j++) {
				a[j]=new ArrayList<Integer>();
			}
			for(int j=0;j<y;j++) {
				int b=sc.nextInt();
				int c=sc.nextInt();
				a[b].add(c);
				a[c].add(b);
			}
			check= new int[x+1];
			for(int j=1;j<=x;j++) {
				if(check[j]==0) {
					if(p==false) {
						break;
					}
					p=bfs(j);
				}
			}
			if(p==true) {
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}
			
		}
		

	}

}
