package 백준;

import java.util.*;

public class 암호코드 {
	public static int mod=1000000;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String n=sc.next();
		int d[]=new int[n.length()+1];
		String s=" "+n;
		d[0]=1;
		
		for(int i=1;i<=n.length();i++) {
			int x=s.charAt(i)-'0';
			if(1<=x&&x<=9) {
				d[i]+=d[i-1];
				d[i]%=mod;
			}
			if(i==1) continue;
			if(s.charAt(i-1)=='0') continue;
			x=(s.charAt(i-1)-'0')*10+s.charAt(i)-'0';
			if(10<=x&&x<=26) {
				d[i]+=d[i-2];
				d[i]%=mod;
			}
		}
		System.out.println(d[n.length()]);
		
		
	
	}

}
