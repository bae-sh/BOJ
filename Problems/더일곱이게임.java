import java.util.Scanner;

public class 더일곱이게임 {
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0) {
			long n=sc.nextLong();
			int ans=0;
			while(true) {
				if(n==1) {
					break;
				}
				if(n%2==0) {
					n/=2;
					ans++;
				}else {
					n--;
					ans++;
				}
			
			}
			if(ans%2!=0) {
				System.out.println("cubelover");
			}else {
				System.out.println("koosaga");
			}
		}
	}
}
//홀수면 쿠사가 이김 큐브 출력