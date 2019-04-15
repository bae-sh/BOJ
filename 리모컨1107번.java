import java.util.*;
public class 리모컨1107번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		int c=Integer.parseInt(s);
		
		int n=sc.nextInt();
		int ans=1000000;
		boolean b[]=new boolean[10];
		for(int i=0;i<10;i++) {
			b[i]=true;
		}
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			b[a]=false;
		}
		for(int i=c;i>=0;i--) {
			if(sol(Integer.toString(i),b)) {
				ans=Math.min(Math.abs(c-i)+Integer.toString(i).length(), ans);
				break;
			}
		}
		int x=ans;
		for(int i=c;i<=x+c;i++) {
			if(sol(Integer.toString(i),b)) {
				ans=Math.min(Math.abs(c-i)+Integer.toString(i).length(), ans);
				break;
			}
		}
		ans=Math.min(Math.abs(c-100), ans);
		System.out.println(ans);
	}
	public static boolean sol(String s,boolean[] b) {
		for(int i=0;i<s.length();i++) {
			int index=Integer.parseInt(s.charAt(i)+"");
			if(b[index]) {
				continue;
			}else {
				return false;
			}
		}
		return true;
	}
}
