import java.util.*;
public class n과m15651 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		StringBuilder sb=new StringBuilder();
		int n=sc.nextInt();
		int m=sc.nextInt();
		int d[]=new int[m];
		m--;
		for(int i=0;i<=m;i++) {
			d[i]=1;
		}
		while(d[0]<=n) {
			for(int i=0;i<m;i++) {
				sb.append(d[i]+" ");
			}
			sb.append(d[m]+"\n");
			d[m]++;
			for(int i=m;i>=0;i--) {
				if(d[i]>n&&i!=0) {
					d[i-1]++;
					d[i]=1;
				}
			}
		}
		System.out.println(sb);
	}
}
