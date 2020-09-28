import java.util.*;
public class 공유기설치2110번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int c=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		Arrays.sort(a);
		solve(a,c);
	}
	public static void solve(int a[],int c) {
		int l=1;
		int r=a[a.length-1];
		int mid=(l+r)/2;
		int ans=0;
		while(l<=r) {
			mid=(l+r)/2;
			if(check(a,c,mid)) {
				ans=Math.max(ans, mid);
				l=mid+1;
			}else {
				r=mid-1;
			}
		}
		System.out.println(ans);
	}
	public static boolean check(int a[],int c,int mid) {
		int cnt=1;
		int last=a[0];
		for(int i:a) {
			if(i-last>=mid) {
				last=i;
				cnt++;
			}
		}
		return cnt>=c;
	}
}
