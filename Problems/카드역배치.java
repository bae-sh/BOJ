import java.util.*;
public class 카드역배치 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int d[]= new int[20];
		for(int i=0;i<20;i++) {
			d[i]=i+1;
		}
		for(int i=0;i<10;i++) {
			int a=sc.nextInt()-1;
			int b=sc.nextInt()-1;
			swap(a,b,d);
		}
		for(int i:d) {
			System.out.print(i+" ");
		}
		
	}
	static void swap(int a,int b,int d[]) {
		for(int i=0;i<=(b-a)/2;i++) {
			int temp=d[a+i];
			d[a+i]=d[b-i];
			d[b-i]=temp;
		}
	}
}
