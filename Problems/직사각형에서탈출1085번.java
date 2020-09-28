package 백준;
import java.util.*;
public class 직사각형에서탈출1085번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int x=sc.nextInt();
		int y=sc.nextInt();
		int w=sc.nextInt();
		int h=sc.nextInt();
		x=Math.min(x, Math.abs(x-w));
		y=Math.min(y, Math.abs(y-h));;
		System.out.println(Math.min(x, y));
	}

}
