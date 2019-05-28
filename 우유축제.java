import java.util.*;
public class 우유축제 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		int cnt=0;
		for(int i=0;i<n;i++) {
			if(a[i]==cnt%3) {
				cnt++;
			}
		}
		System.out.println(cnt);
	}

}
