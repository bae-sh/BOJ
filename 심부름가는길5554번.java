package 백준;
import java.util.*;
public class 심부름가는길5554번 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		int d=sc.nextInt();
		a=a+b+c+d;
		System.out.println(a/60);
		System.out.println(a%60);
	}

}
