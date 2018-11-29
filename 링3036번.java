package 백준;
import java.util.*;
public class 링3036번 {
	static int gcd(int a,int b) {
		while(b!=0) {
			int temp=a%b;
			a=b;
			b=temp;
		}
		return a;
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		for(int i=1;i<=n-1;i++) {
			int k=gcd(a[0],a[i]);
			System.out.println(a[0]/k+"/"+a[i]/k);
		}
	}

}
