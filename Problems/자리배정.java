import java.util.*;
public class 자리배정 {
	static int dx[]={-1,0,1,0};
	static int dy[]= {0,1,0,-1};
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int c=sc.nextInt();
		int r=sc.nextInt();
		int k=sc.nextInt();
		if(k>c*r) {
			System.out.println(0);
		}else {
			boolean a[][]=new boolean[r][c];
			a[r-1][0]=true;
			int x=r-1;
			int y=0;
			int cnt=0;
			for(int i=2;i<=k;i++) {
					int nx=x+dx[cnt%4];
					int ny=y+dy[cnt%4];
					if(0<=nx&&nx<r&&0<=ny&&ny<c&&!a[nx][ny]) {
						x=nx; y=ny;
						a[nx][ny]=true;
					}else {
						cnt++;
						i--;
					}
				
			}
			x=r-x;
			y++;
			System.out.println(y+" "+x);
			
		}
	}

}
