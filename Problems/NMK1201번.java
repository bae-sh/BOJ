import java.util.*;
public class NMK1201번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int k=sc.nextInt();
		if(m+k-1>n||m*k<n) {
			System.out.println(-1);
			System.exit(0);
		}
		if(m==1) {
			for(int i=n;i>=1;i--) {
				System.out.print(i+" ");
			}
			System.exit(0);
		}
		Queue<Integer> q=new LinkedList<>();
		ArrayList<Integer> a[]=new ArrayList[n];
		for(int i=0;i<n;i++) {
			a[i]=new ArrayList();
		}
		int x=(n-k)/(m-1);
		int y=(n-k)%(m-1);
		q.add(k);
		for(int i=0;i<m-1;i++) {
			if(y>0) {
				q.add(x+1);
			y--;	
			}else {
				q.add(x);
			}
		}
		int j=0;
		int start=1;
		while(!q.isEmpty()) {
			for(int i=q.poll();i>0;i--,start++) {
				a[j].add(start);
			}
			Collections.sort(a[j], Collections.reverseOrder());
			j++;
		}
		for(int i=0;i<j;i++) {
			for(int e=0;e<a[i].size();e++) {
				System.out.print(a[i].get(e)+" ");
			}
		}
		
	}

}
