import java.util.Scanner;

public class n과m2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String s = "";
		print(1, n, m, s);

	}

	public static void print(int start, int end, int m, String s) {
		if (m <= 0) {
			System.out.println(s);
		} else if (start > end) {
			return;
		} else {
			if (s.equals("")) {
				print(start + 1, end, m - 1, start + "");
				print(start + 1, end, m, s);
			} else {
				print(start + 1, end, m - 1, s + " " + start);
				print(start + 1, end, m, s);
			}
		}

	}
}
