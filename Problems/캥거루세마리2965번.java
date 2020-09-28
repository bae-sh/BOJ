package 백준;
import java.util.*;
public class 캥거루세마리2965번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		int ans=0;
		while(!(b-a==1&&c-b==1)) {
			if(b-a>=c-b) {
				c=b;
				b=a+1;
				
			}else {
				a=b;
				b=a+1;
			}
			ans++;
		}
		System.out.println(ans);
	}

}
