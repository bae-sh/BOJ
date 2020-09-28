package 백준;
import java.util.*;
public class 다이얼5622번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		int ans=0;
		for(int i=0;i<s.length();i++) {
			char c=s.charAt(i);
			if('A'<=c&&c<='C') {
				ans+=3;
			}else if('D'<=c&&c<='F') {
				ans+=4;
			}else if('G'<=c&&c<='I') {
				ans+=5;
			}else if('J'<=c&&c<='L') {
				ans+=6;
			}else if('M'<=c&&c<='O') {
				ans+=7;
			}else if('P'<=c&&c<='S') {
				ans+=8;
			}else if('T'<=c&&c<='V') {
				ans+=9;
			}else if('W'<=c&&c<='Z') {
				ans+=10;
			}
		}
		System.out.println(ans);
	}

}
