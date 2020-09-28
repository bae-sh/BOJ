package 백준;
import java.util.*;
public class 바이러스2606번 {
	static int cnt=0;
	static void bfs(ArrayList<Integer>[] a,boolean c[]) {
		Queue<Integer> q=new LinkedList<Integer>();
		q.add(1);
		while(!q.isEmpty()) {
			int k=q.poll();
			for(int i:a[k]) {
				if(c[i]==false) {
					c[i]=true;
					q.add(i);
					cnt++;
				}
			}
		}
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int t=sc.nextInt();
		boolean c[]=new boolean[n+1];
		ArrayList<Integer>[] a=(ArrayList<Integer>[])new ArrayList[n+1]; 
		for(int i=0;i<n+1;i++) {
			a[i]=new ArrayList();
		}
		for(int i=0;i<t;i++) {
			int n1=sc.nextInt();
			int n2=sc.nextInt();
			a[n1].add(n2);
			a[n2].add(n1);
		}
		bfs(a,c);
		System.out.println(cnt-1);
	}

}
