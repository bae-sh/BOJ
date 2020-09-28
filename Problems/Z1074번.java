import java.util.*;
public class Z1074번 {
	static int cnt=0;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int r=sc.nextInt();
		int c=sc.nextInt();
		
		solve(n,r,c,0,0);
	}
	public static void solve(int n,int r,int c,int x,int y) {
		if(n==1) {
			for(int i=0;i<2;i++) {
				for(int j=0;j<2;j++) {
					if(x+i==r&&y+j==c) {
						System.out.println(cnt);
						System.exit(0);
					}
					cnt++;
				}
			}
		}
		else {
			int k=(int)Math.pow(2, n-1);
			if(x+k-1>=r&&y+k-1>=c) {
				solve(n-1,r,c,x,y);
			}else if(x+k-1>=r&&y+k-1<c) {
				cnt+=k*k;
				solve(n-1,r,c,x,y+k);
			}else if(x+k-1<r&&y+k-1>=c) {
				cnt+=2*k*k;
				solve(n-1,r,c,x+k,y);
			}else {
				cnt+=3*k*k;
				solve(n-1,r,c,x+k,y+k);
			}
		}
	}
}
