import java.util.*;
public class NQueen9663 {
	static int n;
	static int ans=0;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		boolean c[][]=new boolean[n][n];
		calc(0,c);
		System.out.println(ans);
	}
	static void calc(int row,boolean c[][]) {
		if(row==n) {
			ans++;
		}else {
			for(int i=0;i<n;i++) {
				c[row][i]=true;
				if(check(row,i,c)) {
					calc(row+1,c);
				}
				c[row][i]=false;
			}
		}
	}
	static boolean check(int row,int col,boolean c[][]) {
		for(int i=0;i<n;i++) {
			if(i==row) continue;
			if(c[i][col]) {
				return false;
			}
		}
		
		int x=row-1;
		int y=col-1;
		while(0<=x&&0<=y) {
			if(c[x][y]) {
				return false;
			}
			x--;y--;
		}
		x=row-1; y=col+1;
		while(0<=x&&y<n) {
			if(c[x][y]) {
				return false;
			}
			x--;y++;
		}
		return true;
	}
}
