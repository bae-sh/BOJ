package 백준;
import java.util.*;
public class 남욱이의닭장11006번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++) {
			int n=sc.nextInt();
			int m=sc.nextInt();
			int ans=m*2-n;
			System.out.println(ans+" "+(m-ans));
		}
	}

}
