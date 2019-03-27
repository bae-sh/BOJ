import java.util.*;
public class 관리자는누구 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[9];
		String s[]= {"PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY"};
		int ans=-1;
		int max=0;
		for(int i=0;i<9;i++) {
			for(int j=0;j<n;j++) {
				int x=sc.nextInt();
				if(max<x) {
					max=x;
					ans=i;
				}
			}
		}
		System.out.println(s[ans]);
		
	}

}
