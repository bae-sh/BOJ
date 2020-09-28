import java.util.*;
public class 분해합 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int ans=0;
		for(int i=n;i>=0;i--) {
			int t=i;
			String s=Integer.toString(i);
			for(int j=0;j<s.length();j++) {
				t+=Integer.parseInt(s.charAt(j)+"");
			}
			if(t==n) {
				ans=i;
			}
		}
		System.out.println(ans);
	}

}
