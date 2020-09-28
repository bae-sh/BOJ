package 백준;

import java.util.*;
public class 덱 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		Deque d = new LinkedList();
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			String x=sc.next();
			if(x.equals("push_front")) {
				int y=sc.nextInt();
				d.offerFirst(y);
			}
			else if(x.equals("push_back")) {
				int y=sc.nextInt();
				d.offerLast(y);
			}
			else if(x.equals("pop_front")) {
				if(!d.isEmpty()) {
					System.out.println(d.pollFirst());
				}
				else
					System.out.println(-1);
			}
			else if(x.equals("pop_back")) {
				if(!d.isEmpty()) {
					System.out.println(d.pollLast());
				}
				else
					System.out.println(-1);
			}
			else if(x.equals("size")) {
				System.out.println(d.size());
			}
			else if(x.equals("front")) {
				if(!d.isEmpty()) {
					System.out.println(d.peekFirst());
				}
				else
					System.out.println(-1);
			}
			else if(x.equals("back")) {
				if(!d.isEmpty()) {
					System.out.println(d.peekLast());
				}
				else
					System.out.println(-1);
			}
			else if(x.equals("empty")) {
				if(d.isEmpty()) {
					System.out.println(1);
				}
				else
					System.out.println(0);
			}
		}

	}

}
