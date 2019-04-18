import java.util.*;

public class 문자열폭발9935 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		String ans = sc.nextLine();
		StringBuilder sb = new StringBuilder();
		Deque<Pair9935> d = new LinkedList();
		if (ans.length() == 1) {
			for (int i = 0; i < ans.length(); i++) {
				if ((s.charAt(i) + "").equals(ans)) {
					continue;
				} else {
					sb.append(s.charAt(i));
				}
			}
		} else {
			for (int i = 0; i < s.length(); i++) {
				String c = s.charAt(i) + "";
				if(c.equals(ans.charAt(0)+"")){
					d.add(new Pair9935(i, 0));
				}
				else if (d.isEmpty()) {
					sb.append(c);
				} else {
					Pair9935 p = d.getLast();
					for (int j = 1; j < ans.length(); j++) {
						if (c.equals(ans.charAt(j) + "")) {
							if (p.p + 1 == j) {
								if (j == ans.length() - 1) {
									for (int k = 0; k < ans.length() - 1; k++) {
										d.removeLast();
									}
								} else {
									d.add(new Pair9935(i, j));
								}
							} else {
								d.add(new Pair9935(i, j));
								while (!d.isEmpty()) {
									sb.append(s.charAt(d.poll().index));
								}
								break;
							}
						} else if (j == ans.length() - 1) {
							d.add(new Pair9935(i, j));
							while (!d.isEmpty()) {
								sb.append(s.charAt(d.poll().index));
							}
						}
					}
				}
			}
		}

		if (sb.length() == 0) {
			System.out.println("FRULA");
		} else {
			System.out.println(sb.toString());
		}
	}

}

class Pair9935 {
	int index;
	int p;

	Pair9935(int index, int p) {
		this.index = index;
		this.p = p;
	}
}
