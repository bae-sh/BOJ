package 백준;
import java.util.*;
public class 막대기1094번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int x=sc.nextInt();
		int n=0;
		int cnt=0;
		int a=64;
		while(true) {
			if(x==n+a) {
				cnt++;
				break;
			}
			a/=2;
			if(x>n+a) {
				n+=a;
				cnt++;
				continue;
			}
			else if(x<n+a){
				continue;
			}
		}
		System.out.println(cnt);
	}

}
