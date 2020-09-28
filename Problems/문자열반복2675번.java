package 백준;
import java.util.*;
public class 문자열반복2675번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			String s=sc.next();
			for(int j=0;j<s.length();j++) {
				for(int k=0;k<a;k++) {
					System.out.print(s.charAt(j));
				}
			}
			System.out.println();
		}
	}

}
