import java.util.*;
public class DSLR {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0) {
			int n=sc.nextInt();
			int m=sc.nextInt();
			Queue<Integer> q=new LinkedList<>();
			String d[]=new String[10000];
			for(int i=0;i<10000;i++) {
				d[i]="";
			}
			if(n==m) {
				System.out.println(0);
			}else {
				q.add(n);
				while(!q.isEmpty()) {
					int x=q.remove();
					if(x==m) {
						System.out.println(d[x]);
						break;
					}else {
						change(x,d,q);
					}
				}
			}
		}
	}
	public static void change(int x,String d[],Queue<Integer> q) {
		int y=2*x;
		if(y>9999) y%=10000;
		if(y!=x&&d[y].equals("")) {
			d[y]+=d[x]+"D";
			q.add(y);
		}
		y=x-1;
		if(y<0) y=9999;
		if(d[y].equals("")) {
			d[y]+=d[x]+"S";
			q.add(y);
		}
		y=(x%1000)*10+(x/1000);
		if(y!=x&&d[y].equals("")) {
			d[y]=d[x]+"L";
			q.add(y);
		}
		y=(x/10)+(x%10)*1000;
		if(y!=x&&d[y].equals("")) {
			d[y]=d[x]+"R";
			q.add(y);
		}
	}
}
