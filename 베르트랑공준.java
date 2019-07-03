import java.util.*;
public class 베르트랑공준 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		boolean b[]=new boolean[250000];
		for(int i=2;i<=500;i++) {
			if(b[i]==false) {
				for(int j=i*i;j<250000;j+=i) {
					b[j]=true;
				}
			}
		}
		while(true) {
			int n=sc.nextInt();
			if(n==0)
				break;
			else {
				int ans=0;
				for(int i=n+1;i<=n*2;i++) {
					if(b[i]==false) {
						ans++;
					}
				}
				System.out.println(ans);
			}
		}
	}

}
