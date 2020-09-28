import java.util.*;
public class 중앙이동알고리즘 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int d[]=new int[n+1];
		d[0]=2;
		for(int i=1;i<=n;i++) {
			d[i]=2*d[i-1]-1;
		}
		System.out.println(d[n]*d[n]);
	}

}
