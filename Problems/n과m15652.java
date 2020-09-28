import java.util.*;
public class n과m15652 {
	static int d[];
	static int n,m;
	static StringBuilder sb;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		m=sc.nextInt();
		sb=new StringBuilder();
		d=new int[m];
		dfs(0);
		System.out.print(sb);
	}
	static void dfs(int cnt) {
		if(cnt==m) {
			for(int i=0;i<m-1;i++) {
				sb.append(d[i]+" ");
			}
			sb.append(d[m-1]+"\n");
		}else {
			for(int i=1;i<=n;i++) {
				d[cnt]=i;
				if(cnt>0&&d[cnt]<d[cnt-1]) {
					continue;
				}
				dfs(cnt+1);
			}
		}
	}
}
