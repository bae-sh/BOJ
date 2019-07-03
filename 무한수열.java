import java.util.*;
public class 무한수열 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();
		long p=sc.nextLong();
		long q=sc.nextLong();
		System.out.println(go(n,p,q));
		
	}
	static long go(long n,long p,long q) {
		if(n==0) {
			return 1;
		}else if(n==1){
			return 2;
		}else {
			return go(n/p,p,q)+go(n/q,p,q);
		}
	}
}
