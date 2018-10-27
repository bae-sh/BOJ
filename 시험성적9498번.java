package 백준;
import java.util.*;
public class 시험성적9498번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		if(90<=n&&n<=100) {
			System.out.println("A");
		}
		else if(80<=n&&n<=89) {
			System.out.println("B");
		}
		else if(70<=n&&n<=79) {
			System.out.println("C");
		}
		else if(60<=n&&n<=69) {
			System.out.println("D");
		}
		else {
			System.out.println("F");
		}
	}

}
