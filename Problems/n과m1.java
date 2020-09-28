import java.util.*;

public class n과m1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		String s = "";
		int p[] = new int[n + 1];
		print(n, m, s,p);

	}

	public static void print( int end, int m, String s, int p[]) {
		if (m <= 0) {
			System.out.println(s);
		}else {
			for (int i = 1; i <= end; i++) {
				if(p[i]==0) {//사용안했으면
					p[i]=1;
					if(s.equals("")) {
						print(end, m-1,i+"",p);
					}else {
						print(end, m-1, s+" "+i,p);
					}
					p[i]=0;
				}
			}
		}
	}
}
