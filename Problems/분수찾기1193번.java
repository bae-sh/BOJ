package 백준;
import java.util.*;
public class 분수찾기1193번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int i=0;
		
		while(true) {
			if(i*(i+1)/2<n) {
				i++;
				continue;
			}
			break;
		}
		int k=i*(i+1)/2-n;
		if(i%2!=0) {
			int a=1+k;
			int b=i-k;
			System.out.println(a+"/"+b);
		}
		else {
			int a=1+k;
			int b=i-k;
			System.out.println(b+"/"+a);
		}
		
	}

}
