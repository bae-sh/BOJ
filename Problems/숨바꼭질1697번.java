package 백준;
import java.util.*;
public class 숨바꼭질1697번 {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		int d[]=new int[150000];
		boolean check[]=new boolean[150000];
		if(n==k) {
			System.out.println(0);
		}else {
			Queue<Integer> q= new LinkedList();
			check[n]=true;
			add(q,n,d,check);
			while(!q.isEmpty()) {
				int x=q.remove();
				if(x==k) {
					System.out.println(d[x]);
					System.exit(0);
				}else {
					add(q,x,d,check);
				}
			}
		}
	}
	public static void add(Queue<Integer> q, int x,int d[],boolean check[]) {
		if(0<=x-1&&check[x-1]==false) {
			q.add(x-1);
			d[x-1]=d[x]+1;
			check[x-1]=true;
		}
		if(2*x<=149999&&check[2*x]==false) {
			q.add(2*x);
			d[2*x]=d[x]+1;
			check[x*2]=true;
		}
		if(x+1<=149999&&check[x+1]==false) {
			q.add(x+1);
			d[x+1]=d[x]+1;
			check[x+1]=true;
		}
	}
}
