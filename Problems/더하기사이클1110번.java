package 백준;
import java.util.*;
public class 더하기사이클1110번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String n=sc.nextLine();
		if(n.length()<2) {
			n+="0";
		}
		int cnt=0;
		String ans=n;
		while(true) {
			int x=ans.charAt(0)-'0'+ans.charAt(1)-'0';
			String c=Integer.toString(x);
			ans=""+ans.charAt(1)+c.charAt(c.length()-1);
			cnt++;
			if(ans.equals(n)) break;
		}
		System.out.println(cnt);
	}

}
