import java.util.*;
public class 균형잡힌세상 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		while(true) {
			String s=sc.nextLine();
			Stack<String> st=new Stack();
			if(s.equals("."))
				break;
			for(int i=0;i<s.length();i++) {
				if(s.charAt(i)=='('||s.charAt(i)=='[') {
					st.push(s.charAt(i)+"");
				}else if(s.charAt(i)==')') {
					if(st.isEmpty()) {
						System.out.println("no");
						break;
					}
					else if(st.peek().charAt(0)!='(') {
						System.out.println("no");
						break;
					}else {
						st.pop();
					}
				}else if(s.charAt(i)==']') {
					if(st.isEmpty()) {
						System.out.println("no");
						break;
					}else if(st.peek().charAt(0)!='[') {
						System.out.println("no");
						break;
					}
					else {
						st.pop();
					}
				}else if(s.charAt(i)=='.') {
					if(st.isEmpty()) {
						System.out.println("yes");
					}else {
						System.out.println("no");
					}
					break;
				}
			}
		}
	}

}
