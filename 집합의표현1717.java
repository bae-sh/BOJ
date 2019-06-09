import java.util.*;
public class 집합의표현1717 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int p[]=new int[n+1];
		for(int i=0;i<=n;i++) {
			p[i]=i;
		}
		while(m-->0) {
			int k=sc.nextInt();
			int a=sc.nextInt();
			int b=sc.nextInt();
			
			if(k==0) {
				union(a,b,p);
			}else {
				if(find(a,p)==find(b,p)) {
					System.out.println("YES");
				}else {
					System.out.println("NO");
				}
			}
		}
	}
	static void union(int a,int b,int p[]) {
		a=find(a,p);
		b=find(b,p);
		if(a!=b) {
			p[b]=a;
		}
	}
	static int find(int a,int p[]) {
		if(a==p[a]) {
			return a;
		}else {
			return p[a]=find(p[a],p);
		}
	}
}
