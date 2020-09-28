import java.util.*;

public class 괄호의값 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] s = sc.nextLine().split("");
		Stack<String> st = new Stack<>();
		int ans = 0;
		int cir = 0;
		int rec = 0;
		int temp = 1;
		boolean t = false;
		for (int i = 0; i < s.length; i++) {
			if (s[i].equals("(")) {
				st.push("(");
				cir++;
				t = true;
			} else if (s[i].equals("[")) {
				st.push("[");
				rec++;
				t = true;
			} else if (s[i].equals(")")) {
				if (st.isEmpty()) {
					System.out.println(0);
					System.exit(0);
				} else if (!st.peek().equals("(")) {
					System.out.println(0);
					System.exit(0);
				} else {
					if (t) {
						ans += (int) Math.pow(2, cir) * (int) Math.pow(3, rec);
					}
					st.pop();
					cir--;
					t = false;
				}
			} else if (s[i].equals("]")) {
				if (st.isEmpty()) {
					System.out.println(0);
					System.exit(0);
				} else if (!st.peek().equals("[")) {
					System.out.println(0);
					System.exit(0);
				} else {
					if (t) {
						ans += (int) Math.pow(2, cir) * (int) Math.pow(3, rec);
					}
					st.pop();
					rec--;
					t = false;
				}
			}
		}
		if (!st.isEmpty()) {
			System.out.println(0);
		} else {
			System.out.println(ans);
		}

	}

}
