package 백준;
import java.util.*;
public class 영수증5565번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=0;
		for(int i=0;i<9;i++) {
			b+=sc.nextInt();
		}
		System.out.println(a-b);
	}

}
