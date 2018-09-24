package 백준;
import java.util.*;
class Edge{
	int to;
	int cost;
	Edge(int to,int cost){
		this.to=to;
		this.cost=cost;
	}
}
public class 트리의지름1967번 {
	static int[] bfs(ArrayList<Edge>a[],int n,int start) {
		Queue<Integer> q=new LinkedList<Integer>();
		int check[]=new int[n+1];
		check[start]=1;
		int g[]=new int[n+1];
		q.add(start);
		while(!q.isEmpty()) {
			int p=q.remove();
			for(Edge e:a[p]) {
			int to=e.to;
			int cost=e.cost;
			if(check[to]==0) {
				check[to]=1;
				q.add(to);
				g[to]=g[p]+e.cost;
			}
			}
		}
		return g;
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int g[]=new int[n+1];
		int start=1;
		ArrayList<Edge> a[]=(ArrayList<Edge>[])new ArrayList[n+1];
		for(int i=0;i<=n;i++) {
			a[i]=new ArrayList<Edge>();
		}
		for(int i=0;i<n-1;i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			int z=sc.nextInt();
			a[x].add(new Edge(y,z));
			a[y].add(new Edge(x,z));
		}
		g=bfs(a,n,start);
		for(int i=2;i<=n;i++) {
			if(g[start]<g[i]) {
				start=i;
			}
		}
		g=bfs(a,n,start);
		for(int i=1;i<=n;i++) {
			if(g[start]<g[i]) {
				start=i;
			}
		}
		System.out.println(g[start]);
	}

}
