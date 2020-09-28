import java.util.*;

public class 세로읽기 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a[][] = new String[15][15];
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 5; i++) {
			String s[] = sc.nextLine().split("");
			for (int j = 0; j < s.length; j++) {
				a[i][j] = s[j];
			}
			for (int j = s.length; j < 15; j++) {
				a[i][j] = "";
			}
		}
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 5; j++) {
				sb.append(a[j][i]);
			}

		}
		System.out.println(sb.toString());

	}
}
