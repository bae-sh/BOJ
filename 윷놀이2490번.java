package 백준;
import java.util.*;
public class 윷놀이2490번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		for(int i=0;i<3;i++) {
			int a=0;
			for(int j=0;j<4;j++) {
			int n=sc.nextInt();
				if(n==0) {
				a++;
				}
			}
			if(a==0) {
				System.out.println("E");
			}else if(a==1) {
				System.out.println("A");
			}else if(a==2) {
				System.out.println("B");
			}else if(a==3) {
				System.out.println("C");
			}else if(a==4) {
				System.out.println("D");
			}
			
		}
	}

}
