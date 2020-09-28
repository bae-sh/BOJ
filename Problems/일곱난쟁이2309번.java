package 백준;
import java.util.*;
public class 일곱난쟁이2309번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int d[]=new int[9];
		int dp[]=new int[9];
		int a=0;
		for(int i=0;i<9;i++) {
			d[i]=sc.nextInt();
			a+=d[i];
		}
		Arrays.sort(d);
		int ans=a;
		for(int i=0;i<=8;i++) {
			for(int j=i;j<9;j++) {
				ans-=d[i];
				ans-=d[j];
				if(ans==100) {
					dp[i]=1;
					dp[j]=1;
					for(int k=0;k<9;k++) {
						if(dp[k]==0) {
							System.out.println(d[k]);
						}
					}
					System.exit(0);
				}
				ans=a;
			}
		}
	}

}
