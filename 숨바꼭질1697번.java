package 백준;
import java.util.*;
public class 숨바꼭질1697번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		int a=k;
		int cnt=0;
		while(true) {
			if(a<=n) {
				cnt=cnt+n-a;
				break;
			}
			if(a%2==0) {
				a/=2;
				cnt++;
				continue;
			}
			else {
				a-=1;
				cnt++;
			}
		}
		System.out.println(cnt);
	}

}
