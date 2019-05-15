import java.util.*;
public class 숫자조각 {
	static long ans=0;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		long m=sc.nextLong();
		if(m>=9876543210L) {
			System.out.println("9876543210");
		}else {
			boolean b[]=new boolean[10];
			go(0,b,m);
			System.out.println(ans);
		}
	}
	public static void go(long num,boolean b[],long m) {
			for(int i=0;i<10;i++) {
				if(b[i]==false) {
					long temp=num;
					num=num*10+i;
					if(Math.abs(num-m)<=Math.abs(ans-m)) {
						if(Math.abs(num-m)==Math.abs(ans-m)) {
							ans=Math.min(num, ans);
						}else {
							ans=num;
						}
					}
					b[i]=true;
					go(num,b,m);
					b[i]=false;
					num=temp;
				}
			}
		
	}
}
