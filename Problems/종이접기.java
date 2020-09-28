import java.util.*;
public class 종이접기 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long ans=0;
		for(int i=0;i<n*n;i++) {
			ans+=sc.nextInt();
		}
		System.out.println(ans);
	}

}
