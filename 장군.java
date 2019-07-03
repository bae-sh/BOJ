import java.util.*;
public class 장군 {
	static int ans=10000000;
	static int dx[]={-2,-3,-3,-2,2,3,3,2};
	static int dy[]= {-3,-2,2,3,3,2,-2,-3};
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int r1=sc.nextInt();
		int c1=sc.nextInt();
		int r2=sc.nextInt();
		int c2=sc.nextInt();
		boolean c[][]=new boolean[10][9];
		c[r1][c1]=true;
		go(r1,c1,r2,c2,c);
		if(ans==10000000) {
			System.out.println(-1);
		}else {
			System.out.println(ans);
		}
	}
	static void go(int r1,int c1,int r2,int c2,boolean c[][]) {
		Queue<Pair16509> q=new LinkedList();
		int cnt=0;
		q.add(new Pair16509(r1,c1,cnt));
		c[r1][c1]=true;
		while(!q.isEmpty()) {
			Pair16509 p=q.poll();
			if(p.x==r2&&p.y==c2) {
				ans=p.cnt;
				break;
			}else {
				for(int i=0;i<8;i++) {
					int nx=p.x+dx[i];
					int ny=p.y+dy[i];
					if(0<=nx&&nx<10&&0<=ny&&ny<9&&!c[nx][ny]) {
						if(i==0) {
							if((r2==p.x&&c2==p.y-1)||(r2==p.x-1&&c2==p.y-2))
								continue;
						}else if(i==1) {
							if((r2==p.x-1&&c2==p.y)||(r2==p.x-2&&c2==p.y-1))
								continue;
						}else if(i==2) {
							if((r2==p.x-1&&c2==p.y)||(r2==p.x-2&&c2==p.y+1))
								continue;
						}else if(i==3) {
							if((r2==p.x&&c2==p.y+1)||(r2==p.x-1&&c2==p.y+2))
								continue;
						}else if(i==4) {
							if((r2==p.x&&c2==p.y+1)||(r2==p.x+1&&c2==p.y+2))
								continue;
						}else if(i==5) {
							if((r2==p.x+1&&c2==p.y)||(r2==p.x+2&&c2==p.y+1))
								continue;
						}else if(i==6) {
							if((r2==p.x&&c2==p.y+1)||(r2==p.x-1&&c2==p.y+2))
								continue;
						}else if(i==7) {
							if((r2==p.x&&c2==p.y-1)||(r2==p.x+1&&c2==p.y-2))
								continue;
						}
							q.add(new Pair16509(nx,ny,p.cnt+1));
					}
				}
			}
			
		}
	}
}
class Pair16509{
	int x;
	int y;
	int cnt;
	Pair16509(int x,int y,int cnt){
		this.x=x;
		this.y=y;
		this.cnt=cnt;
	}
}
