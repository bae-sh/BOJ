package 백준;
import java.util.*;
public class 검증수2475번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a[]=new int[5];
		int ans=0;
		for(int i=0;i<5;i++) {
			int x=sc.nextInt();
			a[i]=x*x;
			ans+=a[i];
		}
		System.out.println(ans%10);
	}

}
