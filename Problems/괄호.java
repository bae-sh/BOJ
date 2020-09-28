package 백준;

import java.util.*;

public class 괄호 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		String x[] = new String[n];
		boolean p[] = new boolean[n];
		int a = 0;// '('의 개수
		int b = 0;// ')'의 개수

		for (int i = 0; i < n; i++) {
			x[i] = sc.nextLine();
		}
		for (int i = 0; i < n; i++) {
			if (x[i].length() % 2 != 0) {
				p[i] = false;
				continue;
			}
			for (int j = 0; j < x[i].length(); j++) {
				if (x[i].charAt(j) == '(') {
					a++;
				} else if (x[i].charAt(j) == ')') {
					b++;
				}
				if (a < b) {
					p[i] = false;
					a = 0;
					b = 0;
					break;
				} else {
					p[i] = true;
				}
			}
			
			if(a!=b) {
				p[i]=false;
			}
			a = 0;
			b = 0;
		}

		for (int i = 0; i < n; i++) {
			if (p[i] == true) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}
	}

}
