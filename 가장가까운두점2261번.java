import java.util.*;
public class 가장가까운두점2261번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		Pair2261[] p=new Pair2261[n];
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			int b=sc.nextInt();
			p[i]=new Pair2261();
			p[i].x=a;
			p[i].y=b;
		}
		Arrays.sort(p);
		solve(p,0,n-1);
		
	}
	public static double solve(Pair2261[] p,int start,int end) {
		if(end==0) {
			return cal(p[0].x,p[1].x,p[0].y,p[1].y);
		}else if(start==end){
			return cal(p[end].x,p[end].y,p[end-1].x,p[end-1].y);
		}else {
			int mid=(start+end)/2;
			double lm=solve(p,start,mid);
			double rm=solve(p,mid+1,end);
			
			double min=Math.min(lm, rm);
			int ans=1000000000;
			for(int i=0;i<end;i++) {
				if(Math.abs(p[i].x-p[mid].x)<Math.sqrt(min)) {
					int d=(int)(Math.pow((p[i].x-p[mid].x), 2)+Math.pow((p[i].y-p[mid].y), 2));
					ans=Math.min(ans, d);
				}else if(i>mid) {
					break;
				}
			}
			return ans;
		}
	}
	public static double cal(int x1,int y1,int x2,int y2) {
		return Math.sqrt(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	}
}
class Pair2261 implements Comparable{
	int x,y;

	@Override
	public int compareTo(Object o) {
		Pair2261 other=(Pair2261) o;
		if(this.x>other.x) {
			return 1;
		}else if(this.x<other.x) {
			return -1;
		}else return 0;
	}
}