import java.util.*;
public class 수복원하기 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		boolean b[]=new boolean[100001];
		for(int i=2;i<=400;i++) {
			if(b[i]==false) {
				for(int j=i*i;j<100001;j+=i) {
					b[j]=true;
				}
			}
		}
		while(n-->0) {
			int k=sc.nextInt();
			int a[]=new int[100001];
			for(int i=2;i<=100000;i++) {
				if(!b[i]) {
					while(true) {
						if(k%i==0) {
							k/=i;
							a[i]++;
						}else
							break;
					}
				}
			}
			for(int i=2;i<=100000;i++) {
				if(a[i]!=0) {
					System.out.println(i+" "+a[i]);
				}
			}
		}
	}

}
