import java.util.*;
public class 회전하는큐 {
	static int ans=0;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		Queue<Integer> q=new LinkedList();
		int n=sc.nextInt();
		int m=sc.nextInt();
		for(int i=1;i<=n;i++) {
			q.add(i);
		}
		for(int i=0;i<m;i++) {
			go(q,sc.nextInt());
		}
		System.out.println(ans);
	}
	static void go(Queue<Integer> q,int n) {
		Queue<Integer> q2=new LinkedList();
		Stack<Integer> st=new Stack<>();
		while(q.peek()!=n) {
			q2.add(q.poll());
		}
		q.poll();
		if(q2.size()<=q.size()) {
			ans+=q2.size();
			while(!q2.isEmpty()) {
				q.add(q2.poll());
			}
		}else {
			ans+=q.size()+1;
			while(!q2.isEmpty()) {
				q.add(q2.poll());
			}
		}
	}
}
