import java.util.*;
public class 수열의합 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int l=sc.nextInt();
		
		for(int i=l;i<101;i++) {
			int k=n;
			for(int j=0;j<i;j++) {
				k-=j;
			}
			if(k>=0&&k%i==0) {
				k/=i;
				for(int j=0;j<i;j++) {
					System.out.print(k+" ");
					k++;
				}
				return ;
			}
		}
		System.out.println(-1);
	}

}
