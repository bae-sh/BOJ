import java.util.*;
public class 별찍기112448번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=5*n/3+n/3-1;
		StringBuilder sb=new StringBuilder();
		String a[][]=new String[k][k];
		for(int i=0;i<k;i++) {
			for(int j=0;j<k;j++) {
				a[i][j]=" ";
			}
		}
		if(n/3==1) {
			solve(n/3,a,2,0);
		}else {
			int l=(int)(Math.log10(n/3)/Math.log10(2));
			solve(n/3,a,5*(int)Math.pow(2, l-1)+(int)Math.pow(2, l-1)-1,0);
		}
		for(int i=0;i<k;i++) {
			for(int j=0;j<k;j++) {
				sb.append(a[i][j]);
			}
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
	public static void solve(int n,String a[][],int x,int y) {
		if(n==1) {
			a[y][x]="*";
			a[y+1][x-1]="*";
			a[y+1][x+1]="*";
			for(int i=0;i<5;i++) {
				a[y+2][x-2+i]="*";
			}
		}else {
			solve(n/2,a,x,y);
			solve(n/2,a,x-3*(int)Math.pow(2, Math.log10(n)/Math.log10(2)-1),y+3*n/2);
			solve(n/2,a,x+3*(int)Math.pow(2, Math.log10(n)/Math.log10(2)-1),y+3*n/2);
		}
	}
}	
