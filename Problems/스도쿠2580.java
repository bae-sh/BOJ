import java.util.*;
public class 스도쿠2580 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a[][]=new int[9][9];
		for(int i=0;i<9;i++) {
			String s[]=sc.nextLine().split(" ");
			for(int j=0;j<9;j++) {
				a[i][j]=Integer.parseInt(s[j]);
			}
		}
		calc(a,0);
		
	}
	static void calc(int a[][],int cnt) {
		if(cnt==81) {
			for(int i=0;i<9;i++) {
				for(int j=0;j<8;j++) {
					System.out.print(a[i][j]+" ");
				}
				System.out.println(a[i][8]);
			}
			System.exit(0);
		}else {
			int x=cnt/9;
			int y=cnt%9;
			if(a[x][y]==0) {
				for(int i=1;i<10;i++) {
					a[x][y]=i;
					if(check(a,cnt,i)) {
						calc(a,cnt+1);
					}
				}
				a[x][y]=0;
			}else {
				calc(a,cnt+1);
			}
		}
	}
	static boolean check(int a[][],int cnt,int i) {
		int x=cnt/9;
		int y=cnt%9;
		for(int j=0;j<9;j++) {
			if(j==x) continue;
			if(a[j][y]==i) 
				return false;
		}
		for(int j=0;j<9;j++) {
			if(j==y) continue;
			if(a[x][j]==i) 
				return false;
		}
		int nx=x/3*3;
		int ny=y/3*3;
		for(int j=nx;j<nx+3;j++) {
			for(int k=ny;k<ny+3;k++) {
				if(j==x&&k==y) continue;
				if(a[j][k]==i)
					return false;
			}
		}
		return true;
	}
}
