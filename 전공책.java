import java.util.*;
public class 전공책 {
	static int ans=100000000;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String t=sc.nextLine();
		int an[]=new int[27];
		for(int i=0;i<t.length();i++) {
			an[t.charAt(i)-'A'+1]++;
		}
		int n=sc.nextInt();
		int d[][]=new int[n][27];
		for(int i=0;i<n;i++) {
			d[i][0]=sc.nextInt();
			String s=sc.next();
			for(int j=0;j<s.length();j++) {
				d[i][(int)(s.charAt(j)-'A'+1)]++;
			}
		}
		int temp[]=new int[27];
		go(d,an,temp,n-1,0);
		if(ans==100000000) {
			System.out.println(-1);
		}else {
			System.out.println(ans);
		}
	}
	static void go(int d[][],int an[],int temp[],int n,int index) {
		if(index>n) {
			for(int i=1;i<=26;i++) {
				if(temp[i]<an[i]) {
					return;
				}
			}
			ans=Math.min(ans, temp[0]);
		}else {
			int t[]=new int[27];
			System.arraycopy(temp, 0, t, 0, 27);
			go(d,an,t,n,index+1);
			for(int i=0;i<27;i++) {
				t[i]+=d[index][i];
			}
			go(d,an,t,n,index+1);
		}
	}
}
