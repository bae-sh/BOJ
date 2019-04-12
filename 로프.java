import java.util.*;
public class 로프 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		Arrays.sort(a);
		int ans=0;
		for(int i=0;i<n;i++) {
			ans=Math.max(a[i]*(n-i), ans);
		}
		System.out.println(ans);
	}

}
