import java.util.*;
public class 하노이탑이동순서 {
	static int cnt=0;
	static StringBuilder sb=new StringBuilder();
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		solve(n,1,3);
		System.out.println(cnt+"\n"+sb.toString());
	}
	static void solve(int n,int x,int y) {
		if(n==0) return;
		solve(n-1,x,6-x-y);
		sb.append(x+" "+y+"\n");
		cnt++;
		solve(n-1,6-x-y,y);
	}
}
