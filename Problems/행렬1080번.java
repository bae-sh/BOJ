import java.util.*;
public class 행렬1080번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		sc.nextLine();
		int a[][]=new int[n][m];
		int b[][]=new int[n][m];
		int cnt=0;
		for(int i=0;i<n;i++) {
			char[] c=sc.nextLine().toCharArray();
			for(int j=0;j<c.length;j++) {
				a[i][j]=c[j]-'0';
			}
		}
		for(int i=0;i<n;i++) {
			char[] c=sc.nextLine().toCharArray();
			for(int j=0;j<c.length;j++) {
				b[i][j]=c[j]-'0';
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(a[i][j]!=b[i][j]) {
					change(a,i,j);
					cnt++;
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(a[i][j]!=b[i][j]) {
					System.out.println(-1);
					System.exit(0);
				}
					
			}
		}
		System.out.println(cnt);
	}
	public static void change(int a[][],int x,int y) {
		if(a.length-x>=3&&a[0].length-y>=3) {
			for(int i=x;i<x+3;i++) {
				for(int j=y;j<y+3;j++) {
					a[i][j]=(a[i][j]==1) ?0:1;
				}
			}
		}
	}
}
