package 백준;

import java.util.*;
public class 진법변환2 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int b=sc.nextInt();
		Stack st= new Stack();
		
		while(n!=0) {
			if(n%b>=10) {
				char x=(char)(n%b+55);
				st.push(x);
			}
			else {
				st.push(n%b);
			}
			n=n/b;
			
		}
		while(!st.isEmpty()) {
			System.out.print(st.pop());
		}
	}

}
