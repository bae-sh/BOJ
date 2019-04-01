import java.util.*;
import java.io.*;
public class 나무자르기2805번 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] s=br.readLine().split(" ");
		int n=Integer.parseInt(s[0]);
		int m=Integer.parseInt(s[1]);
		String[] _s=br.readLine().split(" ");
		int a[]=new int[n];
		int max=0;
		for(int i=0;i<n;i++) {
			a[i]=Integer.parseInt(_s[i]);
			max=Math.max(max, a[i]);
		}
		solve(max,a,m);
	}
	public static void solve(int max,int a[],int m) {
		int l=1;
		int r=max;
		int mid;
		int ans=0;
		while(l<=r) {
			mid=(l+r)/2;
			if(check(a,mid,m)) {
				ans=Math.max(ans, mid);
				l=mid+1;
			}else {
				r=mid-1;
			}
		}
		System.out.println(ans);
	}
	public static boolean check(int a[],int mid,int m) {
		long cnt=0;
		for(int i=0;i<a.length;i++) {
			if(a[i]-mid>0) {
				cnt+=a[i]-mid;
			}
		}
		return cnt>=m;
	}
}
