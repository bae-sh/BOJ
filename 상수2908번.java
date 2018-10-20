package 백준;
import java.util.*;
public class 상수2908번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a=sc.next();
		String b=sc.next();
		String aa="";
		String bb="";
		for(int j=2;j>=0;j--) {
				aa+=a.charAt(j);
		}
		int aaa=Integer.parseInt(aa);
		for(int j=2;j>=0;j--) {
			bb+=b.charAt(j);
	}
		int bbb=Integer.parseInt(bb);
		System.out.println(aaa>bbb?aaa:bbb);
	}

}
