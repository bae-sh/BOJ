import java.util.*;
public class 네번째점3009 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a[]=new int[1001];
		int b[]=new int[1001];
		
		int ans_a=0; int ans_b=0;
		for(int i=0;i<3;i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			a[x]++; b[y]++;
		}
		for(int i=1;i<1001;i++) {
			if(a[i]==1) {
				ans_a=i;
			}
			if(b[i]==1) {
				ans_b=i;
			}
		}
		System.out.println(ans_a+" "+ans_b);
		
		
	}

}
