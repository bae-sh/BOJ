import java.util.*;
public class 쿼드트리1992번 {
	static StringBuilder sb=new StringBuilder();
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		sc.nextLine();
		int a[][]=new int[n][n];
		for(int i=0;i<n;i++) {
			String s=sc.nextLine();
			for(int j=0;j<n;j++) {
				a[i][j]=Integer.parseInt(s.charAt(j)+"");
			}
		}
		solve(a,n,0,0);
		System.out.println(sb.toString());
	}
	public static void solve(int a[][],int n,int x,int y) {
		if(n==0) return;
		int k=same(a,n,x,y);
		if(k==-1) {
				sb.append("(");
				solve(a,n/2,x,y);
				solve(a,n/2,x+n/2,y);
				solve(a,n/2,x,y+n/2);
				solve(a,n/2,x+n/2,y+n/2);
				sb.append(")");
		}else {
			sb.append(k);
		}
	}
	public static int same(int a[][],int n,int x,int y) {
		for(int i=y;i<y+n;i++) {
			for(int j=x;j<x+n;j++) {
				if(a[y][x]!=a[i][j]) {
					return -1;
				}
			}
		}
		return a[y][x];
	}
}
