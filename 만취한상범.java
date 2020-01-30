import java.util.*;
public class 만취한상범 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0) {
			int n=sc.nextInt();
			int ans=0;
			int p[]=new int[n+1];//0이 열려있고 1이 닫혀있고
			for(int i=2;i<=n;i++) {
				for(int j=i;j<=n;j+=i) {
					p[j]= p[j]==1 ? 0:1 ;
				}
			}
			for(int i=1;i<=n;i++) {
				if(p[i]==0)
					ans++;
			}
			System.out.println(ans);
		}
	}

}
