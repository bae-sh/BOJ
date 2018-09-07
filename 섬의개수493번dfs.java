package 백준;

import java.util.*;
public class 섬의개수493번dfs {
	public static final int dx[]= {0,-1,-1,-1,0,1,1,1};
	public static final int dy[]= {-1,-1,0,1,1,1,0,-1};
	static void dfs(int a[][],int group[][],int x,int y,int w,int h) {
		Pair p= new Pair(x,y);
		for(int i=0;i<8;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(0<=nx&&nx<h&&0<=ny&&ny<w&&group[nx][ny]==0&&a[nx][ny]==1) {
				group[nx][ny]=1;
				dfs(a,group,nx,ny,w,h);
			}
		}
	}
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		while(true) {
			int w=sc.nextInt();
			int h=sc.nextInt();
			int cnt=0;
			if(w==0&&h==0) break;
			
			int a[][]=new int[h][w];
			int group[][]=new int[h][w];
			for(int i=0;i<h;i++) {
				for(int j=0;j<w;j++) {
					a[i][j]=sc.nextInt();
				}
			}
			
			for(int i=0;i<h;i++) {
				for(int j=0;j<w;j++) {
					if(a[i][j]==1&&group[i][j]==0) {
						dfs(a,group,i,j,w,h);
						cnt++;
					}
				}
			}
			System.out.println(cnt);
		}
	}

}
