import java.util.*;
public class 연산자끼워넣기14888 {
	static int Max=-1000000000;
	static int Min=1000000000;
	static int n;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		int operator[]=new int[4];
		for(int i=0;i<4;i++) {
			operator[i]=sc.nextInt();
		}
		oper(a[0],operator,a,1);
		System.out.println(Max);
		System.out.println(Min);
		
	}
	static void oper(int front,int operator[],int a[],int cnt) {
		if(operator[0]>0) {
			int _front=front+a[cnt];
			operator[0]--;
			oper(_front,operator,a,cnt+1);
			operator[0]++;
		}
		if(operator[1]>0) {
			int _front=front-a[cnt];
			operator[1]--;
			oper(_front,operator,a,cnt+1);
			operator[1]++;
		}
		if(operator[2]>0) {
			int _front=front*a[cnt];
			operator[2]--;
			oper(_front,operator,a,cnt+1);
			operator[2]++;
		}
		if(operator[3]>0) {
			int _front=front/a[cnt];
			operator[3]--;
			oper(_front,operator,a,cnt+1);
			operator[3]++;
		}
		if(cnt==n) {
			Max=Math.max(Max, front);
			Min=Math.min(Min, front);
		}
	}
}
