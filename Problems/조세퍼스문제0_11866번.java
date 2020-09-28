package 백준;
import java.util.*;
public class 조세퍼스문제0_11866번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		Queue q=new LinkedList();
		Queue q2=new LinkedList();
		int n=sc.nextInt();
		int m=sc.nextInt();
		List list=new LinkedList();
		for(int i=1;i<=n;i++) {
			q.add(i);
		}
		while(!q.isEmpty()) {
			for(int i=0;i<m-1;i++) {
				q.add(q.poll());
			}
			q2.add(q.poll());
		}
		System.out.print("<");
		while(!q2.isEmpty()) {
			System.out.print(q2.poll());
			if(!q2.isEmpty()) {
				System.out.print(", ");
			}
		}
		System.out.println(">");
	}

}
