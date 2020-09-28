package 백준;

import java.util.*;
public class 쇠막대기 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		Stack st = new Stack();
		String a=sc.nextLine();
		int sum=0;
		
		for(int i=0;i<a.length();i++) {
			if(a.charAt(i)=='(') {
				st.push('(');
			}
			else if(a.charAt(i)==')') {
				st.pop();
				if(a.charAt(i-1)=='(') {
					sum+=st.size();
				}
				else {
					sum+=1;
				}
			}
		}
		System.out.println(sum);
		
		
	}

}
