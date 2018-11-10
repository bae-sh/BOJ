package 백준;
import java.util.*;
public class 평균1546번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		double a[]=new double[n];
		double Max=0;
		double avg=0;
		for(int i=0;i<n;i++) {
			double x=sc.nextInt();
			a[i]=x;
			if(Max<a[i]) {
				Max=a[i];
			}
		}
		for(int i=0;i<n;i++) {
			a[i]=a[i]/Max*100;
			avg+=a[i];
		}
		System.out.println(avg/n);
	}

}
