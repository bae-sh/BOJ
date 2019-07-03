import java.util.*;
public class 백대열 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		StringTokenizer str=new StringTokenizer(s, ":");
		int a=Integer.parseInt(str.nextToken());
		int b=Integer.parseInt(str.nextToken());
		int c=gcd(a,b);
		System.out.println(a/c+":"+(b/c));
	}
	public static int gcd(int a,int b) {
		if(b==0)
			return a;
		else
			return gcd(b,a%b);
	}
}
