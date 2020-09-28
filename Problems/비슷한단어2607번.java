package 백준;
import java.util.*;
public class 비슷한단어2607번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int dp[]=new int[26];
		int d[]=new int[26];
		int n=sc.nextInt();
		int ans=0;
		String a=sc.next();
		for(int i=0;i<a.length();i++) {
			dp[a.charAt(i)-'A']++;
		}
		firstloop:
		for(int i=0;i<n-1;i++) {
			int cnt=0;
			String b=sc.next();
			d=Arrays.copyOf(dp, 26);
			if(Math.abs(b.length()-a.length())>1) {
				continue firstloop;
			}
			for(int j=0;j<b.length();j++) {
				d[b.charAt(j)-'A']--;
			}
			for(int j=0;j<d.length;j++) {
				if(d[j]!=0) {
					cnt++;
				}
				
			}for(int j=0;j<d.length;j++) {
				if(d[j]<-1||d[j]>1) {
					continue firstloop;
				}
				
			}
			
			if(cnt<=2) {
				ans++;
			}
		}
		System.out.println(ans);
	}

}
