package 백준;
import java.util.*;
public class ACM호텔10250번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++) {
			int h=sc.nextInt();
			int w=sc.nextInt();
			int n=sc.nextInt();
			
			int a=(int)Math.ceil((double)n/h);//호실
			int b=n%h;//층
			if(n%h==0) {
				b=h;
			}
			
			
			System.out.print(b);
			System.out.printf("%02d",a);
			System.out.println();
		}
	}

}
