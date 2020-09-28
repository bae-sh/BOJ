import java.util.*;
public class 암호만들기1759번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int l=sc.nextInt();
		int c=sc.nextInt();
		sc.nextLine();
		String[] s=sc.nextLine().split(" ");
		Arrays.sort(s);
		go(l,s,"",0);
	}
	public static void go(int n,String[] s,String pass,int index) {
		if(pass.length()==n) {
			if(check(pass)) {
				System.out.println(pass);
			}
			return ;
		}
		if(index>=s.length) return;
		go(n,s,pass+s[index],index+1);
		go(n,s,pass,index+1);
	}
	public static boolean check(String pass) {
		int ja=0;
		int mo=0;
		char[] c=pass.toCharArray();
		for(char x:c) {
			if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u') {
				mo++;
			}else {
				ja++;
			}
		}
		return ja>=2&&mo>=1;
	}
}
