import java.util.*;

public class 의배수 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int cnt=0;
		for(int i=3;i<=3000;i+=3) {
			for(int j=3;j<=3000;j+=3) {
				int k= n-i-j;
				if(k>0&&k%3==0) {
					cnt++;
				}
			}
		}
		System.out.println(cnt);
		
	}

}
