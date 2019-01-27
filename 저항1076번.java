package 백준;
import java.util.*;
public class 저항1076번{
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		String a[]=new String[3];
		String ans="";
		for(int i=0;i<2;i++) {
			a[i]=sc.next();
			if(a[i].equals("black")&&i!=0) {
				ans+="0";
			}else if(a[i].equals("brown")) {
				ans+="1";
			}else if(a[i].equals("red")) {
				ans+="2";
			}else if(a[i].equals("orange")) {
				ans+="3";
			}else if(a[i].equals("yellow")) {
				ans+="4";
			}else if(a[i].equals("green")) {
				ans+="5";
			}else if(a[i].equals("blue")) {
				ans+="6";
			}else if(a[i].equals("violet")) {
				ans+="7";
			}else if(a[i].equals("grey")) {
				ans+="8";
			}else if(a[i].equals("white")) {
				ans+="9";
			}
		}
		if(Integer.parseInt(ans)==0) {
			System.out.println(0);
			System.exit(0);
		}
		a[2]=sc.next();
		if(a[2].equals("black")) {
			ans+="";
		}else if(a[2].equals("brown")) {
			ans+="0";
		}else if(a[2].equals("red")) {
			ans+="00";
		}else if(a[2].equals("orange")) {
			ans+="000";
		}else if(a[2].equals("yellow")) {
			ans+="0000";
		}else if(a[2].equals("green")) {
			ans+="00000";
		}else if(a[2].equals("blue")) {
			ans+="000000";
		}else if(a[2].equals("violet")) {
			ans+="0000000";
		}else if(a[2].equals("grey")) {
			ans+="00000000";
		}else if(a[2].equals("white")) {
			ans+="000000000";
		}
		System.out.println(ans);
	}
}