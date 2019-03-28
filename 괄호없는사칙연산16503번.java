import java.util.*;
public class 괄호없는사칙연산16503번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String[] s=sc.nextLine().split(" ");
		int a=Integer.parseInt(s[0]);
		int b=Integer.parseInt(s[2]);
		int c=Integer.parseInt(s[4]);
		
		int ans1=solve(solve(a,b,s[1]),c,s[3]);
		int ans2=solve(a,solve(b,c,s[3]),s[1]);
		if(ans1>ans2) {
			System.out.println(ans2);
			System.out.println(ans1);
		}else {
			System.out.println(ans1);
			System.out.println(ans2);
		}
		
	}
	public static int solve(int a,int b,String s) {
		if(s.equals("+")) {
			return a+b;
		}else if(s.equals("-")) {
			return a-b;
		}else if(s.equals("*")) {
			return a*b;
		}else {
			return a/b;
		}
	}
}
