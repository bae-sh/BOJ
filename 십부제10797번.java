package 백준;
import java.util.*;
public class 십부제10797번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int cnt=0;
		for(int i=0;i<5;i++) {
			int b=sc.nextInt();
			if(a==b) {
				cnt++;
			}
		}
		System.out.println(cnt);
	}

}
