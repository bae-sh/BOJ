import java.util.*;
public class 손익분기점 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		if(b==c) {
			System.out.println(-1);
			return;
		}
		int x=a/(c-b);
		if(x<0) {
			System.out.println(-1);
		}else {
			System.out.println(x+1);
		}
	}

}
