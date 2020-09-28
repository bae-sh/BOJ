import java.util.*;

public class 숫자30 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		int check = 0;
		int a[] = new int[s.length()];
		for (int i = 0; i < s.length(); i++) {
			int k = Integer.parseInt(s.charAt(i) + "");
			check += k;
			a[i] = k;
		}
		if (check % 3 != 0)
			System.out.println(-1);
		else {
			Arrays.sort(a);
			if (a[0] != 0)
				System.out.println(-1);
			else {
				for(int i=a.length-1;i>=0;i--) {
					System.out.print(a[i]);
				}
			}
		}
	}

}
