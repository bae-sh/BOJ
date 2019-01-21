package 백준;
import java.util.*;
public class 약수구하기2501번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		int cnt=0;
		for(int i=1;i<=n;i++) {
			if(n%i==0) {
				cnt++;
				if(k==cnt) {
					System.out.println(i);
					System.exit(0);
				}
			}
		}
		System.out.println(0);
	}

}
