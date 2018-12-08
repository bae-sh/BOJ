package 백준;
import java.util.*;
public class 색종이2563번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a[][]=new int[101][101];
		int ans=0;
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			for(int j=x;j<x+10;j++) {
				for(int k=y;k<y+10;k++) {
					a[j][k]=1;
				}
			}
		}
		for(int i=0;i<101;i++) {
			for(int j=0;j<101;j++) {
				if(a[i][j]==1) {
					ans++;
				}
			}
		}
		System.out.println(ans);
		
	}

}
