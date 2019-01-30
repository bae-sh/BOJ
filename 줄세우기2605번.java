package 백준;
import java.util.*;
public class 줄세우기2605번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int d[]=new int[n];
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			d[i]=i+1;
			for(int j=0;j<a;j++) {
				int temp=d[i-j];
				d[i-j]=d[i-j-1];
				d[i-j-1]=temp;
			}
		}
		for(int a:d) {
			System.out.print(a+" ");
		}
		
	}

}
