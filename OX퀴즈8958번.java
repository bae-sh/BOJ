package 백준;
import java.util.*;
public class OX퀴즈8958번 {
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		String a[]=new String[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.next();
			int ans=0;
			int b[]=new int[a[i].length()];
			for(int j=0;j<a[i].length();j++) {
				if(a[i].charAt(j)=='O'&&j==0) {
					ans++;
					b[j]=1;
					continue;
				}
				if(a[i].charAt(j)=='O') {
					b[j]=b[j-1]+1;
					ans+=b[j];
				}
			}
			System.out.println(ans);
		}
	}
}
