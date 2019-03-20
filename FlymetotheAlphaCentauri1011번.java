package 백준;
import java.util.*;
public class FlymetotheAlphaCentauri1011번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			double n=y-x;
			int c=(int)Math.sqrt(n);
			int ans=0;
			if(c*c>n) {
				c--;
			}
			ans+=2*c-1;
			double k=n-c*c;
			double k2=Math.ceil(k/c);
			ans+=k2;
			System.out.println(ans);
		}
	}

}
