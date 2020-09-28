import java.util.*;
public class 완전제곱수1997번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int m=sc.nextInt();
		int n=sc.nextInt();
		int ans=0;
		int min=0;
		for(int i=0;i<=100;i++) {
			if(m<=i*i&&i*i<=n) {
				ans+=i*i;
				if(min==0) {
					min=i*i;
				}
			}
		}
		if(ans==0) {
			System.out.println(-1);
			System.exit(0);
		}
		System.out.println(ans+"\n"+min);
	}

}
