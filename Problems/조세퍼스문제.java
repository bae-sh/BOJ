package 백준;

import java.util.*;

public class 조세퍼스문제 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		Queue q= new LinkedList();
		int a=sc.nextInt();
		int b=sc.nextInt();
		for(int i=1;i<=a;i++) {
			q.offer(i);
		}
		System.out.print("<");
		while(!q.isEmpty()) {
			for(int i=0;i<b-1;i++) {
				q.offer(q.poll());
			}
			System.out.print(q.poll());
			if(!q.isEmpty()) {
				System.out.print(", ");
			}
		}
		System.out.println(">");
	}

}
