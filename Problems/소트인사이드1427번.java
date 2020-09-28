package 백준;
import java.util.*;
public class 소트인사이드1427번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String x=sc.nextLine();
		int a[]=new int[x.length()];
		for(int i=0;i<x.length();i++) {
			a[i]=x.charAt(i);
		}
		Arrays.sort(a);
		for(int i=x.length()-1;i>=0;i--) {
			System.out.print(a[i]-'0');
		}
	}

}
