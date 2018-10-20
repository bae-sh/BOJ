package 백준;
import java.util.*;
public class 설탕배달2839번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=5;
		int b=3;
		int x=sc.nextInt();
		int c=0;
		for(int i=0;5*i<=x;i++) {
			for(int j=0;(3*j+5*i)<=x;j++) {
				if((3*j+5*i)==x) {
					c=j+i;
				}
			}
		}
		if(c==0) {
			c=-1;
		}
		System.out.println(c);
	}

}
