import java.util.*;
public class 고려대학교에는공식와인이있다 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int c=sc.nextInt();
		int k=sc.nextInt();
		int p=sc.nextInt();
		int ans=0;
		for(int i=0;i<=c;i++) {
			ans+=(k*i)+(p*i*i);
		}
		System.out.println(ans);
	}

}
