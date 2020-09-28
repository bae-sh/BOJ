import java.util.*;
import java.io.*;
public class 여우가정보섬에올라온이유 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		long cnt=0;
		Pair17131 p[]=new Pair17131[n];
		for(int i=0;i<n;i++) {
			String s[]=br.readLine().split(" ");
			int x=Integer.parseInt(s[0]);
			int y=Integer.parseInt(s[1]);
			p[i]=new Pair17131(x, y);
		}
		for(int i=0;i<p.length;i++) {
			cnt=cnt+go(p,p[i].x,p[i].y,i);
			cnt%=1000000007;
		}
		System.out.println(cnt);
	}
	public static long go(Pair17131 p[],int x,int y,int k) {
		long left=0;
		long right=0;
		for(int i=k;i<p.length;i++) {
			Pair17131 p1=p[i];
			int x1=p1.x;
			int y1=p1.y;
			if(p1.x>x&&p1.y>y) {
				right++;
			}else if(p1.x<x&&p1.y>y) {
				left++;
			}
		}
		return (right*left)%1000000007;
	}
}
class Pair17131{
	int x,y;
	public Pair17131(int x,int y) {
		this.x=x;
		this.y=y;
	}
}
