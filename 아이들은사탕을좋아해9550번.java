package 백준;
import java.util.*;
public class 아이들은사탕을좋아해9550번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++) {
			int n=0;
			int a=sc.nextInt();
			int b=sc.nextInt();
			for(int j=0;j<a;j++) {
				int k=sc.nextInt();
				n+=k/b;
			}
			System.out.println(n);
			
		}
	}

}
