import java.util.*;

public class 스타트링크5014번 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int f = sc.nextInt();
		int s = sc.nextInt();
		int g = sc.nextInt();
		int u = sc.nextInt();
		int d = sc.nextInt();
		int ans[] = new int[f + 1];
		boolean check[] = new boolean[f + 1];

		Queue<Integer> q = new LinkedList<>();
		q.add(s);
		check[s] = true;
		while (!q.isEmpty()) {
			int start = q.remove();
			if (start == g) {
				System.out.println(ans[start]);
				System.exit(0);
			}
			if (start - d > 0 && check[start - d] == false) {
				q.add(start-d);
				check[start - d] = true;
				ans[start - d] = ans[start] + 1;
			}
			if (start + u <=f && check[start + u] == false) {
				q.add(start+u);
				check[start + u] = true;
				ans[start + u] = ans[start] + 1;
			}
			
		}
		System.out.println("use the stairs");
	}

}
