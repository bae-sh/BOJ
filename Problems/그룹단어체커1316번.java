package 백준;

import java.util.*;

public class 그룹단어체커1316번 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int d[] = new int[26];
			String a = sc.next();
			int cn = 1;
			for (int j = 0; j < a.length() - 1; j++) {
				if (a.charAt(j) != a.charAt(j + 1)) {
					if (d[a.charAt(j) - 'a'] != 0 || d[a.charAt(j + 1) - 'a'] != 0) {
						break;
					} else {
						d[a.charAt(j) - 'a'] += cn;
						cn = 1;
					}
				} else {
					cn++;
				}
				if (j == a.length() - 2) {
					cnt++;
				}
			}
			if(a.length()==1) {
				cnt++;
			}
		}
		System.out.println(cnt);
	}

}
