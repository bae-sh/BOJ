package 백준;
import java.util.*;
public class 다면체10569번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			int b=sc.nextInt();
			int c=2-a+b;
			System.out.println(c);
		}
	}

}
