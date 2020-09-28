package 백준;
import java.util.*;
public class 셀프넘버4673번 {
	static int self(String a) {
		int x=Integer.parseInt(a);
		for(int i=0;i<a.length();i++) {
			x+=a.charAt(i)-'0';
		}
		return x;
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int d[]=new int[20000];
		for(int i=1;i<=10000;i++) {
			d[self(Integer.toString(i))]=1;
		}
		for(int i=1;i<=10000;i++) {
			if(d[i]==0) {
				System.out.println(i);
			}
		}
	}

}
