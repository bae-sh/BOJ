import java.util.*;
public class 부분집합의합1182 {
	static int ans=0;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int s=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		if(s==0) {
			ans=-1;
		}
		go(a,0 ,s,0);
		System.out.println(ans);
	}
	static void go(int a[],int index,int s,int num) {
		if(index==a.length) {
			if(num==s)
				ans++;
			return;
		}
		go(a,index+1,s,num+a[index]);
		go(a,index+1,s,num);
		
	}
}
