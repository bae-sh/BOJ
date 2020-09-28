import java.util.*;
public class 순열의순서1722번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		StringBuilder sb=new StringBuilder();
		ArrayList<Integer> a=new ArrayList();
		int cnt=0;
		for(int i=1;i<=n;i++) {
			a.add(i);
		}
		if(k==1) {
			long num=sc.nextLong();
			for(int i=n-1;i>=0;i--) {
				if(num-fac(i)>0) {
					num-=fac(i);
					i=i+1;
					cnt++;
				}else {
					sb.append(a.remove(cnt)+" ");
					
					cnt=0;
				}
			}
		}else if(k==2) {
			long ans=1;
			for(int i=n-1;i>=0;i--) {
				int m=sc.nextInt();
				ans+=a.indexOf(m)*fac(i);
				a.remove(a.indexOf(m));
			}
			sb.append(ans);
		}
		System.out.println(sb.toString());
	}
	public static long fac(long n) {
		if(n==0) return 1;
		else
			return fac(n-1)*n;
	}
}
