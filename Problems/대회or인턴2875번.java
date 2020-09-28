import java.util.*;
public class 대회or인턴2875번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int k=sc.nextInt();
		int ans=0;
		for(int i=0;i<100;i++){
			if(n+m-3>=k&&n>=2&&m>=1) {
				n-=2;m--;
				ans++;
			}
			else {
				break;
			}
		}
		System.out.println(ans);
	}

}
