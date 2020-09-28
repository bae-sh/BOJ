package 백준;
import java.util.*;
public class 괄호의값2504번 {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		Stack st=new Stack();
		String s=sc.nextLine();
		int n=1;
		int ans=0;
		for(int i=0;i<s.length();i++) {
			
			if(s.charAt(i)=='(') {
				st.push('(');
				n*=2;
			}else if(s.charAt(i)=='[') {
				st.push('[');
				n*=3;
			}else if(s.charAt(i)==')') {
				if(!st.peek().equals('(')) {
					System.out.println(0);
					System.exit(0);
				}
				else {
					st.pop();
					ans+=n;
					n/=2;
					
				}
				
			}else if(s.charAt(i)==']') {
				if(!st.pop().equals('[')) {
					System.out.println(0);
					System.exit(0);
				}else {
					st.pop();
					ans+=n;
					n/=3;
				}
			}
			
		}
		System.out.println(ans);
	}

}
