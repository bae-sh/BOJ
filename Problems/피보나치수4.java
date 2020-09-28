import java.math.BigInteger;
import java.util.*;
public class 피보나치수4 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		BigInteger p[]=new BigInteger[10001];
		p[0]=new BigInteger("0");
		p[1]=new BigInteger("1");
		for(int i=2;i<10001;i++) {
			p[i]=new BigInteger("0");
			p[i]=p[i].add(p[i-1]);
			p[i]=p[i].add(p[i-2]);
		}
		System.out.println(p[n]);
	}

}
