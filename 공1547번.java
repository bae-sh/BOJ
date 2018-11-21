package 백준;
import java.util.*;
public class 공1547번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[4];
		a[1]=1;
		for(int i=0;i<n;i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			int temp=a[x];
			a[x]=a[y];
			a[y]=temp;
		}
		for(int i=1;i<=3;i++) {
			if(a[i]==1) {
				System.out.println(i);
				System.exit(0);
			}
		}
	}

}
