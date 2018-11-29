package 백준;
import java.util.*;
public class 로마숫자2608번 {
	static int ans=0;
	static void cal(String a) {
		for(int i=0;i<a.length();i++) {
			if(a.charAt(i)=='I') {
				if(i!=a.length()-1) {
					if(a.charAt(i+1)=='V') {
						ans+=4;
						i++;
					}
					else if(a.charAt(i+1)=='X') {
						ans+=9;
						i++;
					}
					else {
						ans++;
					}
				}
				else {
					ans++;
				}
				continue;
			}
			if(a.charAt(i)=='V') {
				ans+=5;
				continue;
			}
			if(a.charAt(i)=='X') {
				if(i!=a.length()-1) {
					if(a.charAt(i+1)=='L') {
						ans+=40;
						i++;
					}
					else if(a.charAt(i+1)=='C') {
						ans+=90;
						i++;
					}
					else {
						ans+=10;
					}
				}
				else {
					ans+=10;
				}
				continue;
			}
			if(a.charAt(i)=='L') {
				ans+=50;
				continue;
			}
			if(a.charAt(i)=='C') {
				if(i!=a.length()-1) {
					if(a.charAt(i+1)=='D') {
						ans+=400;
						i++;
						continue;
					}
					else if(a.charAt(i+1)=='M') {
						ans+=900;
						i++;
						continue;
					}
					else {
						ans+=100;
					}
				}
				else {
					ans+=100;
				}
				continue;
			}
			if(a.charAt(i)=='D') {
				ans+=500;
				continue;
			}
			if(a.charAt(i)=='M') {
				ans+=1000;
				continue;
			}
			
		}
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a=sc.next();
		String b=sc.next();
		cal(a);
		cal(b);
		System.out.println(ans);
		while(ans!=0) {
			if(ans-1000>=0) {
				System.out.print('M');
				ans-=1000;
				continue;
			}
			else if((ans-900>=0)) {
				System.out.print("CM");
				ans-=900;
				continue;
			}
			else if((ans-500>=0)) {
				System.out.print('D');
				ans-=500;
				continue;
			}
			else if((ans-400>=0)) {
				System.out.print("CD");
				ans-=400;
				continue;
			}
			else if((ans-100>=0)) {
				System.out.print("C");
				ans-=100;
				continue;
			}
			else if((ans-90>=0)) {
				System.out.print("XC");
				ans-=90;
				continue;
			}
			else if((ans-50>=0)) {
				System.out.print("L");
				ans-=50;
				continue;
			}
			else if((ans-40>=0)) {
				System.out.print("XL");
				ans-=40;
				continue;
			}
			else if((ans-10>=0)) {
				System.out.print("X");
				ans-=10;
				continue;
			}
			else if((ans-9>=0)) {
				System.out.print("IX");
				ans-=9;
				continue;
			}
			else if((ans-5>=0)) {
				System.out.print("V");
				ans-=5;
				continue;
			}
			else if((ans-4>=0)) {
				System.out.print("IV");
				ans-=4;
				continue;
			}
			else if((ans-1>=0)) {
				System.out.print("I");
				ans-=1;
				continue;
			}
		}
		
	}

}
