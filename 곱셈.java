import java.util.*;
public class 곱셈 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		long a=sc.nextInt();
		long b=sc.nextInt();
		long c=sc.nextInt();
		long ans=1;
		while(b>0) {
			if(b%2==1) {
				ans*=a;
				ans%=c;
			}
			a=(a*a)%c;
			b/=2;
		}
		System.out.println(ans);
		
	}

}
