package 백준;
import java.util.*;
public class 빙고2578번 {
	public static void c(int dp[][],int n,int check[][]) {
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				if(dp[i][j]==n) {
					check[i][j]=1;
				}
			}
		}
	}
	public static void win(int c[][],int ans) {
		int a=0;
		for(int i=0;i<5;i++) {
			if(c[i][0]==1&&c[i][1]==1&&c[i][2]==1&&c[i][3]==1&&c[i][4]==1) {
				a++;
			}
			if(c[0][i]==1&&c[1][i]==1&&c[2][i]==1&&c[3][i]==1&&c[4][i]==1) {
				a++;
			}
			
		}
		if(c[0][0]==1&&c[1][1]==1&&c[2][2]==1&&c[3][3]==1&&c[4][4]==1) {
			a++;
		}
		if(c[4][0]==1&&c[3][1]==1&&c[2][2]==1&&c[1][3]==1&&c[0][4]==1) {
			a++;
		}
		if(a>=3) {
			System.out.println(ans);
			System.exit(0);
			
		}
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int dp[][]=new int[5][5];
		int check[][]=new int[5][5];
		int ans=1;
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				dp[i][j]=sc.nextInt();
			}
		}
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				int a=sc.nextInt();
				c(dp,a,check);
				win(check,ans);
				ans++;
			}
		}
		
	}

}
