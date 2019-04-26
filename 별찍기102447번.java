import java.util.*;
public class 별찍기102447번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		String a[][]=new String[n][n];
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				a[i][j]=" ";
			}
		}
		solve(n,a,0,0);
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				sb.append(a[i][j]);
			}
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
	public static void solve(int n,String a[][],int x,int y) {
		if(n==1) {
			a[x][y]="*";
		}else {
			for(int i=y;i<y+3*n/3;i+=n/3) {
				for(int j=x;j<x+3*n/3;j+=n/3) {
					if(i==y+n/3&&j==x+n/3) {
						continue;
						}
					solve(n/3,a,j,i);
				}
			}
		}
	}
}
