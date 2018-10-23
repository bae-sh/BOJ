package 백준;
import java.util.*;
public class 수찾기1920번 {
	static int check(int a[],int k[],int p,int s) {
		if(a[a.length-1]<s||a[0]>s) {
			return 0;
		}
		if(a[p]>s) {
			if(k[p]!=0) {
				return 0;
			}
			k[p]=1;
			if(p==0) {
				return 0;
			}
			p=p/2;
			return check(a,k,p,s);
		}
		else if(a[p]<s) {
			if(k[p]!=0) {
				return 0;
			}
			if(p+p/2>a.length) {
				return 0;
			}
			k[p]=1;
			p=p+p/2;
			return check(a,k,p,s);
		}
		else {
			return 1;
		}
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		Arrays.sort(a);
		int m=sc.nextInt();
		for(int i=0;i<m;i++) {
			int k[]=new int[n+1];
			int q=sc.nextInt();
			int p=a.length/2;
			System.out.println(check(a,k,p,q));
		}
	}

}
