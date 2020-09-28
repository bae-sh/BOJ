import java.util.*;
public class 성적표 {
	static long max=9000000000000000000L;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int x=0;
		int y=0;
		Pair14721[] p=new Pair14721[n];
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			int b=sc.nextInt();
			p[i]=new Pair14721(a,b);
		}
		for(int i=1;i<=100;i++) {
			for(int j=1;j<=100;j++) {
				long ans=0;
				for(int k=0;k<n;k++) {
					ans+=Math.pow(p[k].b-(i*p[k].a+j), 2);
				}
				if(max>ans) {
					x=i;
					y=j;
					max=ans;
				}
			}
		}
		System.out.println(x+" "+y);
	}

}
class Pair14721{
	int a;
	int b;
	public Pair14721(int a,int b) {
		this.a=a;
		this.b=b;
	}
}
