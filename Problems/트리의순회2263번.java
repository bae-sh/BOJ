import java.io.*;
import java.util.*;
public class 트리의순회2263번 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int a[]=new int[n];
		int b[]=new int[n];
		Queue<Integer> q=new LinkedList();
		String st[]=br.readLine().split(" ");
		String st2[]=br.readLine().split(" ");
		for(int i=0;i<n;i++) {
			a[i]=Integer.parseInt(st[i]);
			b[i]=Integer.parseInt(st2[i]);
		}
		solve(0,a.length-1,0,b.length-1,a,b,q);
		while(!q.isEmpty())
			System.out.print(q.poll()+" ");
		
	}
	public static void solve(int is,int ie,int ps,int pe,int a[],int b[],Queue q) {
		if(is>ie) {
			return;
		}
		q.add(b[pe]);
		if(is==ie) {
			return;
		}
		
		int ir=find(a,b[pe]);
		int l=ir-is;
		solve(is,ir-1,ps,ps+l-1,a,b,q);
		solve(ir+1,ie,ps+l,pe-1,a,b,q);
	}
	public static int find(int a[],int n) {
		for(int i=0;i<a.length;i++) {
			if(a[i]==n) {
				return i;
			}
		}
		return -1;
	}
}
