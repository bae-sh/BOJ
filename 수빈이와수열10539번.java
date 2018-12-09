package 백준;
import java.util.*;
public class 수빈이와수열10539번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n+1];
		int b[]=new int[n+1];
		for(int i=1;i<=n;i++) {
			b[i]=sc.nextInt();
		}
		a[1]=b[1];
		System.out.print(a[1]);
		for(int i=2;i<=n;i++) {
			a[i]=b[i]*i-b[i-1]*(i-1);
			System.out.print(" "+a[i]);
		}
	}

}
