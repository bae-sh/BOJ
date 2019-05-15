import java.util.*;
public class 숫자카드10815번 {

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
			int k=sc.nextInt();
			find(a,a.length-1,0,k);
		}
		
	}
	public static void find(int a[],int right,int left,int x) {
		while(left<=right) {
			int mid=(left+right)/2;
			if(a[mid]==x) {
				System.out.print("1 ");
				return;
			}else if(a[mid]>x) {
				right=mid-1;
			}else {
				left=mid+1;
			}
		}
		System.out.print("0 ");
	}
}
