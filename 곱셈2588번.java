package 백준;
import java.util.*;
public class 곱셈2588번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		String b=sc.next();
		for(int i=0;i<3;i++) {
			int x=Integer.parseInt(b.charAt(2-i)+"");
			System.out.println(a*x);
			}
		int x=Integer.parseInt(b);
		System.out.println(a*x);
	}

}
