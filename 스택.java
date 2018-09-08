package 백준;

import java.util.*;
public class 스택 {

	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int n=sc.nextInt();
		Stack st = new Stack();
		for(int i=0;i<n;i++) {
			String x=sc.next();
			
			if(x.equals("push")) {
				int y=sc.nextInt();
				st.push(y);
			}
			else if(x.equals("pop")) {
				if(st.size()!=0)
				System.out.println(st.pop());
				else {
					System.out.println("-1");
				}
			}
			else if(x.equals("size")) {
				System.out.println(st.size());
			}
			else if(x.equals("empty")) {
				if(st.empty()) {
					System.out.println("1");
				}
				else {
					System.out.println("0");
				}
			}
			else if(x.equals("top")) {
				if(st.size()!=0) {
					System.out.println(st.peek());
				}
				else {
					System.out.println("-1");
				}
			}
			
			
		}
	}

}
