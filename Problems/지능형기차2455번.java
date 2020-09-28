package 백준;
import java.util.*;
public class 지능형기차2455번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a[][]=new int[4][2];
		for(int i=0;i<4;i++) {
			a[i][0]=sc.nextInt();
			a[i][1]=sc.nextInt();
		}
		int Max=a[0][1];
		int n=a[0][1];
		for(int i=1;i<4;i++) {
			n=n-a[i][0]+a[i][1];
			Max=Math.max(Max, n);
		}
		System.out.println(Max);
	}

}
