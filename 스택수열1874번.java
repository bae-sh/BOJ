package 백준;
import java.util.*;
public class 스택수열1874번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		Stack<Integer> st=new Stack();
		int n=sc.nextInt();
		int a[]=new int[n];
		int d[]=new int[n+1];
		int j=0;
		int cnt=0;
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		Queue<String> q=new LinkedList();
		for(int i=1;i<=a[0];i++) {
			st.push(i);
			cnt=i;
			q.add("+");
		}
		while(j!=n) {
			if(st.isEmpty()) {
				st.push(++cnt);
				q.add("+");
				continue;
			}
			if(d[a[j]]!=0) {
				System.out.println("NO");
				System.exit(0);
			}
			if(a[j]==st.peek()) {
				q.add("-");
				d[a[j]]=1;
				st.pop();
				j++;
				continue;
			}else if(a[j]<st.peek()) {
				d[st.pop()]=1;
				q.add("-");
			}else if(a[j]>st.peek()) {
				st.push(++cnt);
				q.add("+");
			}
		}
		while(!q.isEmpty()){
			System.out.println(q.poll());
		}
		
	}

}
