import java.util.*;

public class 검열3111 {
	static boolean lt = true;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		String sr = "";
		for (int i = s.length() - 1; i >= 0; i--) {
			sr += s.charAt(i);
		}
		String a = sc.nextLine();
		Stack l = new Stack();
		Stack r = new Stack();
		int R_index = 0;
		int L_index = a.length() - 1;
		int cnt = 0;
		while (cnt != a.length()) {
			if (lt) {
				String c = a.charAt(R_index) + "";
				l.push(c);
				solve(c, s, l);
				R_index++;
			} else {
				String c = a.charAt(L_index) + "";
				r.push(c);
				solve(c, sr, r);
				L_index--;
			}
			cnt++;

		}
		while (!l.isEmpty()) {
			String c=(String)l.pop();
			r.push(c);
			solve(c,sr,r);
		}
		while (!r.isEmpty()) {
			System.out.print(r.pop());
		}

	}

	static void solve(String c, String s, Stack l) {

		if (c.equals(s.charAt(s.length() - 1) + "")) {
			if (l.size() >= s.length()) {
				String t = "";
				for (int i = l.size() - s.length(); i < l.size(); i++) {
					t += l.get(i);
				}
				if (t.equals(s)) {
					for (int i = 0; i < s.length(); i++) {
						l.pop();
					}
					lt = !lt;
				}
			}
		}
	}
}
