package 백준;
import java.util.*;
public class 프린터큐1966번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int k=sc.nextInt();
		for(int i=0;i<k;i++) {
			int n=sc.nextInt();
			int a=sc.nextInt();
			int cnt=0;
			int ans[]=new int[n];
			int [][] d=new int[n][2];
			Queue<Integer> q=new LinkedList();
			for(int j=0;j<n;j++) {
				d[j][0]=sc.nextInt();
				q.add(j);
			}
			while(!q.isEmpty()) {
			int p=q.poll();
			boolean b=true;
			for(int j=0;j<n;j++) {
				if(d[p][0]<d[j][0]&&d[j][1]==0) {
					b=false;
					break;
				}
			}
			if(b==true) {
				ans[p]=++cnt;
				d[p][1]=1;
			}else {
				q.add(p);
			}
		}
			System.out.println(ans[a]);
		}
	}

}
