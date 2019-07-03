import java.util.*;
public class 이항쇼다운 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		StringBuilder sb=new StringBuilder();
		while(true) {
			long n=sc.nextLong();
			long m=sc.nextLong();
			long ans=1;
			int div=1;
			if(n+m==0) {
				break;
			}else {
				if(n-m<m) {
					m=n-m;
				}
				while(m-->0) {
					ans*=n--;
					ans/=div++;
				}
				sb.append(ans+"\n");
			}
		}
		System.out.println(sb.toString());
	}

}
