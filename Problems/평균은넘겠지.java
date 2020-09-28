package 백준;
import java.util.*;
public class 평균은넘겠지 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			int x=sc.nextInt();
			double xx=x;
			double avg=0;
			double a[]=new double[x];
			for(int j=0;j<x;j++) {
				a[j]=sc.nextInt();
				avg+=a[j];
			}
			avg/=x;
			int cnt=0;
			for(double j:a) {
				if(j>avg) cnt++;
			}
			System.out.format("%.3f",cnt/xx*100);
			System.out.println("%");
		}
	}

}
