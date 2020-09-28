import java.util.*;
public class 병든나이트1783번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		if(n==1)
			System.out.println(1);
		else if(n==2)
			System.out.println(Math.min(4, (m+1)/2));
		else if(n>=3) {
			if(m<7)
				System.out.println(Math.min(4, m));
			else if(m>=7)
				System.out.println(m-2);
		}
	}

}
