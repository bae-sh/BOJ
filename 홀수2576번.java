package 백준;
import java.util.*;
public class 홀수2576번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int ans=0;
		int min=100;
		for(int i=0;i<7;i++) {
			int a=sc.nextInt();
			if(a%2!=0) {
				ans+=a;
				min=Math.min(a, min);
			}
		}
		if(ans==0) {
			System.out.println(-1);
			System.exit(0);
		}
		System.out.println(ans);
		System.out.println(min);
	}

}
