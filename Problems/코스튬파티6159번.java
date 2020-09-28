package 백준;
import java.util.*;
public class 코스튬파티6159번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int s=sc.nextInt();
		int a[]=new int[n];
		int cnt=0;
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				if(a[i]+a[j]<=s) {
					cnt++;
				}
			}
		}
		System.out.println(cnt);
	}

}
