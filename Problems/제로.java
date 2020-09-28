import java.util.*;
public class 제로 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int k=sc.nextInt();
		Stack<Integer> st=new Stack();
		while(k-->0) {
			int n=sc.nextInt();
			if(n==0) {
				st.pop();
			}else {
				st.push(n);
			}
		}
		int ans=0;
		while(!st.isEmpty()) {
			ans+=st.pop();
		}
		System.out.println(ans);
	}

}
