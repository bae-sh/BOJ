import java.util.*;
public class 달팽이 {
	static int dx[]= {1,0,-1,0};
	static int dy[]= {0,1,0,-1};
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		StringBuilder sb=new StringBuilder();
		int a[][]=new int[n][n];
		int cnt=0;
		int x=0;int y=0;
		a[0][0]=n*n;
		for(int i=n*n-1;i>=1;i--) {
			if(cnt%4==0) {
				if(x+1>=n) {
					cnt++;
					i++;
				}else if(a[x+1][y]!=0) {
					cnt++;
					i++;
				}else {
					a[++x][y]=i;
				}
			}else if(cnt%4==1) {
				if(y+1>=n) {
					cnt++;
					i++;
				}else if(a[x][y+1]!=0) {
					cnt++;
					i++;
				}else {
					a[x][++y]=i;
				}
			}else if(cnt%4==2) {
				if(x-1<0) {
					cnt++;
					i++;
				}else if(a[x-1][y]!=0) {
					cnt++;
					i++;
				}else {
					a[--x][y]=i;
				}
			}else {
				if(y-1<0) {
					cnt++;
					i++;
				}else if(a[x][y-1]!=0) {
					cnt++;
					i++;
				}else {
					a[x][--y]=i;
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				int t=a[i][j];
				if(m==t) {
					x=i+1;y=j+1;
				}
				sb.append(a[i][j]+" ");
			}
			sb.append("\n");
		}
		sb.append(x+" "+y);
		System.out.println(sb.toString());
	}

}
