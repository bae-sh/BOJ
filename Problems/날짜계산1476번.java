package 백준;
import java.util.*;
public class 날짜계산1476번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int dp[]=new int[7981];
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		int cnt=0;
		for(int i=a;i<=7980;i=cnt*15+a) {
			dp[i]=1;
			cnt++;
		}
		cnt=0;
		for(int i=b;i<=7980;i=cnt*28+b) {
			if(dp[i]==1) {
				dp[i]=2;
				
			}
			cnt++;
		}cnt=0;
		for(int i=c;i<=7980;i=cnt*19+c) {
			if(dp[i]==2&&i!=0) {
				System.out.println(i);
				break;
			}
			cnt++;
		}
	}

}
