import java.util.*;
public class 별찍기22 {
	static int dx[]= {0,1,0,-1};
	static int dy[]= {-1,0,1,0};
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		if(n==1) {
			System.out.println("*");
			return;
		}
		int size=n*4-3;
		String s[][]=new String[4*n-1][size];
		for(int i=0;i<4*n-1;i++) {
			for(int j=0;j<size;j++) {
				s[i][j]=" ";
			}
		}
		int time=0;
		int x=0,y=size-1;
		while(true) {
			s[x][y]="*";
			if(x==2*n&&y==size/2) {
				break;
			}
			int nx=x+dx[time];
			int ny=y+dy[time];
			if(0<=nx&&nx<4*n-1&&0<=ny&&ny<size) {
				if(0<=nx+dx[time]&&nx+dx[time]<4*n-1&&0<=ny+dy[time]&&ny+dy[time]<size&&s[nx+dx[time]][ny+dy[time]].equals("*")) {
					time=(time+1)%4;
				}else {
					x=nx;y=ny;
				}
			}else {
				time=(time+1)%4;
			}
		}
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<4*n-1;i++) {
			if(i==1) {
				sb.append("*\n");
				continue;
			}
			for(int j=0;j<size;j++) {
				sb.append(s[i][j]);
			}
			if(i!=4*n-2)
				sb.append("\n");
		}
		System.out.print(sb.toString());
	}
}
