package 백준;

import java.util.*;
public class 트리의부모찾기11725번 {
	static void bfs(ArrayList<Integer>a[],int p[],int start) {
		Queue<Integer> q=new LinkedList<Integer>();
		q.add(start);
		while(!q.isEmpty()) {
			int r=q.remove();
			for(int i:a[r]) {
				if(p[i]==0) {
					p[i]=r;
					q.add(i);
				}
			}
		}
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int p[]=new int[n+1];
		ArrayList<Integer> a[]=(ArrayList<Integer>[])new ArrayList[n+1];
		for(int i=0;i<n+1;i++) {
			a[i]=new ArrayList<Integer>();
		}
		for(int i=0;i<n-1;i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			a[x].add(y);
			a[y].add(x);
		}
		p[1]=-1;
		bfs(a,p,1);
		for(int i=2;i<=n;i++) {
			System.out.println(p[i]);
		}
	}

}
