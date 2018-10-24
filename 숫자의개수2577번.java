package 백준;
import java.util.*;
public class 숫자의개수2577번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int ans[]=new int[10];
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		String k=Integer.toString(a*b*c);
		for(int i=0;i<k.length();i++) {
			int x=k.charAt(i)-'0';
			ans[x]++;
		}
		for(int i=0;i<=9;i++) {
			System.out.println(ans[i]);
		}
	}

}
