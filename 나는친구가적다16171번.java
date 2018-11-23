package 백준;
import java.util.*;
public class 나는친구가적다16171번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String x=sc.nextLine();
		String y=sc.nextLine();
		char a[]=new char[x.length()];
		int cnt=0;
		for(int i=0;i<x.length();i++) {
			if('0'<=x.charAt(i)&&x.charAt(i)<='9') {
				continue;
			}
			a[cnt++]=x.charAt(i);
		}
		cnt=0;
		for(int i=0;i<x.length();i++) {
			if(y.charAt(cnt)==a[i]) {
				int k=i;
				for(int j=0;j<y.length();j++) {
					if(y.charAt(cnt)!=a[k]) {
						System.out.println(0);
						System.exit(0);
					}
					cnt++;
					k++;
				}
				break;
				
			}
			System.out.println(0);
			System.exit(0);
		}
		System.out.println(1);
		System.exit(0);
	}

}
