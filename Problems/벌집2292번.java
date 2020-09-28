package 백준;
import java.util.*;
public class 벌집2292번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int i=1;
		while(true) {
			if(n>3*i*(i-1)+1) {
				i++;
				continue;
			}
			System.out.println(i);
			break;
		}
	}

}
