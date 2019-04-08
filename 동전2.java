import java.util.*;
public class 동전2 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		int a[]=new int[10001];
		int b[]=new int[n];
		for(int i=0;i<n;i++) {
			int t=sc.nextInt();
			b[i]=t;
			if(t<=k) {
				a[t]=1;
			}
		}
		
	}
	public static void go(int a[],int b[],int k,int n) {
		for(int i:b) {
			if(n+i==k) {
				if(a[k]==0) {
					a[k]=a[n]+1;
				}else if(a[n]+1<a[k]){
					a[k]=a[n]+1;
				}
			}else if(n+i<k) {
				
			}
		}
		
	}
}
