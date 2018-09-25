package 백준;

import java.util.*;
public class 팩토리얼0의개수1676번 {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int s=0;
		long d[]=new long[501];
		int a=n;
		d[0]=1;
		for(int l=0;l<=a;l++) {
			n=l;
			s=0;
		for(int i=1;i<=n;i++) {
			d[i]=d[i-1]*i;
			String k=Long.toString(d[i]);
			for(int j=0;j<k.length();j++) {
			if(k.charAt(k.length()-1-j)!='0') {
				d[i]=Long.parseLong(k.charAt(k.length()-1-j)+"");
				break;
			}
			s++;
		}
		}
		System.out.println(l+": "+s);
		}
	}

}
