import java.util.*;
public class 알파벳1987 {
	static int ans=1;
	static int[] dx= {-1,0,1,0};
	static int[] dy= {0,1,0,-1};
	static Set<String> set;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int r=sc.nextInt();
		int c=sc.nextInt();
		sc.nextLine();
		String s[][]=new String[r][c];
		set =new HashSet();
		for(int i=0;i<r;i++) {
			String t=sc.nextLine();
			for(int j=0;j<c;j++) {
				s[i][j]=t.charAt(j)+"";
			}
		}
		set.add(s[0][0]);
		go(s,0,0,1);
		System.out.println(ans);
	}
	static void go(String s[][],int x,int y,int n) {
			for(int i=0;i<4;i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(0<=nx&&nx<s.length&&0<=ny&&ny<s[0].length) {
					if(!set.contains(s[nx][ny])) {
						set.add(s[nx][ny]);
						go(s,nx,ny,n+1);
						set.remove(s[nx][ny]);
					}
				}
				ans= Math.max(n, ans);
			}
	}
}
