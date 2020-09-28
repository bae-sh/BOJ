import java.util.*;
public class asd {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		if(n%2==1) {
			String s[][]=new String[n][n];
			StringBuilder sb=new StringBuilder();
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					s[i][j]=" ";
				}
			}
			for(int i=0;i<n;i++) {
				s[0][i]="*";
				sb.append(s[0][i]);
			}
			sb.append("\n");
			int k=(n+1)/2;
			for(int i=1;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(i+j==k) {
						s[i][j]="*"; s[i][n-j-1]="*";
						for(int m=0;m<=n-j-1;m++) {
							sb.append(s[i][m]);
						}
						if(i!=n-1)
							sb.append("\n");
						break;
					}
				}
			}
			System.out.print(sb);
			
		}else {
			System.out.println("I LOVE CBNU");
		}
	}

}
