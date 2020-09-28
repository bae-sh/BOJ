package 백준;
import java.util.*;
public class 평균점수10039번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a[]=new int[5];
		int avg=0;
		for(int i=0;i<5;i++) {
			int b=sc.nextInt();
			if(b<40) {
				a[i]=40;
			}
			else {
				a[i]=b;
			}
			avg+=a[i];
		}
		System.out.println(avg/5);
	}

}
